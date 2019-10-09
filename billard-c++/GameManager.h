#pragma once
#include <SFML/Graphics.hpp>
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
	//Ball* Balls[];
public:
	GameManager(float framerate, float physicsDeltatime);
	~GameManager();
	void WindowsUpdate();
	void PhysicsUpdate();
	void InputUpdate();
	bool GetExitFlag();
};

