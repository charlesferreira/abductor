#include "Color.h"
#include "Config.h"
#include "ConsoleBuffer.h"
#include "Pixel.h"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <Windows.h>


ConsoleBuffer::ConsoleBuffer()
{
	// get the default output handle
	console = GetStdHandle(STD_OUTPUT_HANDLE);

	// set up the buffer
	for (int i = 0; i < SCREEN_HEIGHT; i++)
	{
		for (int j = 0; j < SCREEN_WIDTH; j++)
		{
			cache[j][i] = buffer[j][i] = new Pixel();
		}
	}

	// paint it black
	reset();
}


ConsoleBuffer::~ConsoleBuffer()
{
	for (int i = 0; i < SCREEN_WIDTH; i++)
	{
		for (int j = 0; j < SCREEN_HEIGHT; j++)
		{
			buffer[i][j] = NULL;
			cache[i][j] = NULL;
		}
	}
}


void ConsoleBuffer::write(int x, int y, Pixel* pixel, bool forceRefresh)
{
	// respect screen boundaries
	if (x <0 || y < 0 || x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT) return;

	// if both foreground and background colors as magenta, the pixel is transparent
	if (pixel->bgColor == Color::MAGENTA && pixel->fgColor == Color::MAGENTA) return;

	// schedules pixel repaint
	buffer[x][y] = pixel;
}


void ConsoleBuffer::write(int x, int y, Sprite* sprite, bool flipX, bool flipY)
{
	int startX = flipX ? sprite->width - 1 : 0;
	int startY = flipY ? sprite->height - 1 : 0;

	for (int j = 0; j < (signed)sprite->width; j++)
	{
		for (int i = 0; i < (signed)sprite->height; i++)
		{
			write(x + j, y + i, &sprite->map[std::abs(startY - i)][std::abs(startX - j)]);
		}
	}
}


void ConsoleBuffer::write(int x, int y, std::string text, int fgColor, int bgColor)
{
	if (y >= SCREEN_HEIGHT) return;

	for (unsigned int i = 0; i < text.length(); i++)
	{
		if (x + i >= SCREEN_WIDTH) return;

		write(x + i, y, new Pixel(text[i], fgColor, bgColor));
	}
}


void ConsoleBuffer::writeCentered(std::string text, int fgColor, int bgColor)
{
	int x = (SCREEN_WIDTH - text.length()) / 2;
	int y = (int) SCREEN_HEIGHT / 2;

	write(x, y, text, fgColor, bgColor);
}


void ConsoleBuffer::writeCentered(Sprite* sprite)
{
	int x = (SCREEN_WIDTH - sprite->width) / 2;
	int y = (SCREEN_HEIGHT - sprite->height) / 2;

	write(x, y, sprite);
}

void ConsoleBuffer::forceRefresh(int fromX, int fromY, int toX, int toY)
{
	if (toX < 0) toX = fromX;
	if (toY < 0) toY = fromY;

	for (int i = fromY; i <= toY; i++) {
		for (int j = fromX; j <= toX; j++) {
			buffer[j][i]->forceRefresh = true;
		}
	}
}


void ConsoleBuffer::flush()
{
	for (int x = 0; x < SCREEN_WIDTH; x++)
	{
		for (int y = 0; y < SCREEN_HEIGHT; y++)
		{
			if (buffer[x][y]->forceRefresh || !cache[x][y]->equalsTo(buffer[x][y]))
			{
				cache[x][y] = buffer[x][y];
				cache[x][y]->forceRefresh = false;

				printAtCoord(x, y);
			}
		}
	}

	// puts the cursor outside the screen, to stop annoying
	printAtCoord(0, SCREEN_HEIGHT - 1);
}


void ConsoleBuffer::gotoCoord(int x, int y)
{
	SetConsoleCursorPosition(console, { x, y });
}


void ConsoleBuffer::printAtCoord(int x, int y)
{
	Pixel* pixel = buffer[x][y];

	int color = pixel->fgColor | pixel->bgColor << 4;

	SetConsoleTextAttribute(console, color);
	gotoCoord(x, y);
	printf("%c", pixel->value);
}

void ConsoleBuffer::reset()
{
	// ♫ I see a red door and I want to paint it black ♪
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, 0);
	std::cout << std::setw(2000) << ' ';
}