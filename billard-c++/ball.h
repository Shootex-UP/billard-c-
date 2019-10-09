#pragma once
#include "Spritesheet.h"
#include "TileMap.h"
#include <string>
#include <SFML/Graphics.hpp>


class ball
{
	static Spritesheet _mainSpriteSheet;
	static float _winHeight;
	static float _winwidth;

	std::string _idBall;

	float _winPosX;
	float _winPosY;

	Tilemap* _tileMap;
	sf::RenderWindow* _windowBall;


public:
	ball(std::string tileMapPath , std::string idBall);
	~ball();

	void DrawBall();
};

