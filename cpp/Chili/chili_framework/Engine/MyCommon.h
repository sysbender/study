#pragma once
#include <algorithm>
struct Point
{
	int x;
	int y;
	Point(int _x, int _y) : x(_x), y(_y) {}
};


struct Rect
{
	int width;
	int height;
	Rect(int w, int h) : width(w), height(h) {}
};

struct Velocity
{
	int vx;
	int vy;
	Velocity() : vx((rand() % 2) - 1), vy((rand() % 2) - 1) {}
	//int dx = (rand() % 2) - 1;
	//int dy = (rand() % 17) - 8;
};
