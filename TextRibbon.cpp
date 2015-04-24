#include "TextRibbon.h"
#include <vector>

TextRibbon::TextRibbon(int x, int y, std::string text, int fgColor, int bgColor) : Entity(x, y)
{
	int length = text.length();
	Pixel** pixelMap = new Pixel*[1];
	pixelMap[0] = new Pixel[length];

	for (int index = 0; index < length; index++)
	{
		pixelMap[0][index].value = text[index];
		pixelMap[0][index].fgColor = fgColor;
		pixelMap[0][index].bgColor = bgColor;
	}

	this->sprite = new Sprite(pixelMap, text.length(), 1);
}

TextRibbon::~TextRibbon()
{

}

void TextRibbon::update(long delta)
{
	Behaves::update(delta);
}

void TextRibbon::paint()
{
	if (!centered) {
		return Entity::paint();
	}

	ConsoleBuffer::getInstance().writeCentered(sprite);
}

void TextRibbon::behaviorFinished(Behavior* behavior)
{
	//
}
