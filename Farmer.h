#pragma once

#include "Animal.h"
#include "Ship.h"

class Farmer :
	public Animal
{
protected:
	unsigned movespeed = FARMER_DEFAULT_MOVESPEED;

	bool alert = false;
	int totalSuspiciousTime = 0;

public:
	static const int WIDTH = 5;
	static const int HEIGHT = 13;

	void update(long);
	void paint();

	void printExclamationMark();
	void printQuestionMark();

	void reset();

	bool spottedUFO();

	Farmer(int x = FARMER_STARTING_POS_X, int y = FARMER_STARTING_POS_Y);

	void nextBehavior(Behavior* lastBehavior = NULL);

protected:
	void checkForUFOs();
	bool ufoOnSight();
};

