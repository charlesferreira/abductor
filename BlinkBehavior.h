#pragma once

#include "Behaves.h"
#include "Behavior.h"
#include "Entity.h"

class BlinkBehavior :
	public Behavior
{
	enum State {On, Off};

protected:
	State state;
	long timeOn = 0;
	long timeOff = 0;
	Entity* entity;
	Sprite* spriteOn;
	Sprite* spriteOff;

public:
	BlinkBehavior(Behaves*, long, int);
	~BlinkBehavior();

	void execute(long);

protected:
	void on();
	void off();
	bool finished();
};

