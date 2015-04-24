#include "Behaves.h"
#include "Behavior.h"

#include <algorithm>

void Behaves::update(long delta)
{
	std::vector<Behavior*> b = std::vector<Behavior*>(behaviors);

	for (std::vector<Behavior*>::iterator it = b.begin(); it != b.end(); ++it) {
		(*it)->execute(delta);
	}
}

void Behaves::remove(Behavior* behavior)
{
	behaviors.erase(std::remove(behaviors.begin(), behaviors.end(), behavior), behaviors.end());

	delete behavior;
}