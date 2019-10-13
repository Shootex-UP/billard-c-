#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <list>
#include "ball.h"
#include "playerBall.h"
class GameManager
{
private:
	bool _exitFlag = false;
	sf::Clock _clock;
	sf::Clock _physicsClock;
	float _timeScale = 1.f;
	float _framerate = 0;
	float _physicsDeltatime = 0;
	sf::Event _event;
	ball** _balls;
	int _ballCount = 7;
	Spritesheet* _spritesheet;
	sf::FloatRect holes[6] = {
		sf::FloatRect(0, 0, 80, 80),//LeftTop
		sf::FloatRect(1920 / 2 - 20, 0, 40, 40),//MiddleTop
		sf::FloatRect(1920 - 80, 0, 40, 40),//RightTop
		sf::FloatRect(1920 - 80, 1080 - 80, 40, 40),//RightTop
		sf::FloatRect(1920 / 2 - 20, 1080-80, 40, 40),//RightTop
		sf::FloatRect(0, 1080 - 80, 40, 40)//RightTop
	};

public:
	sf::FloatRect _screenSpace = sf::FloatRect(0, 0, 1920, 1080);
	GameManager(float framerate, float physicsDeltatime, std::string spriteSheetPath);
	~GameManager();
	void WindowsUpdate();
	void PhysicsUpdate();
	void InputUpdate();
	bool GetExitFlag();
	void InitWindows(std::map<std::string, std::string> TileMapPathMap);
	void InitBallPos();
	void InitBallVel();
	void DrawAllBalls();
	playerBall* player;
};

