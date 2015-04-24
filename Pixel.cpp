#include "Color.h"
#include "Pixel.h"

bool Pixel::equalsTo(Pixel* other)
{
	return (
		this->value == other->value &&
		this->fgColor == other->fgColor &&
		this->bgColor == other->bgColor
	);
}

bool Pixel::isTransparent()
{
	return this->fgColor == Color::MAGENTA && this->bgColor == Color::MAGENTA;
}

void Pixel::copy(Pixel& other)
{
	value = other.value;
	fgColor = other.fgColor;
	bgColor = other.bgColor;
}

void Pixel::makeTransparent()
{
	fgColor = bgColor = Color::MAGENTA;
}