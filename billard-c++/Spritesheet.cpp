#include "pch.h"
#include "Spritesheet.h"


Spritesheet::Spritesheet(std::string texturePath, int gridOffset, int gridCellSize, int gridNbCellsX) :
	_texturePath(texturePath), _gridOffset(gridOffset), _gridCellSize(gridCellSize), _gridNbCellsX(gridNbCellsX)
{
	_texture.loadFromFile(texturePath);
}

Spritesheet::~Spritesheet()
{
}

void Spritesheet::DrawSprite(int spriteIndex, int x, int y, bool flipH, bool flipV, bool flipD, sf::RenderWindow* targetWindow)
{
	int spriteGridX = spriteIndex % _gridNbCellsX;
	int spriteGridY = floor(spriteIndex / _gridNbCellsX);

	sf::IntRect srcRect(spriteGridX * (_gridCellSize + _gridOffset), spriteGridY * (_gridCellSize + _gridOffset), _gridCellSize, _gridCellSize);
	_sprite.setTexture(_texture);
	_sprite.setTextureRect(srcRect);
	_sprite.setScale(1, 1);
	_sprite.setPosition(sf::Vector2f(x + _gridCellSize / 2, y + _gridCellSize / 2));
	_sprite.setOrigin(sf::Vector2f(_gridCellSize / 2, _gridCellSize / 2));


	int angle = 0;

	if (flipD) {
		if (flipH) {
			angle = 90;
		}
		if (flipV) {
			angle = -90;
		}
	}
	else {
		if (flipH) {
			_sprite.scale(-1, 1);
		}
		if (flipV) {
			_sprite.scale(1, -1);
		}
	}
	_sprite.setRotation(angle);


	(*targetWindow).draw(_sprite);
}
