#include "pch.h"
#include "GameManager.h"
#include <iostream>
#include <iterator>


GameManager::GameManager(float framerate, float physicsDeltatime) : _framerate(framerate), _physicsDeltatime(physicsDeltatime)
{
	_clock = sf::Clock();
	_physicsClock = sf::Clock();
	_balls = new ball*[_ballCount];
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
		for (int i = 0; i < _ballCount; i++)
		{
			for (int j = i + 1; j < _ballCount; j++)
			{
				if (_balls[i]->colliding((*_balls[j])))
				{
					_balls[i]->resolveCollision(_balls[j]);
				}
			}
		}
		_physicsClock.restart();
	}
}

void GameManager::InputUpdate()
{
	sf::Event event;
	while (_balls[0]->_windowBall->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			_balls[0]->_windowBall->close();
	}
}

bool GameManager::GetExitFlag()
{
	return _exitFlag;
}

void GameManager::InitWindows(std::map<std::string, std::string> tileMapPathMap)
{
	std::map<std::string, std::string>::iterator current = tileMapPathMap.begin();
	int i = 0;
	while (current != tileMapPathMap.end())
	{
		_balls[i] = new ball((*current).second, (*current).first);
		i++;
		current++;
	}
}
