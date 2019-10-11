#include "pch.h"
#include "playerBall.h"


playerBall::playerBall(std::string tileMapPath, std::string idBall) : ball(tileMapPath, idBall)
{
	
}


playerBall::~playerBall()
{
}

void playerBall::DrawLine(sf::Vector2i _position)
{
	sf::RectangleShape line(sf::Vector2f(50, 5));
	line.setPosition(20, 20);
	_windowBall->draw(line);
}

void playerBall::DrawBall(Spritesheet* spriteSheet)
{
	_windowBall->clear();
	DrawLine(GetMousePos());
	_tileMap->DrawTileMap(spriteSheet, _windowBall);
	_windowBall->display();
}

sf::Vector2i playerBall::GetMousePos()
{
	// get global mouse position
	sf::Vector2i mousePos = sf::Mouse::getPosition();
	return mousePos;
}
