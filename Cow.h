#pragma once

#include "Animal.h"

class Cow
	: public Animal
{
public:
	static const int WIDTH = 17;
	static const int HEIGHT = 9;

	void update(long);

	Cow(int x = 0, int y = 0);
};
