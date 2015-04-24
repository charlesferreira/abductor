#include "BlinkBehavior.h"
#include "Color.h"
#include "Cow.h"
#include "Entity.h"
#include "Game.h"
#include "Introduction.h"
#include "Keyboard.h"
#include "SpriteManager.h"
#include "StartingScreen.h"
#include "TextRibbon.h"

#include "RoamBehavior.h"

StartingScreen::StartingScreen() : Scene(0, 0)
{
	// loads scene background
	SpriteManager& assetManager = SpriteManager::getInstance();
	this->sprite = assetManager.load("Assets/Sprites/Scenes/StartingScreen.txt", SCREEN_WIDTH, SCREEN_HEIGHT);

	// loads scene elements
	Cow* cow = new Cow(12, 15);
	//cow->addBehavior(new RoamBehavior(cow, cow->width(), 1));
	this->elements.push_back(cow);

	TextRibbon* pressButton = new TextRibbon("   PRESS ENTER   ", Color::WHITE, Color::RED);
	pressButton->center(true);
	pressButton->addBehavior(new BlinkBehavior(pressButton, 500, 0));
	this->elements.push_back(pressButton);

	// receive keyboard events
	Keyboard::getInstance().attach(this);
}


StartingScreen::~StartingScreen()
{
	//delete this->sprite;
	this->sprite = NULL;

	this->elements.clear();
}

void StartingScreen::paint()
{
	Scene::paint();

	ConsoleBuffer& buffer = ConsoleBuffer::getInstance();

	buffer.write(3, 7, "Salvation comes from above", Color::WHITE, Color::DARK_BLUE);
	buffer.write(56, 19, "Producted by", Color::WHITE, Color::BLUE);
	buffer.write(54, 21, "CHARLES FERREIRA", Color::WHITE, Color::BLUE);
	buffer.write(74, 24, "2015", Color::LIME, Color::DARK_GREEN);
}

void StartingScreen::input(char key)
{
	Scene::input(key);

	if (key == VK_RETURN) {
		// RETURN skips to next scene
		this->next(new Introduction());
	}
}