#include "AssetManager.h"
#include "Color.h"
#include "SpriteManager.h"
#include "Pixel.h"
#include <iostream>
#include <sstream>
#include <vector>

Sprite* SpriteManager::load(std::string filename, const unsigned int width, const unsigned int height)
{
	return load(filename, width, height, 0, 0);
}

Sprite* SpriteManager::load(std::string filename, const unsigned int width, const unsigned int height, const unsigned int x, const unsigned int y)
{
	AssetManager& assetManager = AssetManager::getInstance();
	std::vector<std::string> file = assetManager.readfile(filename);

	Pixel** map = new Pixel*[height];
	for (unsigned int i = 0; i < height; i++)
	{
		map[i] = new Pixel[width];
		std::string line = file[i];

		for (unsigned int j = 0; j < width; j++)
		{
			int pos = j * 4;
			std::string h = line.substr(pos, 4);
			std::string v = line.substr(pos, 2);
			std::string f = line.substr(pos + 2, 1);
			std::string g = line.substr(pos + 3, 1);
			map[i][j].value = (char)std::stoul(HEX_PREFIX + line.substr(pos, 2), nullptr, 16);
			map[i][j].fgColor = std::stoul(HEX_PREFIX + line.substr(pos + 2, 1), nullptr, 16);
			map[i][j].bgColor = std::stoul(HEX_PREFIX + line.substr(pos + 3, 1), nullptr, 16);
		}
	}

	return new Sprite(map, width, height);
}


Sprite* SpriteManager::copy(Sprite* original, char value, int fgColor, int bgColor)
{
	Pixel** map = new Pixel*[original->height];
	for (unsigned int i = 0; i < original->height; i++)
	{
		map[i] = new Pixel[original->width];

		for (unsigned int j = 0; j < original->width; j++)
		{
			int fg, bg;
			if (original->map[i][j].isTransparent()) {
				fg = bg = Color::MAGENTA;
			}
			else {
				fg = fgColor != NULL ? fgColor : original->map[i][j].fgColor;
				bg = bgColor != NULL ? bgColor : original->map[i][j].bgColor;
			}

			map[i][j].value = value != NULL ? value : original->map[i][j].value;
			map[i][j].fgColor = fg;
			map[i][j].bgColor = bg;
		}
	}

	return new Sprite(map, original->width, original->height);
}


Sprite* SpriteManager::transparent(Sprite* original)
{
	return SpriteManager::copy(original, ' ', Color::MAGENTA, Color::MAGENTA);
}

Sprite* SpriteManager::empty(const unsigned int width, const unsigned int height)
{
	return fill(width, height, ' ', Color::MAGENTA, Color::MAGENTA);
}

Sprite* SpriteManager::fill(const unsigned int width, const unsigned int height, char value, int fgColor, int bgColor)
{

	Pixel** map = new Pixel*[height];
	for (unsigned int i = 0; i < height; i++)
	{
		map[i] = new Pixel[width];

		for (unsigned int j = 0; j < width; j++)
		{
			map[i][j] = Pixel(value, fgColor, bgColor);
		}
	}

	return new Sprite(map, width, height);
}