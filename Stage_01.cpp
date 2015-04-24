#include "Animals.h"
#include "BlinkBehavior.h"
#include "Color.h"
#include "Farmer.h"
#include "Game.h"
#include "Stage_01.h"
#include "Pig.h"
#include "SpriteManager.h"
#include "TextRibbon.h"

Stage_01::Stage_01() : Stage()
{
	// loads scene background
	SpriteManager& assetManager = SpriteManager::getInstance();
	sprite = assetManager.load("Assets/Sprites/Scenes/Stage_01.txt", SCREEN_WIDTH, SCREEN_HEIGHT);

	// adds clouds
	addClouds();

	// loads animals onto stage
	animals = new Animals();
	elements.push_back(animals);

	// enter the player
	player = new Ship();
	elements.push_back(player);

	// enter the enemy
	enemy = new Farmer();
	enemy->nextBehavior();
	elements.push_back(enemy);

	// sets up stage elements
	setup();
}


Stage_01::~Stage_01()
{
	delete this->sprite;
	this->sprite = NULL;

	this->elements.clear();
}


void Stage_01::setup()
{
	// resets player's position
	player->reset();

	// resets enemy position
	enemy->reset();

	// resets animals list
	animals->clear();
	addAnimals(STAGE_STARTING_ANIMALS, false);
}

void Stage_01::update(long delta)
{
	spawningTime += delta;
	if (spawningTime >= nextSpawn && (animals->list().size() < STAGE_MAX_ANIMALS_ON_STAGE)) {
		spawningTime = 0;
		nextSpawn = STAGE_MIN_SPAWN_TIME + (rand() % (STAGE_MAX_SPAWN_TIME - STAGE_MIN_SPAWN_TIME));
		addAnimal();
	}

	Stage::update(delta);
}

void Stage_01::addAnimals(unsigned quantity, bool offScreen)
{
	for (unsigned i = 0; i < quantity; i++)
		addAnimal(offScreen);
}

void Stage_01::addAnimal(bool offScreen)
{
	Animal* animal;

	// sorts the race of the animal
	short race = rand() % 3;
	switch (race) {
	case 0:
		animal = new Chick();
		break;
	case 1:
		animal = new Cow();
		break;
	case 2:
		animal = new Pig();
		break;
	}

	// sorts which diretion the animal is facing
	animal->flipX(rand() % 2 == 0);

	// animal off screen
	if (offScreen) {
		animal->x = animal->flippedX
			? SCREEN_WIDTH
			: (-1 * animal->width());
	}
	// animal on screen
	else {
		animal->x = rand() % (SCREEN_WIDTH - animal->width());
	}

	// random behavior
	animal->nextBehavior();

	// sorts starting vertical line for this animal
	animal->y = SCREEN_HEIGHT - animal->height() - 2 - (rand() % 2);

	// adds the animal into stage's collection
	animals->add(animal);
}

void Stage_01::addClouds()
{
	for (int i = 0; i < STAGE_CLOUDS_STARTING_NUM; i++) {
		int x = (SCREEN_WIDTH / 6) * (1 + 2 * i);
		addCloud(x);
	}
}

void Stage_01::addCloud(int x)
{
	elements.push_back(new Cloud(x, STAGE_CLOUDS_POS_Y));
}