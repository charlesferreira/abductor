#include "BlinkBehavior.h"
#include "Color.h"
#include "Pixel.h"
#include "Sprite.h"
#include "SpriteManager.h"

BlinkBehavior::BlinkBehavior(Behaves* subject, long duration, int repeat) : Behavior(subject, duration, repeat)
{
	entity = dynamic_cast<Entity*>(subject);

	// creates a copy of entity's sprite to make all pixels transparent
	spriteOff = SpriteManager::getInstance().transparent(entity->sprite);
	spriteOn = entity->sprite;

	// startinf state is "on"
	on();
}


BlinkBehavior::~BlinkBehavior()
{

}


void BlinkBehavior::execute(long delta)
{
	if (state == State::On) {
		if (timeOn < duration) {
			timeOn += delta;
		}
		else {
			off();
		}
	}
	else {
		if (timeOff < duration) {
			timeOff += delta;
		}
		else {
			on();
		}
	}
}


void BlinkBehavior::on()
{
	entity->sprite = spriteOn;
	state = State::On;
	timeOn = 0;

	if (finished()) {
		notify();
	}
}

void BlinkBehavior::off()
{
	entity->sprite = spriteOff;
	state = State::Off;
	timeOff = 0;
}

bool BlinkBehavior::finished()
{
	return (repeat > 0 && ++counter > repeat);
}