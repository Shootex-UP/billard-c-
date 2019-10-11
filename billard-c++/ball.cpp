#include "pch.h"
#include "ball.h"

ball::ball() {

}

ball::ball(std::string tileMapPath, std::string idBall): _idBall(idBall)
{
	_windowBall = new sf::RenderWindow(sf::VideoMode(_winWidth, _winHeight), _idBall, sf::Style::None);
	_tileMap = new Tilemap(tileMapPath, 5, 5, 16, 16);
}


ball::~ball()
{
}

void ball::DrawBall(Spritesheet* spritesheet)
{
	_windowBall->clear();
	_tileMap->DrawTileMap(spritesheet, _windowBall);
	_windowBall->display();
}

void ball::UpdateWindow()
{
	_windowBall->setPosition((sf::Vector2i)(_position - sf::Vector2f(_radius, _radius)));
}

void ball::updatePosition(sf::FloatRect ScreenSpace, float deltatime) {
	if (!ScreenSpace.intersects(sf::FloatRect(_position.x + (_velocity.x * deltatime) , _position.y + (_velocity.y * deltatime), _radius, _radius))) {
		if (_position.x - _radius < 0 || _position.x + _radius > ScreenSpace.width) {
			_velocity.x *= -1;
		}
		else if (_position.y - _radius < 0 || _position.y + _radius > ScreenSpace.height) {
			_velocity.y *= -1;
		}
		else {
			printf("error\n");
		}
	}
	_position = _position + (_velocity * deltatime);
}

bool ball::colliding(ball ball) {
	float xd = _position.x - ball._position.x;
	float yd = _position.y - ball._position.y;

	float sumRadius = _radius + ball._radius;
	float sqrRadius = sumRadius * sumRadius;

	float distSqr = (xd * xd) + (yd * yd);

	if (distSqr <= sqrRadius)
	{
		return true;
	}

	return false;
}

void ball::resolveCollision(ball* ball)
{
	// get the mtd
	sf::Vector2f delta = _position - ball->_position;
	//float d = delta.getLength();
	float d = sqrt((delta.x * delta.x) + (delta.y * delta.y));
	// minimum translation distance to push balls apart after intersecting
	float scalar = ((_radius + ball->_radius) - d) / d;
	sf::Vector2f mtd = delta * scalar;

	// resolve intersection --
	// inverse mass quantities
	float im1 = 1 / _mass;
	float im2 = 1 / ball->_mass;

	// push-pull them apart based off their mass
	_position = _position + mtd * (im1 / (im1 + im2));
	ball->_position = ball->_position - mtd * (im2 / (im1 + im2));

	// impact speed
	sf::Vector2f v = _velocity - ball->_velocity;
	float magnitude = sqrt((mtd.x * mtd.x) + (mtd.y * mtd.y));
	sf::Vector2f normalize = sf::Vector2f(mtd.x / magnitude, mtd.y / magnitude);
	//float vn = v.dot(normalize);
	float vn = ((v.x * normalize.x) + (v.y * normalize.y));

	// sphere intersecting but moving away from each other already
	if (vn > 0.0f) return;

	// collision impulse
	float i = (-(1.0f + 0.85f) * vn) / (im1 + im2);
	sf::Vector2f impulse = mtd * i;

	// change in momentum
	_velocity = _velocity + (impulse * im1);
	ball->_velocity = ball->_velocity - (impulse * im2);

}
