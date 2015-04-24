#pragma once

#include "Scene.h"
#include <chrono>

class Game
{
public:
	static enum State {New, Running, Finished};

private:
	Scene* scene;
	State state = Game::New;

public:
	void run();
	State getState() { return state; };
	void setState(State _state) { state = _state; };
	void setScene(Scene* _scene) { scene = _scene; };


	/*
	* Singleton example by Loki Astari on:
	* http://stackoverflow.com/questions/1008019/c-singleton-design-pattern
	* (Visited on Apr 14, 2015)
	*/
	static Game& getInstance()
	{
		static Game instance;
		return instance;
	}

private:
	Game();
	~Game();
	Game(Game const&) = delete;
	void operator=(Game const&) = delete;

	void gameloop();
	long timer()
	{
		using namespace std::chrono;
		return (long)duration_cast<milliseconds>(high_resolution_clock::now().time_since_epoch()).count();
	};
};
