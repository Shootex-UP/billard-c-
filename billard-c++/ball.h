#pragma once
#include "Spritesheet.h"
#include "TileMap.h"
#include <string>
#include <SFML/Graphics.hpp>


class ball
{
public:
	int _winHeight = 80;//static
	int _winWidth = 80;//static

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

	virtual void DrawBall(Spritesheet* spriteSheet);
	void UpdateWindow();
	void SetPos(sf::Vector2f initPos);
	//Physics
	void updatePosition(sf::FloatRect ScreenSpace, float deltatime);
	bool colliding(ball ball);
	void resolveCollision(ball* ball);
};

