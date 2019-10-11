#include "pch.h"
#include "GameManager.h"
#include <iostream>
#include <iterator>


GameManager::GameManager(float framerate, float physicsDeltatime, std::string spriteSheetPath) : _framerate(framerate), _physicsDeltatime(physicsDeltatime)
{
	_clock = sf::Clock();
	_physicsClock = sf::Clock();
	_balls = new ball*[_ballCount];
	_spritesheet = new Spritesheet(spriteSheetPath, 1, 16, 32);
}


GameManager::~GameManager()
{
}

void GameManager::WindowsUpdate()
{
	float deltaTime = _clock.getElapsedTime().asSeconds();
	if (deltaTime >= _framerate) {
		//std::cout << "Window update " << deltaTime << std::endl;
		for (int i = 0; i < _ballCount; i++) {
			_balls[i]->UpdateWindow();
		}
		_clock.restart();
	}
}

void GameManager::PhysicsUpdate()
{
	float deltaTime = _physicsClock.getElapsedTime().asSeconds();
	if (deltaTime >= _physicsDeltatime) {
		//std::cout << "Physics update" << deltaTime <<  std::endl;
		//speed
		for (int i = 0; i < _ballCount; i++) {
			_balls[i]->updatePosition(_screenSpace, _physicsDeltatime * _timeScale);
		}
		//check collision
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

void GameManager::InitBallPos()
{
	_balls[0]->SetPos(sf::Vector2f(200, 540));

	_balls[1]->SetPos(sf::Vector2f(1200, 540));
	_balls[2]->SetPos(sf::Vector2f(1400, 440));
	_balls[3]->SetPos(sf::Vector2f(1400, 640));
	_balls[4]->SetPos(sf::Vector2f(1600, 340));
	_balls[5]->SetPos(sf::Vector2f(1600, 540));
	_balls[6]->SetPos(sf::Vector2f(1600, 740));
}

void GameManager::InitBallVel()
{
	_balls[0]->SetVel(sf::Vector2f(-700,-700));
}

void GameManager::DrawAllBalls()
{
	for (int i = 0; i < _ballCount; i++)
	{
		_balls[i]->DrawBall(_spritesheet);
	}
}
