#pragma once

#include "Behavior.h"
#include "Entity.h"

class Animal :
	public Entity, public Behaves
{
protected:
	unsigned movespeed;

public:
	Animal(int x = 0, int y = 0, unsigned _movespeed = 1) : Entity(x, y), movespeed(_movespeed) {};

	virtual unsigned speed() {
		return movespeed;
	}

	virtual unsigned speedBoost(unsigned defaultSpeed) {
		return defaultSpeed * (rand() % ANIMAL_MAX_SPEED_BOOST) / 100;
	}

	virtual void update(long);

	virtual void behaviorFinished(Behavior* behavior);
	virtual void nextBehavior(Behavior* lastBehavior = NULL);

	// solves depth problem
	inline bool operator < (const Animal* animal) const {
		return (depth() < animal->depth());
	}

	inline int depth() const {
		return y + height();
	}
};

