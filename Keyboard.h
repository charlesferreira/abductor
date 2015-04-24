#pragma once

#include "KeyboardObserver.h"
#include <vector>

class Keyboard
{
private:
	std::vector<KeyboardObserver*> observers;

public:
	void listen();
	void attach(KeyboardObserver* observer);
	void detach(KeyboardObserver* observer);


	/*
	* Singleton example by Loki Astari on:
	* http://stackoverflow.com/questions/1008019/c-singleton-design-pattern
	* (Visited on Apr 14, 2015)
	*/
	static Keyboard& getInstance()
	{
		static Keyboard instance;
		return instance;
	}

private:
	Keyboard() {};
	Keyboard(Keyboard const&) = delete;
	void operator=(Keyboard const&) = delete;

	void notifyObservers(char key);
};
