#pragma once

#include "Behavior.h"
#include "Entity.h"
#include "TractorBeam.h"

class Ship
	: public Entity, public Behaves
{
public:
	enum State {Playing, Hidden, Abducting};

private:
	State state = Playing;

	Sprite* hiddenSprite;
	Sprite* exposedSprite;

	TractorBeam* beam;

	long sumLeft = 0;
	long sumRight = 0;
	long sumAnimation = 0;

	long moveDelay = ANIMATION_BASE_INTERVAL / PLAYER_MOVE_SPEED;
	long animationDelay = ANIMATION_BASE_INTERVAL / PLAYER_ANIMATION_SPEED;

public:
	static const int WIDTH = 11;
	static const int HEIGHT = 3;

	void reset();

	void update(long);
	void paint();

	inline bool readyForAbduction() const {
		return beam->readyForAbduction();
	}

	inline bool hidden() {
		return state == State::Hidden;
	}

	void behaviorFinished(Behavior* behavior);

	Ship(int x = PLAYER_STARTING_POS_X, int y = PLAYER_STARTING_POS_Y);
	~Ship();

private:
	void moveLeft(long);
	void moveRight(long);
	void hide();
	void expose();
	void abduct();
	void animate(long);
};
