#pragma once

#include "Chick.h"
#include "Cow.h"
#include "Pig.h"

class Animals
	: public Entity
{
protected:
	std::vector<Animal*> elements;

public:
	Animals() : Entity(0, 0) {};
	~Animals();

	void update(long);
	void paint();

	void add(Animal*);
	void erase(Animal*);
	void clear();
	std::vector<Animal*> list() const;
};