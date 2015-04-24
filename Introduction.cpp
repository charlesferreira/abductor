#include "BlinkBehavior.h"
#include "Color.h"
#include "Game.h"
#include "Introduction.h"
#include "Keyboard.h"
#include "Stage_01.h"
#include "Pig.h"
#include "SpriteManager.h"
#include "TextRibbon.h"

Introduction::Introduction() : Scene(0, 0)
{
	// loads scene background
	SpriteManager& assetManager = SpriteManager::getInstance();
	this->sprite = assetManager.load("Assets/Sprites/Scenes/Introduction.txt", SCREEN_WIDTH, SCREEN_HEIGHT);

	// loads scene elements
	lore = new TypeWriter(5, 5, "Assets/Lore.txt", Color::WHITE, Color::DARK_BLUE, STAGE_LORE_TEXT_SPEED);
	this->elements.push_back(lore);

	Pig* pig = new Pig(SCREEN_WIDTH - 19, SCREEN_HEIGHT - Pig::HEIGHT);
	pig->flipX();
	this->elements.push_back(pig);

	// receive keyboard events
	Keyboard::getInstance().attach(this);
}


Introduction::~Introduction()
{
	delete this->sprite;
	this->sprite = NULL;

	delete this->lore;
	this->lore = NULL;

	this->elements.clear();
}


void Introduction::update(long delta)
{
	Scene::update(delta);

	if (!ribbonHidden) return;

	if (lore->hasFinished()) {
		ribbonHidden = !ribbonHidden;

		TextRibbon* pressButton = new TextRibbon(20, 20, "   PRESS ENTER   ", Color::WHITE, Color::BLUE);
		pressButton->addBehavior(new BlinkBehavior(pressButton, 500, 0));
		this->elements.push_back(pressButton);
	}
}

void Introduction::paint()
{
	Scene::paint();

	ConsoleBuffer& buffer = ConsoleBuffer::getInstance();

	// instructions
	buffer.write(63, 6, "CONTROL", Color::MAROON, Color::SILVER);

	buffer.write(64, 8, "MOVE", Color::RED, Color::SILVER);
	buffer.write(64, 9, "     ", Color::WHITE, Color::RED);
	buffer.write(65, 9, std::string(1, 27), Color::WHITE, Color::RED);
	buffer.write(67, 9, std::string(1, 26), Color::WHITE, Color::RED);

	buffer.write(64, 11, "HIDE", Color::RED, Color::SILVER);
	buffer.write(64, 12, "space", Color::WHITE, Color::RED);

	buffer.write(63, 14, "ABDUCT!", Color::RED, Color::SILVER);
	buffer.write(64, 15, "  e  ", Color::WHITE, Color::RED);
}

void Introduction::input(char key)
{
	Scene::input(key);

	if (key == VK_RETURN) {
		// RETURN skips to next scene
		this->next(new Stage_01());
	}
}
