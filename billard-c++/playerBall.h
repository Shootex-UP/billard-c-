#pragma once
#include "ball.h"

class playerBall : public ball
{
public:
	playerBall(std::string tileMapPath, std::string idBall);
	~playerBall();
	std::string _idBall;
};

