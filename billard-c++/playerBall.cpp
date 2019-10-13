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
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(40, 40)),
		sf::Vertex(sf::Vector2f(GetMousePos()))
	};

	if (_idBall == "")
		_windowBall->draw(line, 2, sf::Lines);
}

void playerBall::DrawBall(Spritesheet* spriteSheet)
{
	_windowBall->clear();
	_tileMap->DrawTileMap(spriteSheet, _windowBall);
	DrawLine(GetMousePos());
	_windowBall->display();
}

sf::Vector2i playerBall::GetMousePos()
{
	// get global mouse position
	sf::Vector2i mousePos = sf::Mouse::getPosition(*_windowBall);
	return mousePos;
}
