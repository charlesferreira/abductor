#include "Keyboard.h"

#include <algorithm>
#include <conio.h>
#include <iostream>

void Keyboard::listen()
{
	if (_kbhit()) {
		char key = _getch();
		if (key >= 0) {
			this->notifyObservers(key);
		}
	}
}

void Keyboard::attach(KeyboardObserver *observer)
{
	observers.push_back(observer);
}

void Keyboard::detach(KeyboardObserver* observer)
{
	observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Keyboard::notifyObservers(char key)
{
	std::vector<KeyboardObserver*> o = std::vector<KeyboardObserver*>(observers);

	for (std::vector<KeyboardObserver*>::iterator it = o.begin(); it != o.end(); ++it) {
		(*it)->input(key);
	}
}