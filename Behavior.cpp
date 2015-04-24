#include "Behaves.h"
#include "Behavior.h"

void Behavior::notify()
{
	this->subject->behaviorFinished(this);
	this->subject->remove(this);
} 