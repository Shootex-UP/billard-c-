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
	float _radius = 40;
	float _mass = 10;

	bool canShoot = false;

	Tilemap* _tileMap;
	sf::RenderWindow* _windowBall;

	ball(std::string tileMapPath , std::string idBall);
	~ball();

	virtual void DrawBall(Spritesheet* spriteSheet);

	void UpdateWindow();
	void SetPos(sf::Vector2f initPos);
	void SetVel(sf::Vector2f initVel);
	//Physics
	void updatePosition(sf::FloatRect ScreenSpace, float deltatime);
	bool colliding(ball ball);
	void resolveCollision(ball* ball);
};

