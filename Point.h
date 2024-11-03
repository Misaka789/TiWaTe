#pragma once
class Point
{
public:
	int x;
	int y;
	Point(int x, int y) :x(x), y(y) {};
	Point() { x = 500, y = 500; };
};