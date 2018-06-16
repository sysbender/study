#include "Poo.h"
#include <cassert>

Poo::Poo() : location(0, 0)
{
	
}

Poo::Poo(int x, int y) : location(x, y)
{
}

void Poo::init(int px, int py)
{
	assert( initialized == false);
	location.x = px;
	location.y = py;
	initialized = true;
}

void Poo::RandomMove(Rect screen)
{
	location.x = location.x + velocity.vx;
	if (location.x < 0)
	{
		location.x = 0;
		velocity.vx = 0 - velocity.vx; // negate the velocity
	}

	if (location.x >= screen.width - rect.width)
	{
		location.x = screen.width - 1 - rect.width;
		velocity.vx = 0 - velocity.vx;
	}

	location.y = location.y + velocity.vy;
	if (location.y < 0)
	{
		location.y = 0;
		velocity.vy = 0 - velocity.vy;
	}
	if (location.y > screen.height - 1 - rect.height)
	{
		location.y = screen.height - 1 - rect.height;
		velocity.vy = 0 - velocity.vy;
	}
}

void Poo::Draw(Graphics& gfx)
{
	gfx.PutPixel(14 + location.x, 0 + location.y, 138, 77, 0);
	gfx.PutPixel(7 + location.x, 1 + location.y, 138, 77, 0);
	gfx.PutPixel(13 + location.x, 1 + location.y, 138, 77, 0);
	gfx.PutPixel(20 + location.x, 1 + location.y, 138, 77, 0);
	gfx.PutPixel(6 + location.x, 2 + location.y, 138, 77, 0);
	gfx.PutPixel(13 + location.x, 2 + location.y, 138, 77, 0);
	gfx.PutPixel(20 + location.x, 2 + location.y, 138, 77, 0);
	gfx.PutPixel(6 + location.x, 3 + location.y, 138, 77, 0);
	gfx.PutPixel(6 + location.x, 4 + location.y, 138, 77, 0);
	gfx.PutPixel(14 + location.x, 4 + location.y, 138, 77, 0);
	gfx.PutPixel(21 + location.x, 4 + location.y, 138, 77, 0);
	gfx.PutPixel(7 + location.x, 5 + location.y, 138, 77, 0);
	gfx.PutPixel(13 + location.x, 5 + location.y, 138, 77, 0);
	gfx.PutPixel(21 + location.x, 5 + location.y, 138, 77, 0);
	gfx.PutPixel(7 + location.x, 6 + location.y, 138, 77, 0);
	gfx.PutPixel(20 + location.x, 6 + location.y, 138, 77, 0);
	gfx.PutPixel(6 + location.x, 7 + location.y, 138, 77, 0);
	gfx.PutPixel(14 + location.x, 7 + location.y, 51, 28, 0);
	gfx.PutPixel(15 + location.x, 7 + location.y, 51, 28, 0);
	gfx.PutPixel(20 + location.x, 7 + location.y, 138, 77, 0);
	gfx.PutPixel(12 + location.x, 8 + location.y, 51, 28, 0);
	gfx.PutPixel(13 + location.x, 8 + location.y, 51, 28, 0);
	gfx.PutPixel(14 + location.x, 8 + location.y, 51, 28, 0);
	gfx.PutPixel(7 + location.x, 9 + location.y, 138, 77, 0);
	gfx.PutPixel(11 + location.x, 9 + location.y, 51, 28, 0);
	gfx.PutPixel(12 + location.x, 9 + location.y, 102, 57, 0);
	gfx.PutPixel(13 + location.x, 9 + location.y, 138, 77, 0);
	gfx.PutPixel(14 + location.x, 9 + location.y, 138, 77, 0);
	gfx.PutPixel(15 + location.x, 9 + location.y, 51, 28, 0);
	gfx.PutPixel(21 + location.x, 9 + location.y, 138, 77, 0);
	gfx.PutPixel(10 + location.x, 10 + location.y, 51, 28, 0);
	gfx.PutPixel(11 + location.x, 10 + location.y, 51, 28, 0);
	gfx.PutPixel(12 + location.x, 10 + location.y, 102, 57, 0);
	gfx.PutPixel(13 + location.x, 10 + location.y, 138, 77, 0);
	gfx.PutPixel(14 + location.x, 10 + location.y, 138, 77, 0);
	gfx.PutPixel(15 + location.x, 10 + location.y, 51, 28, 0);
	gfx.PutPixel(20 + location.x, 10 + location.y, 138, 77, 0);
	gfx.PutPixel(9 + location.x, 11 + location.y, 51, 28, 0);
	gfx.PutPixel(10 + location.x, 11 + location.y, 138, 77, 0);
	gfx.PutPixel(11 + location.x, 11 + location.y, 138, 77, 0);
	gfx.PutPixel(12 + location.x, 11 + location.y, 51, 28, 0);
	gfx.PutPixel(13 + location.x, 11 + location.y, 51, 28, 0);
	gfx.PutPixel(14 + location.x, 11 + location.y, 51, 28, 0);
	gfx.PutPixel(15 + location.x, 11 + location.y, 51, 28, 0);
	gfx.PutPixel(16 + location.x, 11 + location.y, 51, 28, 0);
	gfx.PutPixel(9 + location.x, 12 + location.y, 51, 28, 0);
	gfx.PutPixel(10 + location.x, 12 + location.y, 138, 77, 0);
	gfx.PutPixel(11 + location.x, 12 + location.y, 138, 77, 0);
	gfx.PutPixel(12 + location.x, 12 + location.y, 111, 62, 0);
	gfx.PutPixel(13 + location.x, 12 + location.y, 102, 57, 0);
	gfx.PutPixel(14 + location.x, 12 + location.y, 102, 57, 0);
	gfx.PutPixel(15 + location.x, 12 + location.y, 102, 57, 0);
	gfx.PutPixel(16 + location.x, 12 + location.y, 51, 28, 0);
	gfx.PutPixel(9 + location.x, 13 + location.y, 51, 28, 0);
	gfx.PutPixel(10 + location.x, 13 + location.y, 109, 61, 0);
	gfx.PutPixel(11 + location.x, 13 + location.y, 138, 77, 0);
	gfx.PutPixel(12 + location.x, 13 + location.y, 138, 77, 0);
	gfx.PutPixel(13 + location.x, 13 + location.y, 138, 77, 0);
	gfx.PutPixel(14 + location.x, 13 + location.y, 138, 77, 0);
	gfx.PutPixel(15 + location.x, 13 + location.y, 138, 77, 0);
	gfx.PutPixel(16 + location.x, 13 + location.y, 51, 28, 0);
	gfx.PutPixel(5 + location.x, 14 + location.y, 51, 28, 0);
	gfx.PutPixel(7 + location.x, 14 + location.y, 51, 28, 0);
	gfx.PutPixel(8 + location.x, 14 + location.y, 51, 28, 0);
	gfx.PutPixel(9 + location.x, 14 + location.y, 51, 28, 0);
	gfx.PutPixel(10 + location.x, 14 + location.y, 51, 28, 0);
	gfx.PutPixel(11 + location.x, 14 + location.y, 138, 77, 0);
	gfx.PutPixel(12 + location.x, 14 + location.y, 138, 77, 0);
	gfx.PutPixel(13 + location.x, 14 + location.y, 138, 77, 0);
	gfx.PutPixel(14 + location.x, 14 + location.y, 138, 77, 0);
	gfx.PutPixel(15 + location.x, 14 + location.y, 138, 77, 0);
	gfx.PutPixel(16 + location.x, 14 + location.y, 51, 28, 0);
	gfx.PutPixel(4 + location.x, 15 + location.y, 51, 28, 0);
	gfx.PutPixel(5 + location.x, 15 + location.y, 138, 77, 0);
	gfx.PutPixel(6 + location.x, 15 + location.y, 51, 28, 0);
	gfx.PutPixel(7 + location.x, 15 + location.y, 116, 65, 0);
	gfx.PutPixel(8 + location.x, 15 + location.y, 138, 77, 0);
	gfx.PutPixel(9 + location.x, 15 + location.y, 138, 77, 0);
	gfx.PutPixel(10 + location.x, 15 + location.y, 138, 77, 0);
	gfx.PutPixel(11 + location.x, 15 + location.y, 51, 28, 0);
	gfx.PutPixel(12 + location.x, 15 + location.y, 51, 28, 0);
	gfx.PutPixel(13 + location.x, 15 + location.y, 51, 28, 0);
	gfx.PutPixel(14 + location.x, 15 + location.y, 51, 28, 0);
	gfx.PutPixel(15 + location.x, 15 + location.y, 51, 28, 0);
	gfx.PutPixel(16 + location.x, 15 + location.y, 51, 28, 0);
	gfx.PutPixel(17 + location.x, 15 + location.y, 51, 28, 0);
	gfx.PutPixel(18 + location.x, 15 + location.y, 51, 28, 0);
	gfx.PutPixel(1 + location.x, 16 + location.y, 51, 28, 0);
	gfx.PutPixel(2 + location.x, 16 + location.y, 51, 28, 0);
	gfx.PutPixel(3 + location.x, 16 + location.y, 51, 28, 0);
	gfx.PutPixel(4 + location.x, 16 + location.y, 51, 28, 0);
	gfx.PutPixel(5 + location.x, 16 + location.y, 138, 77, 0);
	gfx.PutPixel(6 + location.x, 16 + location.y, 51, 28, 0);
	gfx.PutPixel(7 + location.x, 16 + location.y, 116, 65, 0);
	gfx.PutPixel(8 + location.x, 16 + location.y, 138, 77, 0);
	gfx.PutPixel(9 + location.x, 16 + location.y, 138, 77, 0);
	gfx.PutPixel(10 + location.x, 16 + location.y, 138, 77, 0);
	gfx.PutPixel(11 + location.x, 16 + location.y, 138, 77, 0);
	gfx.PutPixel(12 + location.x, 16 + location.y, 138, 77, 0);
	gfx.PutPixel(13 + location.x, 16 + location.y, 109, 61, 0);
	gfx.PutPixel(14 + location.x, 16 + location.y, 51, 28, 0);
	gfx.PutPixel(15 + location.x, 16 + location.y, 138, 77, 0);
	gfx.PutPixel(16 + location.x, 16 + location.y, 138, 77, 0);
	gfx.PutPixel(17 + location.x, 16 + location.y, 138, 77, 0);
	gfx.PutPixel(18 + location.x, 16 + location.y, 123, 69, 0);
	gfx.PutPixel(19 + location.x, 16 + location.y, 51, 28, 0);
	gfx.PutPixel(0 + location.x, 17 + location.y, 51, 28, 0);
	gfx.PutPixel(1 + location.x, 17 + location.y, 87, 49, 0);
	gfx.PutPixel(2 + location.x, 17 + location.y, 87, 49, 0);
	gfx.PutPixel(3 + location.x, 17 + location.y, 87, 49, 0);
	gfx.PutPixel(4 + location.x, 17 + location.y, 87, 49, 0);
	gfx.PutPixel(5 + location.x, 17 + location.y, 51, 28, 0);
	gfx.PutPixel(6 + location.x, 17 + location.y, 51, 28, 0);
	gfx.PutPixel(7 + location.x, 17 + location.y, 43, 24, 0);
	gfx.PutPixel(8 + location.x, 17 + location.y, 51, 28, 0);
	gfx.PutPixel(9 + location.x, 17 + location.y, 51, 28, 0);
	gfx.PutPixel(10 + location.x, 17 + location.y, 51, 28, 0);
	gfx.PutPixel(11 + location.x, 17 + location.y, 51, 28, 0);
	gfx.PutPixel(12 + location.x, 17 + location.y, 51, 28, 0);
	gfx.PutPixel(13 + location.x, 17 + location.y, 40, 22, 0);
	gfx.PutPixel(14 + location.x, 17 + location.y, 51, 28, 0);
	gfx.PutPixel(15 + location.x, 17 + location.y, 138, 77, 0);
	gfx.PutPixel(16 + location.x, 17 + location.y, 138, 77, 0);
	gfx.PutPixel(17 + location.x, 17 + location.y, 138, 77, 0);
	gfx.PutPixel(18 + location.x, 17 + location.y, 123, 69, 0);
	gfx.PutPixel(19 + location.x, 17 + location.y, 51, 28, 0);
	gfx.PutPixel(0 + location.x, 18 + location.y, 51, 28, 0);
	gfx.PutPixel(1 + location.x, 18 + location.y, 138, 77, 0);
	gfx.PutPixel(2 + location.x, 18 + location.y, 138, 77, 0);
	gfx.PutPixel(3 + location.x, 18 + location.y, 138, 77, 0);
	gfx.PutPixel(4 + location.x, 18 + location.y, 138, 77, 0);
	gfx.PutPixel(5 + location.x, 18 + location.y, 51, 28, 0);
	gfx.PutPixel(6 + location.x, 18 + location.y, 51, 28, 0);
	gfx.PutPixel(7 + location.x, 18 + location.y, 51, 28, 0);
	gfx.PutPixel(8 + location.x, 18 + location.y, 51, 28, 0);
	gfx.PutPixel(9 + location.x, 18 + location.y, 51, 28, 0);
	gfx.PutPixel(10 + location.x, 18 + location.y, 51, 28, 0);
	gfx.PutPixel(11 + location.x, 18 + location.y, 51, 28, 0);
	gfx.PutPixel(12 + location.x, 18 + location.y, 51, 28, 0);
	gfx.PutPixel(13 + location.x, 18 + location.y, 51, 28, 0);
	gfx.PutPixel(14 + location.x, 18 + location.y, 51, 28, 0);
	gfx.PutPixel(15 + location.x, 18 + location.y, 138, 77, 0);
	gfx.PutPixel(16 + location.x, 18 + location.y, 138, 77, 0);
	gfx.PutPixel(17 + location.x, 18 + location.y, 138, 77, 0);
	gfx.PutPixel(18 + location.x, 18 + location.y, 123, 69, 0);
	gfx.PutPixel(19 + location.x, 18 + location.y, 51, 28, 0);
	gfx.PutPixel(20 + location.x, 18 + location.y, 51, 28, 0);
	gfx.PutPixel(21 + location.x, 18 + location.y, 51, 28, 0);
	gfx.PutPixel(22 + location.x, 18 + location.y, 51, 28, 0);
	gfx.PutPixel(0 + location.x, 19 + location.y, 51, 28, 0);
	gfx.PutPixel(1 + location.x, 19 + location.y, 138, 77, 0);
	gfx.PutPixel(2 + location.x, 19 + location.y, 138, 77, 0);
	gfx.PutPixel(3 + location.x, 19 + location.y, 138, 77, 0);
	gfx.PutPixel(4 + location.x, 19 + location.y, 138, 77, 0);
	gfx.PutPixel(5 + location.x, 19 + location.y, 51, 28, 0);
	gfx.PutPixel(6 + location.x, 19 + location.y, 138, 77, 0);
	gfx.PutPixel(7 + location.x, 19 + location.y, 138, 77, 0);
	gfx.PutPixel(8 + location.x, 19 + location.y, 138, 77, 0);
	gfx.PutPixel(9 + location.x, 19 + location.y, 138, 77, 0);
	gfx.PutPixel(10 + location.x, 19 + location.y, 138, 77, 0);
	gfx.PutPixel(11 + location.x, 19 + location.y, 138, 77, 0);
	gfx.PutPixel(12 + location.x, 19 + location.y, 138, 77, 0);
	gfx.PutPixel(13 + location.x, 19 + location.y, 138, 77, 0);
	gfx.PutPixel(14 + location.x, 19 + location.y, 138, 77, 0);
	gfx.PutPixel(15 + location.x, 19 + location.y, 138, 77, 0);
	gfx.PutPixel(16 + location.x, 19 + location.y, 138, 77, 0);
	gfx.PutPixel(17 + location.x, 19 + location.y, 138, 77, 0);
	gfx.PutPixel(18 + location.x, 19 + location.y, 123, 69, 0);
	gfx.PutPixel(19 + location.x, 19 + location.y, 51, 28, 0);
	gfx.PutPixel(20 + location.x, 19 + location.y, 138, 77, 0);
	gfx.PutPixel(21 + location.x, 19 + location.y, 138, 77, 0);
	gfx.PutPixel(22 + location.x, 19 + location.y, 65, 36, 0);
	gfx.PutPixel(23 + location.x, 19 + location.y, 51, 28, 0);
	gfx.PutPixel(1 + location.x, 20 + location.y, 51, 28, 0);
	gfx.PutPixel(2 + location.x, 20 + location.y, 51, 28, 0);
	gfx.PutPixel(3 + location.x, 20 + location.y, 51, 28, 0);
	gfx.PutPixel(4 + location.x, 20 + location.y, 51, 28, 0);
	gfx.PutPixel(5 + location.x, 20 + location.y, 51, 28, 0);
	gfx.PutPixel(6 + location.x, 20 + location.y, 138, 77, 0);
	gfx.PutPixel(7 + location.x, 20 + location.y, 138, 77, 0);
	gfx.PutPixel(8 + location.x, 20 + location.y, 138, 77, 0);
	gfx.PutPixel(9 + location.x, 20 + location.y, 138, 77, 0);
	gfx.PutPixel(10 + location.x, 20 + location.y, 138, 77, 0);
	gfx.PutPixel(11 + location.x, 20 + location.y, 138, 77, 0);
	gfx.PutPixel(12 + location.x, 20 + location.y, 138, 77, 0);
	gfx.PutPixel(13 + location.x, 20 + location.y, 138, 77, 0);
	gfx.PutPixel(14 + location.x, 20 + location.y, 138, 77, 0);
	gfx.PutPixel(15 + location.x, 20 + location.y, 138, 77, 0);
	gfx.PutPixel(16 + location.x, 20 + location.y, 138, 77, 0);
	gfx.PutPixel(17 + location.x, 20 + location.y, 138, 77, 0);
	gfx.PutPixel(18 + location.x, 20 + location.y, 123, 69, 0);
	gfx.PutPixel(19 + location.x, 20 + location.y, 51, 28, 0);
	gfx.PutPixel(20 + location.x, 20 + location.y, 138, 77, 0);
	gfx.PutPixel(21 + location.x, 20 + location.y, 138, 77, 0);
	gfx.PutPixel(22 + location.x, 20 + location.y, 65, 36, 0);
	gfx.PutPixel(23 + location.x, 20 + location.y, 51, 28, 0);
	gfx.PutPixel(0 + location.x, 21 + location.y, 51, 28, 0);
	gfx.PutPixel(1 + location.x, 21 + location.y, 138, 77, 0);
	gfx.PutPixel(2 + location.x, 21 + location.y, 138, 77, 0);
	gfx.PutPixel(3 + location.x, 21 + location.y, 138, 77, 0);
	gfx.PutPixel(4 + location.x, 21 + location.y, 138, 77, 0);
	gfx.PutPixel(5 + location.x, 21 + location.y, 138, 77, 0);
	gfx.PutPixel(6 + location.x, 21 + location.y, 51, 28, 0);
	gfx.PutPixel(7 + location.x, 21 + location.y, 51, 28, 0);
	gfx.PutPixel(8 + location.x, 21 + location.y, 51, 28, 0);
	gfx.PutPixel(9 + location.x, 21 + location.y, 51, 28, 0);
	gfx.PutPixel(10 + location.x, 21 + location.y, 51, 28, 0);
	gfx.PutPixel(11 + location.x, 21 + location.y, 51, 28, 0);
	gfx.PutPixel(12 + location.x, 21 + location.y, 51, 28, 0);
	gfx.PutPixel(13 + location.x, 21 + location.y, 51, 28, 0);
	gfx.PutPixel(14 + location.x, 21 + location.y, 51, 28, 0);
	gfx.PutPixel(15 + location.x, 21 + location.y, 51, 28, 0);
	gfx.PutPixel(16 + location.x, 21 + location.y, 51, 28, 0);
	gfx.PutPixel(17 + location.x, 21 + location.y, 51, 28, 0);
	gfx.PutPixel(18 + location.x, 21 + location.y, 51, 28, 0);
	gfx.PutPixel(20 + location.x, 21 + location.y, 51, 28, 0);
	gfx.PutPixel(21 + location.x, 21 + location.y, 51, 28, 0);
	gfx.PutPixel(22 + location.x, 21 + location.y, 51, 28, 0);
	gfx.PutPixel(0 + location.x, 22 + location.y, 51, 28, 0);
	gfx.PutPixel(1 + location.x, 22 + location.y, 65, 36, 0);
	gfx.PutPixel(2 + location.x, 22 + location.y, 65, 36, 0);
	gfx.PutPixel(3 + location.x, 22 + location.y, 65, 36, 0);
	gfx.PutPixel(4 + location.x, 22 + location.y, 65, 36, 0);
	gfx.PutPixel(5 + location.x, 22 + location.y, 65, 36, 0);
	gfx.PutPixel(6 + location.x, 22 + location.y, 51, 28, 0);
	gfx.PutPixel(1 + location.x, 23 + location.y, 51, 28, 0);
	gfx.PutPixel(2 + location.x, 23 + location.y, 51, 28, 0);
	gfx.PutPixel(3 + location.x, 23 + location.y, 51, 28, 0);
	gfx.PutPixel(4 + location.x, 23 + location.y, 51, 28, 0);
	gfx.PutPixel(5 + location.x, 23 + location.y, 51, 28, 0);
	gfx.PutPixel(6 + location.x, 23 + location.y, 51, 28, 0);
}