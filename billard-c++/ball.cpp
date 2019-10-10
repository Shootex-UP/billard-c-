#include "pch.h"
#include "ball.h"

ball::ball() {

}

ball::ball(std::string tileMapPath, std::string idBall): _idBall(idBall)
{
	_windowBall = new sf::RenderWindow(sf::VideoMode(_winWidth, _winHeight), _idBall, sf::Style::None);
	_tileMap = new Tilemap(tileMapPath, 48, 24, 16, 16);
}


ball::~ball()
{
}

void ball::DrawBall(Spritesheet* spritesheet)
{
	_windowBall->clear();
	_tileMap->DrawTileMap(spritesheet);
	_windowBall->display();
}


bool ball::colliding(ball ball) {
	return false;
}

void ball::resolveCollision(ball* ball) {

}
