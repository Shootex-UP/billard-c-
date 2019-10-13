#pragma once
#include "ball.h"

class playerBall : public ball
{
public:
	playerBall(std::string tileMapPath, std::string idBall);
	~playerBall();
	void DrawLine(sf::Vector2i _position);
	void DrawBall(Spritesheet* spriteSheet) override;
	sf::Vector2i GetMousePos();
	std::string _idBall;

	void Shoot();
};

