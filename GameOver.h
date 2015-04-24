#pragma once

#include "Scene.h"

class GameOver :
	public Scene
{
public:
	static const int WIDTH = 54;
	static const int HEIGHT = 8;
public:
	GameOver();

	void paint();

	void input(char key);
};
