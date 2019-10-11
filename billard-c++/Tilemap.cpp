#include "pch.h"
#include "Tilemap.h"


Tilemap::Tilemap(std::string tileMapPath, int mapWidth, int mapHeight, int tileWidth, int tileHeight)
	: _tileMapPath(tileMapPath), _mapWidth(mapWidth), _mapHeight(mapHeight), _tileWidth(tileWidth), _tileHeight(tileHeight)
{
	int endPos = 0;
	std::ifstream tileMapStream(_tileMapPath);
	//on créé à partir de la premiere case toute la ligne puis on la remplit de 0, et on passe à la deuxieme ligne
	_mapData = new unsigned long*[_mapHeight];
	for (int i = 0; i < _mapHeight; ++i) {
		_mapData[i] = new unsigned long[_mapWidth];
		for (int j = 0; j < _mapWidth; ++j) {
			_mapData[i][j] = 0;
		}
	}

	std::string line;
	std::string strTileIndex;
	int tileX = 0;
	int tileY = 0;
	while (std::getline(tileMapStream, line)) {	//tant qu'il y a des lignes
		tileX = 0;
		while (endPos != std::string::npos) {
			endPos = line.find(",");
			strTileIndex = line.substr(0, endPos);
			if (strTileIndex.length() > 0) {
				line = line.substr(endPos + 1);
				_mapData[tileY][tileX] = std::stoul(strTileIndex);
				tileX++;
			}
			else if (endPos != std::string::npos) {
				line = line.substr(endPos + 1);
				tileX++;
			}
		}
		tileY++;
		endPos = 0;
	}
}


Tilemap::~Tilemap()
{
}

void Tilemap::DrawTileMap(Spritesheet* spriteSheet, sf::RenderWindow* targetWindow) {
	unsigned long spriteRawIndex = 0;
	unsigned long spriteIndex = 0;
	int x = 0;
	int y = 0;
	for (int i = 0; i < _mapHeight; ++i) {
		for (int j = 0; j < _mapWidth; ++j) {
			spriteRawIndex = _mapData[i][j];
			spriteIndex = spriteRawIndex & ~(_FLIPPED_HORIZONTALLY_FLAG | _FLIPPED_VERTICALLY_FLAG | _FLIPPED_DIAGONALLY_FLAG);
			spriteIndex--;
			bool flipH = (spriteRawIndex & _FLIPPED_HORIZONTALLY_FLAG) == _FLIPPED_HORIZONTALLY_FLAG;
			bool flipV = (spriteRawIndex & _FLIPPED_VERTICALLY_FLAG) == _FLIPPED_VERTICALLY_FLAG;
			bool flipD = (spriteRawIndex & _FLIPPED_DIAGONALLY_FLAG) == _FLIPPED_DIAGONALLY_FLAG;
			x = j * _tileHeight;
			y = i * _tileWidth;
			spriteSheet->DrawSprite(spriteIndex, x, y, flipH, flipV, flipD, targetWindow);
		}
	}
}