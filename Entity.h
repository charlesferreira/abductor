#pragma once

#include "ConsoleBuffer.h"
#include "Sprite.h"

class Entity
{
public:
	Sprite* sprite;

	int x = 0;
	int y = 0;

	bool flippedX = false;
	bool flippedY = false;

	void flipX(bool flip = true);
	void flipY(bool flip = true);

	COORD center();

	inline unsigned width() const {
		return sprite->width;
	}
	inline unsigned height() const {
		return sprite->height;
	}

	virtual void update(long) = 0;
	virtual void paint();

	Entity() : Entity(0, 0) {};
	Entity(int _x, int _y) : x(_x), y(_y) {};
	~Entity();
};
