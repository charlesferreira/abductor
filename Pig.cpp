#include "Pig.h"
#include "SpriteManager.h"

Pig::Pig(int x, int y) : Animal(x, y, PIG_DEFAULT_MOVESPEED + speedBoost(PIG_DEFAULT_MOVESPEED))
{
	// loads pig "image"
	SpriteManager& spriteManager = SpriteManager::getInstance();
	this->sprite = spriteManager.load("Assets/Sprites/Animals/Pig.txt", WIDTH, HEIGHT);
}

void Pig::update(long delta)
{
	Animal::update(delta);
}