#pragma once
#include "Spritesheet.h"
#include "TileMap.h"
#include <string>
#include <SFML/Graphics.hpp>


class ball
{
public:
	float _winHeight;//static
	float _winWidth;//static

	std::string _idBall;

	float _winPosX;
	float _winPosY;

	Tilemap* _tileMap;
	sf::RenderWindow* _windowBall;


	ball();
	ball(std::string tileMapPath , std::string idBall);
	~ball();

	void DrawBall(Spritesheet* spriteSheet);
	bool colliding(ball ball);
	void resolveCollision(ball* ball);
};

