#include "../header/vector2Utility.h"

Vector2Class::Vector2Class()
{
	x = 0;
	y = 0;
	prevX = 0;
	prevY = 0;
}

Vector2Class::Vector2Class(float _x, float _y)
{
	x = _x;
	y = _y;
	prevX = 0;
	prevY = 0;
}
Vector2Class::Vector2Class(float _x, float _y, float _prevX, float _prevY)
{
	x = _x;
	y = _y;
	prevX = _prevX;
	prevY = _prevX;
}

Vector2Class::~Vector2Class()
{

}
