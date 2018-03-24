/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include <random>


struct Point
{
	int x;
	int y;
	Point(int _x, int _y): x(_x), y(_y){}
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
	Velocity() : vx((rand() % 2) - 1), vy((rand() % 2) - 1){}
	//int dx = (rand() % 2) - 1;
	//int dy = (rand() % 17) - 8;
};

struct Poo
{
	bool isEaten = false;
	Point location;
	Velocity velocity ;

	Rect rect = Rect(24, 24);
	//
	Poo(int x, int y) : location(x, y) {}
	//
	// move
	void RandomMove(Rect screen)
	{

		location.x = location.x + velocity.vx;
		if (location.x < 0)
		{
			location.x = 0;
			velocity.vx = 0 - velocity.vx;  // negate the velocity
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


};



struct Dude
{
	Point location;
	Rect rect;

	//---------
	Dude(int x, int y):location(x, y), rect(20,20) {}
	

	// move
	void move( Point dest)
	{	
		location = dest; 
	}

	// collision detection
	bool IsColliding(Poo poo) const
	{
		Point p = poo.location;
		Rect r = poo.rect;
		return location.x <= p.x + r.width
			&& location.x + rect.width >= p.x
			&& location.y <= p.y + r.height
			&& location.y + rect.height >= p.y;

	}
 

};



class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
	void DrawFace(int x, int y);
	void DrawPoo(int x, int y);

	int ClampScreenX(int x, int width);
	int ClampScreenY(int y, int height);
	
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	/********************************/

	Dude dude = Dude(400, 300);
	Poo poo0 = Poo(300,150);
	Poo poo1 = Poo(100, 500);
	Poo poo2 = Poo(600, 400);
};