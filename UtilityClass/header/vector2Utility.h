#pragma once


class Vector2Class
{
public : 
	Vector2Class();
	Vector2Class(float _x, float _y);
	Vector2Class(float _x, float _y, float _prevX, float _prevY);
	~Vector2Class();

public:
	float x, y;
	float prevX, prevY;
private:

};