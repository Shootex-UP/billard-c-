#include "pch.h"
#include "GameManager.h"
#include <iostream>


GameManager::GameManager(float framerate, float physicsDeltatime) : _framerate(framerate), _physicsDeltatime(physicsDeltatime)
{
	_clock = sf::Clock();
	_physicsClock = sf::Clock();
}


GameManager::~GameManager()
{
}

void GameManager::WindowsUpdate()
{
	float deltaTime = _clock.getElapsedTime().asSeconds();
	if (deltaTime >= _framerate) {
		std::cout << "Window update " << deltaTime << std::endl;
		_clock.restart();
	}
}

void GameManager::PhysicsUpdate()
{
	float deltaTime = _physicsClock.getElapsedTime().asSeconds();
	if (deltaTime >= _physicsDeltatime) {
		std::cout << "Physics update" << deltaTime <<  std::endl;
		_physicsClock.restart();
	}
}

void GameManager::InputUpdate()
{
	while (ball[0]GetWindow()->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

bool GameManager::GetExitFlag()
{
	return _exitFlag;
}
