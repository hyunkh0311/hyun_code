#include "../header/ConsoleUtility.h"

ConsoleClass::ConsoleClass()
{

}

ConsoleClass::~ConsoleClass()
{

}

void ConsoleClass::gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void ConsoleClass::clear(float x, float y)
{
	gotoxy(x * 2, y);
	printf(" ");
}
void ConsoleClass::draw(int x, int y, const char *shape)
{
	gotoxy(x * 2, y);
	printf("%s",shape);
}