#include "IdleBehavior.h"

void IdleBehavior::execute(long delta)
{
	elapsed += delta;

	if (elapsed >= duration) {
		notify();
	}
}

bool IdleBehavior::finished()
{
	return elapsed >= duration;
}