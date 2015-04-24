#pragma once

#include "Pixel.h"

class Sprite
{
private:

public:
	Pixel** map;
	const unsigned int width;
	const unsigned int height;

	Sprite(Pixel** _map, const unsigned int _width, const unsigned int _height)
		: map(_map), width(_width), height(_height) {};
	~Sprite();
};