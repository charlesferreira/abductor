#pragma once

class Pixel
{

public:
	char value;
	int bgColor;
	int fgColor;
	bool forceRefresh = false;
	
	Pixel() : Pixel(' ', 0, 0) {};
	Pixel(char _value, int _fgColor, int _bgColor)
		: value(_value), fgColor(_fgColor), bgColor(_bgColor) {};

	bool isTransparent();
	bool equalsTo(Pixel*);

	void copy(Pixel&);
	void makeTransparent();
};

