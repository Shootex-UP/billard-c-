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

	sf::Vector2f _position;
	sf::Vector2f _velocity;
	float _radius = 48;
	float _mass = 1;

	Tilemap* _tileMap;
	sf::RenderWindow* _windowBall;


	ball();
	ball(std::string tileMapPath , std::string idBall);
	~ball();

	void DrawBall(Spritesheet* spriteSheet);
	bool colliding(ball ball);
	void resolveCollision(ball* ball);
};

