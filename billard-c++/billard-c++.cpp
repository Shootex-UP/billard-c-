#include "pch.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <fstream>


#define WINDOWS_WIDTH 1080
#define WINDOWS_HEIGHT 920
#define FRAMERATE 60

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
    std::cout << "Hello World!\n"; 

	std::string spriteSheetPath = GetExePath() + "Assets/colored.png";

	//Load Tilemap Billard
	std::string tileMapPath = GetExePath() + "Assets/sample_fantasy.csv";

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
			window.display();
			clock.restart();
		}

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
	return 0;
}
