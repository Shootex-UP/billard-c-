#include "pch.h"
#include "ball.h"


ball::ball(std::string tileMapPath, std::string idBall): _idBall(idBall)
{
	_windowBall = new sf::RenderWindow(sf::VideoMode(_winwidth, _winHeight), _idBall, sf::Style::None);
	_tileMap = new Tilemap(tileMapPath, 48, 24, 16, 16);
}


ball::~ball()
{
}

void ball::DrawBall()
{
	_windowBall->clear();
	_tileMap->DrawTileMap(&_mainSpriteSheet);
	_windowBall->display();
}
