#pragma once
#include <string>
#include "SpriteSheet.h"
#include <fstream>
class Tilemap
{
private:
	int _mapWidth;
	int _mapHeight;
	int _tileWidth;
	int _tileHeight;
	std::string _tileMapPath;
	unsigned long** _mapData;
	const unsigned _FLIPPED_HORIZONTALLY_FLAG = 0x80000000;
	const unsigned _FLIPPED_VERTICALLY_FLAG = 0x40000000;
	const unsigned _FLIPPED_DIAGONALLY_FLAG = 0x20000000;

public:
	Tilemap(std::string tileMapPath, int mapWidth, int mapHeight, int tileWidth, int tileHeight);
	~Tilemap();
	void DrawTileMap(Spritesheet*, sf::RenderWindow* targetWindow);
};

