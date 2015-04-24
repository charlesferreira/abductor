#pragma once

#include "Behaves.h"
#include "Behavior.h"
#include "Color.h"
#include "Entity.h"
#include <string>

class TextRibbon :
	public Entity, public Behaves
{
private:
	int fgColor;
	int bgColor;
	bool centered = false;

public:
	TextRibbon(int x, int y, std::string text, int fgColor, int bgColor);

	TextRibbon(std::string text, int fgColor, int bgColor) : TextRibbon(0, 0, text, fgColor, bgColor) {};
	~TextRibbon();

	inline void center(bool _centered) { centered = _centered; }

	void update(long);
	void paint();

	void behaviorFinished(Behavior*);
};

