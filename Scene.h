#pragma once

#include "ConsoleBuffer.h"
#include "Entity.h"
#include "Keyboard.h"
#include <vector>

class Scene : public Entity, public KeyboardObserver
{
protected:
	std::vector<Entity*> elements;

public:
	Scene(int x = 0, int y = 0);

	virtual void update(long);
	virtual void paint();

	virtual void input(char);

protected:
	void next(Scene*);
};
