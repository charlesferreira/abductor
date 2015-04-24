#include "Color.h"
#include "Ship.h"
#include "SpriteManager.h"
#include "TractorBeam.h"

TractorBeam::TractorBeam(Ship* ship)
{
	this->ship = ship;

	// loads beam sprite
	SpriteManager& spriteManager = SpriteManager::getInstance();
	this->beamSprite = spriteManager.load("Assets/Sprites/Player/TractorBeam.txt", WIDTH, HEIGHT);
	this->sprite = spriteManager.transparent(this->beamSprite);
}

void TractorBeam::reset()
{
	SpriteManager& spriteManager = SpriteManager::getInstance();
	this->sprite = spriteManager.transparent(this->beamSprite);

	currentSize = 0;
	state = State::New;
}

void TractorBeam::fire()
{
	state = State::Descending;
}

bool TractorBeam::hasFinished()
{
	return state == State::New;
}

bool TractorBeam::readyForAbduction()
{
	return state == State::FullSize;
}

void TractorBeam::update(long delta)
{
	x = ship->x + 1;
	y = ship->y + 3;

	animate(delta);
}

void TractorBeam::animate(long delta)
{
	if (state == State::New) return;

	sumAnimation += delta;

	if (state == State::FullSize) {
		if (sumAnimation > animationDelay * 10) {
			state = State::Ascending;
			sumAnimation = 0;
		}
		return;
	}

	if (sumAnimation > animationDelay) {
		sumAnimation -= animationDelay;

		state == State::Descending ? increaseSize() : decreaseSize();
	}

}

void TractorBeam::increaseSize()
{
	for (int j = 0; j < WIDTH; j++) {
		sprite->map[currentSize][j].copy(beamSprite->map[currentSize][j]);
	}

	if (++currentSize == HEIGHT)
		state = State::FullSize;
}

void TractorBeam::decreaseSize()
{
	if (--currentSize == 0)
		state = State::New;

	for (int j = 0; j < WIDTH; j++) {
		sprite->map[currentSize][j].makeTransparent();
	}
}