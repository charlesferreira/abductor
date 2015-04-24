#include "AssetManager.h"
#include "Color.h"
#include "Pixel.h"
#include "SpriteManager.h"
#include "TypeWriter.h"

#include <string>
#include <vector>

TypeWriter::TypeWriter(int x, int y, std::string filename, int fgColor, int bgColor, int speed)
	:Entity(x, y)
{
	// loads text file
	AssetManager& assetManager = AssetManager::getInstance();
	std::vector<std::string> text = assetManager.readfile(filename);

	// calculates max text width
	unsigned int height = text.size();
	unsigned int width = 0;
	for (std::vector<std::string>::iterator it = text.begin(); it != text.end(); ++it) {
		if ((*it).size() >= width)
			width = (*it).size() + 1;
	}
	
	// creates empty sprite
	SpriteManager& spriteManager = SpriteManager::getInstance();
	sprite = spriteManager.empty(width, height);
	
	// creates text sprite
	textSprite = spriteManager.fill(width, height, ' ', fgColor, bgColor);
	for (unsigned int i = 0; i < height; i++) {
		for (unsigned int j = 0; j < width; j++) {
			if (j >= text[i].length()) break;
			char value = text[i][j];
			textSprite->map[i][j].value = value;
		}
	}

	//sprite = textSprite;
	
	// other settings
	next = { 0, 0 };
	animationDelay = ANIMATION_BASE_INTERVAL / speed;
}


TypeWriter::~TypeWriter()
{
}

void TypeWriter::update(long delta)
{
	animate(delta);
}

void TypeWriter::animate(long delta)
{
	if (finished) return;

	sumAnimation += delta;

	if (sumAnimation >= animationDelay) {
		sumAnimation -= animationDelay;

		while (textSprite->map[next.Y][next.X].value == ' ') {
			if (++next.X >= (int)width()) {
				next.X = 0;
				if (++next.Y >= (int)height()) {
					finished = true;
					return;
				}
			}
		}

		sprite->map[next.Y][next.X].copy(textSprite->map[next.Y][next.X]);
		//sprite->map[next.Y][next.X].forceRefresh = true;
		next.X++;
	}
}