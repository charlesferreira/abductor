/**
 * Main
 *
 * Kicks off the game.
 *
 * @author Charles Ferreira <charles6286@gmail.com>
 * @date Apr 12, 2015
 */

#include "Game.h"

void main()
{
	Game& game = Game::getInstance();
	game.run();

	return;
}