#include "Game.h"
#include "Scene.h"

Scene::Scene(int x, int y) : Entity(x, y)
{
	// receive keyboard events
	Keyboard::getInstance().attach(this);
}

void Scene::update(long delta)
{
	for (std::vector<Entity*>::iterator it = elements.begin(); it != elements.end(); ++it) {
		(*it)->update(delta);
	}
}

void Scene::paint()
{
	// prints stage background
	Entity::paint();

	// prints stage elements
	for (std::vector<Entity*>::iterator it = elements.begin(); it != elements.end(); ++it){
		(*it)->paint();
	}
}

void Scene::input(char key)
{
	if (key == 27) {
		// ESC ends the game at any time
		Game::getInstance().setState(Game::Finished);
	}
}

void Scene::next(Scene* next)
{
	Keyboard::getInstance().detach(this);

	Game::getInstance().setScene(next);
}