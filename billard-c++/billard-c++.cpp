#include "pch.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <list> 
#include "SpriteSheet.h"
#include "TileMap.h"
#include "GameManager.h"
#include "playerBall.h"


#define WINDOWS_WIDTH 1920
#define WINDOWS_HEIGHT 1080
#define FRAMERATE 60
#define PHYSICS_DELTATIME 120

#define WINDOWS_TEST_WIDTH 100
#define WINDOWS_TEST_HEIGHT 100

std::string GetExePath() {
	char cExeFilePath[256];
	GetModuleFileNameA(NULL, cExeFilePath, 256);
	std::string exeFilePath = cExeFilePath;
	int exeNamePos = exeFilePath.find_last_of("\\/");
	std::string exePath = exeFilePath.substr(0, exeNamePos + 1);
	return exePath;
}

int main()
{
	std::map<std::string, std::string> mapPath;

	mapPath["0"] = GetExePath() + "Assets/sample_bool_white.csv";

	mapPath["1"] = GetExePath() + "Assets/sample_bool_1.csv";
	mapPath["2"] = GetExePath() + "Assets/sample_bool_2.csv";
	mapPath["3"] = GetExePath() + "Assets/sample_bool_3.csv";
	mapPath["4"] = GetExePath() + "Assets/sample_bool_4.csv";
	mapPath["5"] = GetExePath() + "Assets/sample_bool_5.csv";
	mapPath["6"] = GetExePath() + "Assets/sample_bool_6.csv";

	sf::RenderWindow window(sf::VideoMode(WINDOWS_WIDTH, WINDOWS_HEIGHT), "Billard C++", sf::Style::None);
	sf::RenderWindow* windowP;
	windowP = &window;
	std::cout << "Hello World!\n";

	//Init Spritesheet
	std::string spriteSheetPath = GetExePath() + "Assets/colored.png";
	Spritesheet mainSpritesheet(spriteSheetPath, 1, 16, 32);	// Dans la pile

	//Init GameManager
	GameManager* gameManager = new GameManager(1.f / FRAMERATE, 1.f / PHYSICS_DELTATIME, spriteSheetPath);
	gameManager->InitWindows(mapPath);

	//Init WinPos
	gameManager->InitBallPos();
	//gameManager->InitBallVel();

	//Load Tilemap Billard
	std::string tileMapPath = GetExePath() + "Assets/sample_pool2.csv";
	Tilemap mainTilemap(tileMapPath, 120, 67, 16, 16);

	sf::Event event;
	sf::Clock clock;
	float frameDelay = 1.f / FRAMERATE;//sec
	float deltaTime = 0;
	while (window.isOpen())
	{
		deltaTime = clock.getElapsedTime().asSeconds();
		if (deltaTime >= frameDelay) {
			//std::cout << deltaTime << "sec" << std::endl;
			window.clear();
			//draw
			mainTilemap.DrawTileMap(&mainSpritesheet, windowP);

			gameManager->DrawAllBalls();

			clock.restart();
			window.display();
		}
		gameManager->WindowsUpdate();
		gameManager->PhysicsUpdate();

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					gameManager->player->Shoot();
					std::cout << "SHHOOOOOOOOOOOOOT" << std::endl;
				}
			}
		}
	}
	return 0;
}
