#include "Animals.h"

#include <algorithm>

void Animals::update(long delta)
{
	for (std::vector<Animal*>::iterator it = elements.begin(); it != elements.end(); ++it) {
		(*it)->update(delta);
	}
}

void Animals::paint()
{
	for (std::vector<Animal*>::iterator it = elements.begin(); it != elements.end(); ++it) {
		(*it)->paint();
	}
}

void Animals::add(Animal* animal)
{
	elements.push_back(animal);
	std::sort(elements.begin(), elements.end());
}

void Animals::erase(Animal* animal)
{
	elements.erase(std::remove(elements.begin(), elements.end(), animal), elements.end());
}

void Animals::clear()
{
	elements.clear();
}

std::vector<Animal*> Animals::list() const
{
	return std::vector<Animal*>(elements);
}