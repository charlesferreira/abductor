#pragma once

#include "Entity.h"

class TypeWriter :
	public Entity
{
private:
	Sprite* textSprite;

	COORD next;
	bool finished = false;

	int animationDelay;
	long sumAnimation = 0;;

public:
	TypeWriter(int x, int y, std::string filename, int fgColor, int bgColor, int speed);
	~TypeWriter();

	void update(long);
	inline bool hasFinished() { return finished; }

private:
	void animate(long);
};
