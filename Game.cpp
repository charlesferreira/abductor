#include "Color.h"
#include "Game.h"
#include "Keyboard.h"
#include "StartingScreen.h"

#include <conio.h>
#include <Windows.h>

Game::Game()
{
	srand((unsigned int)time(NULL));

	// sets up a new game
	this->scene = new StartingScreen();

	gameloop();
}

Game::~Game()
{
	delete this->scene;
	this->scene = NULL;
}

void Game::run()
{
	Game& game = Game::getInstance();

	if (game.getState() == Game::New) {
		game.setState(Game::Running);
		gameloop();
	}
}

void Game::gameloop()
{
	long delta = 0;
	long lastTime = Game::timer();  
	long lastPaint = 0;
	long pace = 1000 / 17; // ~60 FPS

	while (state != Game::Finished)
	{
		// "processes input events", or simulates it...
		Keyboard::getInstance().listen();

		// updates as often as possible
		this->scene->update(delta);

		// paints scene and its elements, keeping the frame rate
		lastPaint += delta;
		if (lastPaint >= pace) {
			lastPaint %= pace;
			this->scene->paint();
		}

		// flushes the buffer contents to console
		ConsoleBuffer::getInstance().flush();

		delta = Game::timer() - lastTime;
		lastTime = Game::timer();
	}
}