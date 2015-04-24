#pragma once

#include "Behavior.h"

class IdleBehavior :
	public Behavior
{
private:
	long elapsed = 0;

public:
	IdleBehavior(Behaves* subject) : Behavior(subject, 0, 0) {};

	void execute(long);

	bool finished();
};

