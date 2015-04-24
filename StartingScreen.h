#pragma once

#include "Scene.h"

class StartingScreen :
	public Scene
{
public:
	StartingScreen();
	~StartingScreen();

	void paint();

	void input(char);
};
