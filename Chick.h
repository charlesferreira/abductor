#pragma once

#include "Animal.h"

class Chick
	: public Animal
{
protected:
	unsigned movespeed = CHICK_DEFAULT_MOVESPEED;

public:
	static const int WIDTH = 4;
	static const int HEIGHT = 3;

	void update(long);

	Chick(int x = 0, int y = 0);
};
