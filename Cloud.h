#pragma once

#include "Entity.h"

class Cloud
	: public Entity
{
protected:
	int animationDelay;
	int lastAnimation = 0;

public:
	static const int WIDTH = 11;
	static const int HEIGHT = 4;

	void setup();

	void update(long);

	Cloud(int x = 0, int y = 0);
};
