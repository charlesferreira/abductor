#pragma once

#include <vector>

class Behavior; // breaks circular reference

class Behaves
{
protected:
	std::vector<Behavior*> behaviors;

public:
	inline void addBehavior(Behavior* behavior) {
		this->behaviors.push_back(behavior);
	}
	void remove(Behavior* behavior);

	virtual void update(long delta);

	virtual void behaviorFinished(Behavior* behavior) = 0;
	void erase(Behavior* behavior);
};

