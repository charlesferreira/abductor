#pragma once

#include "Animal.h"

class Pig
	: public Animal
{
protected:
	unsigned movespeed = PIG_DEFAULT_MOVESPEED;

public:
	static const int WIDTH = 9;
	static const int HEIGHT = 6;

	void update(long);

	Pig(int x = 0, int y = 0);
};
