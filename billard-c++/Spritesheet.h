#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Spritesheet
{
private:
	std::string _texturePath;
	int _gridOffset = 0;
	int _gridCellSize = 0;
	int _gridNbCellsX = 0;

	sf::RenderWindow* _renderer;
	sf::Texture _texture;
	sf::Sprite _sprite;

public:
	Spritesheet(std::string texturePath, int gridOffset, int gridCellSize, int gridNbCellsX);
	~Spritesheet();
	void DrawSprite(int spriteIndex, int x, int y, bool flipH, bool flipV, bool flipD, sf::RenderWindow* targetWindow);
};

