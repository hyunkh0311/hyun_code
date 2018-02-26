#pragma once
#include <conio.h>
#include <Windows.h>
#include <stdio.h>

class ConsoleClass {
public:
	ConsoleClass();
	~ConsoleClass();
	
public:
//	int pointX;
//	int pointY;

	void gotoxy(int x, int y);
	void clear(float x, float y);
	void draw(int x, int y, const char *shape);
};