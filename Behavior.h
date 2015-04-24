#pragma once

#include "Behaves.h"

class Behavior
{
protected:
	Behaves* subject;
	long duration;
	int repeat;
	int counter = 0;

public:
	Behavior(Behaves* _subject, long _duration, int _repeat)
		: subject(_subject), duration(_duration), repeat(_repeat) {};

	virtual void execute(long delta) = 0;
	virtual bool finished() = 0;

	void notify();
};