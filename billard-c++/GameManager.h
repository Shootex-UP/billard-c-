#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <list>
#include "ball.h"
class GameManager
{
private:
	bool _exitFlag = false;
	sf::Clock _clock;
	sf::Clock _physicsClock;
	float _timeScale = 1;
	float _framerate = 0;
	float _physicsDeltatime = 0;
	sf::Event _event;
	ball** _balls;
	int _ballCount = 7;
	Spritesheet* _spritesheet;

public:
	sf::FloatRect _screenSpace = sf::FloatRect(0, 0, 1920, 1080);
	GameManager(float framerate, float physicsDeltatime, std::string spriteSheetPath);
	~GameManager();
	void WindowsUpdate();
	void PhysicsUpdate();
	void InputUpdate();
	bool GetExitFlag();
	void InitWindows(std::map<std::string, std::string> TileMapPathMap);
	void DrawAllBalls();
};

