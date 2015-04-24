#include "Animal.h"
#include "RoamBehavior.h"

void Animal::update(long delta)
{
	Behaves::update(delta);
}

void Animal::behaviorFinished(Behavior* behavior)
{
	nextBehavior(behavior);
}

void Animal::nextBehavior(Behavior* lastBehavior)
{
	// default behavior: walk around
	addBehavior(new RoamBehavior(this, width() / 2 + rand() % 10, 1));
}