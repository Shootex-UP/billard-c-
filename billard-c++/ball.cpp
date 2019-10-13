#include "pch.h"
#include "ball.h"

#define PHYSICS_FRICTION 0.05f

ball::ball(std::string tileMapPath, std::string idBall): _idBall(idBall)
{
	_windowBall = new sf::RenderWindow(sf::VideoMode(_winWidth, _winHeight), _idBall, sf::Style::None);
	_tileMap = new Tilemap(tileMapPath, 5, 5, 16, 16);
	_position = sf::Vector2f(1920 / 2, 1080 / 2);
}


ball::~ball()
{
	//
	//delete _tileMap;
}

void ball::DrawBall(Spritesheet* spriteSheet)
{
	_windowBall->clear();
	_tileMap->DrawTileMap(spriteSheet, _windowBall);
	_windowBall->display();
}

void ball::UpdateWindow()
{
	_windowBall->setPosition((sf::Vector2i)(_position - sf::Vector2f(_radius, _radius)));
}

void ball::SetPos(sf::Vector2f initPos)
{
	_position = initPos;
}

void ball::SetVel(sf::Vector2f initVel)
{
	_velocity = initVel;
}

void ball::updatePosition(sf::FloatRect ScreenSpace, float deltatime) {
	sf::Vector2f nexPos((_position.x + (_velocity.x * deltatime)), (_position.y + (_velocity.y * deltatime)));
	if ((nexPos.x  < 0 || nexPos.x  > ScreenSpace.width) || (nexPos.y  < 0 || nexPos.y > ScreenSpace.height)) {
		if (nexPos.x  < 0 || nexPos.x  > ScreenSpace.width) {
			_velocity.x *= -1;
		}
		else if (nexPos.y < 0 || nexPos.y  > ScreenSpace.height) {
			_velocity.y *= -1;
		}
		else {
			printf("error\n");
		}
	}
	_position = _position + (_velocity * deltatime);
	_velocity *= 1 - PHYSICS_FRICTION;

	if (_velocity.x < 3.f && _velocity.y < 3.f)
		canShoot = true;
	else
		canShoot = false;
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

//Source http://www.vobarian.com/collisions/2dcollisions2.pdf
void ball::resolveCollision(ball* ball)
{
	// Compute unit normal and unit tangent vectors
	sf::Vector2f v_n(ball->_position - _position); // vector normal to the collision surface

	sf::Vector2f v_un(0,0);// unit normal vector
	double mag = std::sqrt(v_n.x * v_n.x + v_n.y * v_n.y);//magnitude
	if (mag != 0.)
		v_un = sf::Vector2f(v_n.x / mag, v_n.y / mag);

	sf::Vector2f v_ut(-v_un.y, v_un.x); // unit tangent vector

	// Compute scalar projections of velocities onto v_un and v_ut
	double v1n = (v_un.x * _velocity.x + v_un.y * _velocity.y);// Dot product
	double v1t = (v_ut.x * _velocity.x + v_ut.y * _velocity.y);
	double v2n = (v_un.x * ball->_velocity.x + v_un.y * ball->_velocity.y);
	double v2t = (v_ut.x * ball->_velocity.x + v_ut.y * ball->_velocity.y);

	// Compute new tangential velocities
	double v1tPrime = v1t; // Note: in reality, the tangential velocities do not change after the collision
	double v2tPrime = v2t;

	// Compute new normal velocities using one-dimensional elastic collision equations in the normal direction
	// Division by zero avoided. See early return above.
	double v1nPrime = (v1n * (_mass - ball->_mass) + 2. * ball->_mass * v2n) / (_mass + ball->_mass);
	double v2nPrime = (v2n * (ball->_mass - _mass) + 2. * _mass * v1n) / (_mass + ball->_mass);

	// Compute new normal and tangential velocity vectors
	sf::Vector2f v_v1nPrime(v1nPrime * v_un.x, v1nPrime * v_un.y);// Multiplication by a scalar
	sf::Vector2f v_v1tPrime(v1tPrime * v_ut.x, v1tPrime * v_ut.y);
	sf::Vector2f v_v2nPrime(v2nPrime * v_un.x, v2nPrime * v_un.y);
	sf::Vector2f v_v2tPrime(v2tPrime * v_ut.x, v2tPrime * v_ut.y);

	// Set new velocities in x and y coordinates
	_velocity = v_v1nPrime + v_v1tPrime;
	ball->_velocity = v_v2nPrime + v_v2tPrime;
}


