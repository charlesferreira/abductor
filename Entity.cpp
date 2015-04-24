#include "Entity.h"

Entity::~Entity()
{
	delete this->sprite;
	this->sprite = NULL;
}

void Entity::flipX(bool flip)
{
	flippedX = flip;
}

void Entity::flipY(bool flip)
{
	flippedY = flip;
}

COORD Entity::center()
{
	int centerX = (int)(width() / 2 + x);
	int centerY = (int)(height() / 2 + y);

	return { centerX, centerY };
}

void Entity::paint()
{
	ConsoleBuffer& buffer = ConsoleBuffer::getInstance();

	buffer.write(x, y, sprite, flippedX);
}
