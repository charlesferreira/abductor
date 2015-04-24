#pragma once

#include "Scene.h"
#include "TypeWriter.h"

class Introduction :
	public Scene
{
private:
	bool ribbonHidden = true;
	TypeWriter* lore;

public:
	Introduction();
	~Introduction();

	void input(char);

	void update(long);
	void paint();
};
