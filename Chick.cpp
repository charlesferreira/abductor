#include "Chick.h"
#include "SpriteManager.h"

Chick::Chick(int x, int y) : Animal(x, y, CHICK_DEFAULT_MOVESPEED + speedBoost(CHICK_DEFAULT_MOVESPEED))
{
	// loads chick "image"
	SpriteManager& spriteManager = SpriteManager::getInstance();
	this->sprite = spriteManager.load("Assets/Sprites/Animals/Chick.txt", WIDTH, HEIGHT);
}

void Chick::update(long delta)
{
	Animal::update(delta);
}