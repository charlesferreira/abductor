#pragma once

#include "Entity.h"

class Ship;
class TractorBeam
	: public Entity
{
	enum State {New, Descending, FullSize, Ascending};

private:
	State state = New;

	Ship* ship;
	Sprite* beamSprite;
	int currentSize = 0;

	long sumAnimation = 0;
	long animationDelay = ANIMATION_BASE_INTERVAL / PLAYER_BEAM_SPEED;

public:
	static const int WIDTH = 9;
	static const int HEIGHT = 18;

	void reset();

	void fire();
	bool hasFinished();

	void update(long);

	bool readyForAbduction();

	TractorBeam(Ship*);

private:
	TractorBeam(int x, int y);
	void animate(long);
	void increaseSize();
	void decreaseSize();
};
