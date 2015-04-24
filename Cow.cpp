#include "Cow.h"
#include "SpriteManager.h"

Cow::Cow(int x, int y) : Animal(x, y, COW_DEFAULT_MOVESPEED + speedBoost(COW_DEFAULT_MOVESPEED))
{
	// loads cow "image"
	SpriteManager& spriteManager = SpriteManager::getInstance();
	this->sprite = spriteManager.load("Assets/Sprites/Animals/Cow.txt", WIDTH, HEIGHT);
}

void Cow::update(long delta)
{
	Animal::update(delta);
}
