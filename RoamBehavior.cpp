#include "RoamBehavior.h"


RoamBehavior::RoamBehavior(Behaves* subject, long duration, int repeat)
	: Behavior(subject, duration, repeat)
{
	animal = dynamic_cast<Animal*>(subject);
	interval = ANIMATION_BASE_INTERVAL / animal->speed();
}

void RoamBehavior::execute(long delta)
{
	partial += delta;
	if (partial >= interval) {
		partial %= interval;

		// advances one step
		animal->x += animal->flippedX ? -1 : 1;
		animal->y += animal->x % 2 == 0 ? -1 : 1; // jumpy move! \o/

		if (repeat > 0 && ++steps >= duration) {
			steps = 0;

			if (++counter >= repeat) {
				notify();
				return;
			}
		}

		// flips when reaches the borders
		if (animal->x <= 0) {
			animal->flipX(false);
		}
		else if (animal->x + animal->width() >= SCREEN_WIDTH)
		{
			animal->flipX(true);
		}
	}
}

bool RoamBehavior::finished()
{
	return steps >= duration;
}