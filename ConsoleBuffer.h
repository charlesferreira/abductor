#pragma once

#include "Sprite.h"
#include "Config.h"
#include "Pixel.h"
#include <iostream>
#include <Windows.h>

class ConsoleBuffer
{
private:
	HANDLE console;
	Pixel* buffer[SCREEN_WIDTH][SCREEN_HEIGHT];
	Pixel* cache[SCREEN_WIDTH][SCREEN_HEIGHT];

public:
	void write(int x, int y, Sprite* sprite, bool flipX = false, bool flipY = false);
	void write(int x, int y, Pixel* pixel, bool forceRefresh = false);
	void write(int x, int y, std::string text, int fgColor, int bgColor);
	void writeCentered(std::string text, int fgColor, int bgColor);
	void writeCentered(Sprite* sprite);
	void forceRefresh(int fromX, int fromY, int toX = -1, int toY = -1);
	void flush();

	/*
	* Singleton example by Loki Astari on:
	* http://stackoverflow.com/questions/1008019/c-singleton-design-pattern
	* (Visited on Apr 14, 2015)
	*/
	static ConsoleBuffer& getInstance()
	{
		static ConsoleBuffer instance;
		return instance;
	}
private:
	ConsoleBuffer();
	~ConsoleBuffer();
	ConsoleBuffer(ConsoleBuffer const&) = delete;
	void operator=(ConsoleBuffer const&) = delete;

	void reset();
	void gotoCoord(int x, int y);
	void printAtCoord(int x, int y);
};
