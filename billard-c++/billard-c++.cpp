#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>

#define WINDOWS_WIDTH 1920
#define WINDOWS_HEIGHT 1080
#define FRAMERATE 60

int main()
{

	sf::RenderWindow window(sf::VideoMode(WINDOWS_WIDTH, WINDOWS_HEIGHT), "Billard C++");
    std::cout << "Hello World!\n"; 

	sf::Event event;
	sf::Clock clock;
	float frameDelay = 1.f / FRAMERATE;//sec
	float deltaTime = 0;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

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
