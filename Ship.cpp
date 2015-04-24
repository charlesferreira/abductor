#include "Color.h"
#include "Config.h"
#include "Ship.h"
#include "SpriteManager.h"

#include <Windows.h>

Ship::Ship(int x, int y) : Entity(x, y)
{
	// loads ship sprite
	SpriteManager& spriteManager = SpriteManager::getInstance();
	this->sprite = spriteManager.load("Assets/Sprites/Player/Ship.txt", WIDTH, HEIGHT);

	// loads ship hidden sprite
	hiddenSprite = spriteManager.copy(sprite, 176, Color::SILVER, Color::WHITE);
	exposedSprite = sprite;

	// prepares ship's tractor beam
	beam = new TractorBeam(this);
}

Ship::~Ship()
{
	delete hiddenSprite;
	hiddenSprite = NULL;
}

void Ship::reset()
{
	x = PLAYER_STARTING_POS_X;
	y = PLAYER_STARTING_POS_Y;
	expose();
	beam->reset();
}

void Ship::update(long delta)
{
	Behaves::update(delta);

	// runs animation
	animate(delta);

	// abducting
	if (state == State::Abducting) {
		beam->update(delta);

		if (beam->hasFinished()) {
			state = State::Playing;
		}
		else {
			return;
		}
	}

	// ship actions
	if (GetAsyncKeyState(GAME_CONTROL_HIDE)) hide(); // can't move while hidden
	else{
		if (GetAsyncKeyState(GAME_CONTROL_ABDUCT)) abduct(); // can't move while abducting
		else {
			if (GetAsyncKeyState(GAME_CONTROL_LEFT)) moveLeft(delta);
			if (GetAsyncKeyState(GAME_CONTROL_RIGHT)) moveRight(delta);
		}
	}
}

void Ship::paint()
{
	Entity::paint();

	beam->paint();
}

void Ship::moveLeft(long delta)
{
	sumLeft += delta;

	if (sumLeft >= moveDelay) {
		sumLeft -= moveDelay;
		if (x > 0) {
			expose();
			x--;
		}
	}
}

void Ship::moveRight(long delta)
{
	sumRight += delta;

	if (sumRight >= moveDelay) {
		sumRight -= moveDelay;
		if (x < SCREEN_WIDTH - WIDTH) {
			expose();
			x++;
		}
	}
}

void Ship::hide()
{
	state = State::Hidden;
	sprite = hiddenSprite;
}

void Ship::expose()
{
	state = State::Playing;
	sprite = exposedSprite;
}

void Ship::abduct()
{
	if (state == Abducting) return;
	expose();
	state = State::Abducting;
	beam->fire();
}

void Ship::animate(long delta)
{
	if (state == State::Hidden) return;

	sumAnimation += delta;

	if (sumAnimation >= animationDelay) {
		sumAnimation -= animationDelay;

		// cycles the center pixels
		Pixel* temp;
		for (int curr = 0; curr < WIDTH; curr++) {
			int next = (curr + 1) % WIDTH;
			temp = &sprite->map[1][curr];
			sprite->map[1][curr] = sprite->map[1][next];
			sprite->map[1][next] = *temp;

			sprite->map[1][curr].forceRefresh = true;
			sprite->map[1][next].forceRefresh = true;
		}
	}
}


void Ship::behaviorFinished(Behavior* behavior)
{
	//
}