#include "GameMonitor.h"

#include <algorithm>
//#include <cmath>
#include <string>

void GameMonitor::update(long delta)
{
	if (state == State::Hanging) {
		hangingTime += delta;
		if (hangingTime >= STAGE_HANGING_TIME) {
			resume();
		}

		return;
	}

	updateTimer(delta);
	checkFarmerSight();
	checkAbductionBeam();
}

void GameMonitor::reset()
{
	score = 0;
	lives = PLAYER_STARTING_LIVES;
	timer = TIMER_STARTING_TIME;
}

void GameMonitor::updateTimer(long delta)
{
	sumTimer += delta;
	if (sumTimer >= 1000) {
		sumTimer %= 1000;

		if (--timer <= 0)
			killPlayer();
	}
}

void GameMonitor::checkFarmerSight()
{
	if (stage->enemy->spottedUFO())
		killPlayer();
}

void GameMonitor::checkAbductionBeam()
{
	if (!stage->player->readyForAbduction()) return;

	// searches animals list for abductable animal
	std::vector<Animal*> animals = stage->animals->list();
	for (std::vector<Animal*>::iterator it = animals.begin(); it != animals.end(); ++it) {
		if (abs(((*it)->center().X - stage->player->center().X)) <= PLAYER_ABDUCT_RADIUS) {
			stage->animals->erase((*it));

			timer = min(timer + TIMER_BONUS_PER_ANIMAL, TIMER_MAX_TIME);
			score = min(score + SCORE_BONUS_PER_ANIMAL, SCORE_MAX_SCORE);
		}
	}
}


void GameMonitor::killPlayer()
{
	state = State::Hanging;
	lives--;
}

void GameMonitor::resume()
{
	state = State::Running;
	hangingTime = 0;

	if (lives <= 0) {
		stage->gameover();
	}
	else {
		timer = TIMER_STARTING_TIME;
		stage->setup();
	}
}

COORD GameMonitor::getPlayerCenter()
{
	return stage->player->center();
}

bool GameMonitor::isPlayerHidden()
{
	return stage->player->hidden();
}

/**
 * Displays the HUD
 */
void GameMonitor::paint()
{
	ConsoleBuffer& buffer = ConsoleBuffer::getInstance();

	// pads and writes the score
	std::string score = std::to_string(this->score);
	buffer.write(7 - score.length(), 1, score, HUD_FG_COLOR_ON, HUD_BG_COLOR);

	// prints scores's "turned off" leading zeros
	for (unsigned i = 0; i < 5 - score.length(); i++)
		buffer.write(2 + i, 1, "0", HUD_FG_COLOR_OFF, HUD_BG_COLOR);

	// pads and writes the timer
	std::string timer = std::to_string(this->timer);
	buffer.write(40 - timer.length(), 1, timer, HUD_FG_COLOR_ON, HUD_BG_COLOR);

	// prints timer's "turned off" leading zero
	if (this->timer < 10)
		buffer.write(38, 1, "0", HUD_FG_COLOR_OFF, HUD_BG_COLOR);

	// displays player's life icons
	for (short i = 0; i < PLAYER_STARTING_LIVES; i++) {
		int color = i < lives ? HUD_FG_COLOR_ON : Color::GRAY;
		buffer.write(SCREEN_WIDTH - 7 + (2 * i), 1, std::string(1, PLAYER_LIFE_ICON_CODE), color, HUD_BG_COLOR);
	}
}