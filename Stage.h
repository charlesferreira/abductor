#pragma once

#include "Animals.h"
#include "Farmer.h"
#include "GameMonitor.h"
#include "Scene.h"
#include "Ship.h"

class Stage
	: public Scene
{
	friend class GameMonitor;

protected:
	Animals* animals;
	Farmer* enemy;
	Ship* player;

public:
	Stage();

	virtual void setup() = 0;

	void update(long);
	void paint();

protected:
	virtual void addAnimals(unsigned, bool = true) = 0;
	virtual void addAnimal(bool = true) = 0;

	void gameover();
};

