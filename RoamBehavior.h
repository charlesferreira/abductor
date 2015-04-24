#pragma once

#include "Animal.h"
#include "Behaves.h"
#include "Behavior.h"
#include "Entity.h"

class RoamBehavior :
	public Behavior
{
protected:
	Animal* animal;
	long steps = 0;
	long partial = 0;
	long interval;
	unsigned speed;

public:
	RoamBehavior(Behaves* subject, long duration, int repeat);

	void execute(long);
	bool finished();
};

