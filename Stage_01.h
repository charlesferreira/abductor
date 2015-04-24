#pragma once

#include "Cloud.h"
#include "Stage.h"

class Stage_01 :
	public Stage
{
protected:
	long spawningTime = 0;
	long nextSpawn = STAGE_MIN_SPAWN_TIME;

	std::vector<Cloud*> clouds;

public:
	Stage_01();
	~Stage_01();

	void setup();

	void update(long);

protected:
	void addAnimals(unsigned, bool = true);
	void addAnimal(bool = true);

	void addClouds();
	void addCloud(int x = SCREEN_WIDTH);
};
