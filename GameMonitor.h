#pragma once

#include "Color.h"
#include "Entity.h"
#include "Stage.h"

class Stage; // breaks circular reference

class GameMonitor :
	public Entity
{
	friend class Stage;

public:
	enum State {Running, Hanging};

	static const int HUD_BG_COLOR = Color::DARK_BLUE;
	static const int HUD_FG_COLOR_ON = Color::CYAN;
	static const int HUD_FG_COLOR_OFF = Color::GRAY;

protected:
	Stage* stage;
	State state = Running;

	int sumTimer = 0;
	int hangingTime = 0;

	bool abducted = false;

	int score = 0;
	int lives = PLAYER_STARTING_LIVES;
	int timer = TIMER_STARTING_TIME;

	void addBonusTime();

public:
	inline void setStage(Stage* _stage) {
		stage = _stage;
	};

	COORD getPlayerCenter();
	bool isPlayerHidden();
	
	void reset();

	void update(long);
	void paint();

	static GameMonitor& getInstance()
	{
		static GameMonitor instance;
		return instance;
	}

protected:
	void updateTimer(long);
	void checkFarmerSight();
	void checkAbductionBeam();
	void killPlayer();
	void resume();

	GameMonitor() {};
	GameMonitor(GameMonitor const&) = delete;
	void operator=(GameMonitor const&) = delete;
};

