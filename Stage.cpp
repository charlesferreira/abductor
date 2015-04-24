#include "GameOver.h"
#include "Stage.h"

Stage::Stage() : Scene(0, 0)
{
	// creates the game monitor
	GameMonitor& monitor = GameMonitor::getInstance();
	monitor.setStage(this);
}

void Stage::update(long delta)
{
	GameMonitor& monitor = GameMonitor::getInstance();
	monitor.update(delta);

	// If the monitor is hanging, for whatever reason,
	// (e.g.: detected a collision, or game is paused)
	// prevents from updating scene elements.
	if (monitor.state == GameMonitor::Hanging)	return;

	Scene::update(delta);
}

void Stage::paint()
{
	Scene::paint();

	GameMonitor& monitor = GameMonitor::getInstance();
	monitor.paint();
}

void Stage::gameover()
{
	// since the Game Over text shows up the current
	// scene, here we paint it one last time to ensure
	// everything showing is up to date (like the HUD)
	paint();

	next(new GameOver());
}