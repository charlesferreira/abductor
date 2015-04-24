#pragma once

#include "Sprite.h"
#include <vector>

class SpriteManager
{
public:
	const std::string HEX_PREFIX = "0x";

	Sprite* load(std::string filename, const unsigned int width, const unsigned int height);
	Sprite* load(std::string filename, const unsigned int width, const unsigned int height, const unsigned int x, const unsigned int y);
	Sprite* copy(Sprite*, char = NULL, int = NULL, int = NULL);
	Sprite* transparent(Sprite*);
	Sprite* empty(const unsigned int width, const unsigned int height);
	Sprite* fill(const unsigned int, const unsigned int, char, int, int);

	/*
	 * Singleton example by Loki Astari on:
	 * http://stackoverflow.com/questions/1008019/c-singleton-design-pattern
	 * (Visited on Apr 14, 2015)
	 */
	static SpriteManager& getInstance()
	{
		static SpriteManager instance;
		return instance;
	}

private:
	SpriteManager() {};
	SpriteManager(SpriteManager const&) = delete;
	void operator=(SpriteManager const&) = delete;
};
