#include "Color.h"
#include "Farmer.h"
#include "GameMonitor.h"
#include "SpriteManager.h"

Farmer::Farmer(int x, int y) : Animal(x, y, FARMER_DEFAULT_MOVESPEED)
{
	// loads farmer sprite
	SpriteManager& spriteManager = SpriteManager::getInstance();
	this->sprite = spriteManager.load("Assets/Sprites/Enemy/Farmer.txt", WIDTH, HEIGHT);
}

void Farmer::reset()
{
	x = FARMER_STARTING_POS_X;
	y = FARMER_STARTING_POS_Y;
	alert = false;
	flippedX = false;
	totalSuspiciousTime = 0;
}

void Farmer::checkForUFOs()
{
	if (ufoOnSight()) {
		alert = true;
	}
}

bool Farmer::ufoOnSight()
{
	GameMonitor& monitor = GameMonitor::getInstance();
	COORD ufoCoords = monitor.getPlayerCenter();

	int px = ufoCoords.X;
	int ex = center().X +(flippedX ? 1 : -1);

	return (flippedX ? px < ex : px > ex) && !monitor.isPlayerHidden();
}

bool Farmer::spottedUFO()
{
	GameMonitor& monitor = GameMonitor::getInstance();

	if (alert && !monitor.isPlayerHidden() && totalSuspiciousTime >= PLAYER_MAX_REACTION_TIME && ufoOnSight())
		return true;

	return false;
}

void Farmer::update(long delta)
{
	Animal::update(delta);

	checkForUFOs();

	if (alert) {
		this->totalSuspiciousTime += delta;

		if (totalSuspiciousTime >= FARMER_MAX_SUSPICIOUS_TIME) {
			totalSuspiciousTime = 0;
			alert = false;
		}
	}
}

void Farmer::paint()
{
	Animal::paint();

	// spotted an UFO!!!
	if (alert) {
		spottedUFO()
			? printExclamationMark()
			: printQuestionMark();
	}
}

void Farmer::printExclamationMark()
{
	ConsoleBuffer& buffer = ConsoleBuffer::getInstance();
	buffer.write(center().X, y - 4, std::string(1, 219), Color::YELLOW, Color::BLUE);
	buffer.write(center().X, y - 3, std::string(1, 219), Color::YELLOW, Color::BLUE);
	buffer.write(center().X, y - 2, std::string(1, 220), Color::YELLOW, Color::BLUE);
}

void Farmer::printQuestionMark()
{
	ConsoleBuffer& buffer = ConsoleBuffer::getInstance();
	buffer.write(center().X, y - 4, std::string(1, 219), Color::OLIVE, Color::BLUE);
	buffer.write(center().X, y - 3, std::string(1, 219), Color::OLIVE, Color::BLUE);
	buffer.write(center().X, y - 2, std::string(1, 220), Color::OLIVE, Color::BLUE);
}

void Farmer::nextBehavior(Behavior* lastBehavior)
{
	if (lastBehavior == NULL) {
		// default behavior: walk around
	}

	Animal::nextBehavior();
}