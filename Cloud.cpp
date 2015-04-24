#include "Cloud.h"
#include "SpriteManager.h"
#include <string>

Cloud::Cloud(int x, int y) : Entity(x, y)
{
	setup();

	this->x = x;
}

/**
 * Recycles the clouds
 */
void Cloud::setup()
{
	animationDelay = ANIMATION_BASE_INTERVAL / (STAGE_CLOUDS_BASE_SPEED * (1 + (rand() % 800) / 100));

	// loads a random cloud sprite
	std::string filename = std::string("Assets/Sprites/Scenes/Clouds/Cloud")
		+ std::to_string(rand() % STAGE_CLOUDS_NUM_SPRITES)
		+ std::string(".txt");

	SpriteManager& spriteManager = SpriteManager::getInstance();
	this->sprite = spriteManager.load(filename, WIDTH, HEIGHT);

	x = SCREEN_WIDTH;
}

void Cloud::update(long delta)
{
	lastAnimation += delta;

	if (lastAnimation >= animationDelay) {
		lastAnimation %= animationDelay;

		// all clouds move left :P
		x--;
	}

	if (x < -WIDTH) {
		setup();
	}
}
