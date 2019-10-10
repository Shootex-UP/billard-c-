#include "pch.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <fstream>
#include "SpriteSheet.h"
#include "TileMap.h"
#include "GameManager.h"
#include "playerBall.h"


#define WINDOWS_WIDTH 960
#define WINDOWS_HEIGHT 540
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

	sf::RenderWindow window(sf::VideoMode(WINDOWS_WIDTH, WINDOWS_HEIGHT), "Billard C++", sf::Style::None);
	sf::RenderWindow* windowP;
	windowP = &window;
	std::cout << "Hello World!\n";
	//window.setPosition(sf::Vector2i(960,540)); //Set la position de la window

	GameManager* gameManager = new GameManager(1.f / FRAMERATE, 1.f / PHYSICS_DELTATIME);
	//Load Spritesheet
	std::string spriteSheetPath = GetExePath() + "Assets/colored.png";
	Spritesheet mainSpritesheet(windowP, spriteSheetPath, 1, 16, 32);	// Dans la pile

	//Load Tilemap Billard
	std::string tileMapPath = GetExePath() + "Assets/sample_pool2.csv";
	Tilemap mainTilemap(tileMapPath, 120, 67, 16, 16);

	//Load Player Ball
	std::string playerBallPath = GetExePath() + "Assets/sample_bool_white.csv";
	//playerBall mainplayerBall(playerBallPath,"0");

	//Load Ball
	//ball mainball(playerBallPath, "1");

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
			mainTilemap.DrawTileMap(&mainSpritesheet);
			clock.restart();
			window.display();
		}
		//gameManager->WindowsUpdate();
		//gameManager->PhysicsUpdate();

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
				window.close();
		}
	}
	return 0;
}
