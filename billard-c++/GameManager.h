#pragma once
#include <SFML/Graphics.hpp>
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
	ball* balls;
	int ballCount = 7;
public:
	GameManager(float framerate, float physicsDeltatime);
	~GameManager();
	void WindowsUpdate();
	void PhysicsUpdate();
	void InputUpdate();
	bool GetExitFlag();
};

