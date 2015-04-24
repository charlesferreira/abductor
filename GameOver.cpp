#include "Entity.h"
#include "GameMonitor.h"
#include "GameOver.h"
#include "SpriteManager.h"
#include "StartingScreen.h"

#include "RoamBehavior.h"

GameOver::GameOver() : Scene(0, 0)
{
	// loads scene background
	SpriteManager& assetManager = SpriteManager::getInstance();
	this->sprite = assetManager.load("Assets/Sprites/Scenes/GameOver.txt", WIDTH, HEIGHT);
}

void GameOver::paint()
{
	ConsoleBuffer& buffer = ConsoleBuffer::getInstance();
	buffer.writeCentered(sprite);
}

void GameOver::input(char key)
{
	Scene::input(key);

	if (key == VK_RETURN) {
		GameMonitor& monitor = GameMonitor::getInstance();
		monitor.reset();

		Scene::next(new StartingScreen());
	}
}