/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"


template <typename T>
inline T const& Between(T const& a, T const& b, T const& c) {
	return a >= b && a <= c;
}

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	//const bool cond = wnd.kbd.KeyIsPressed(VK_UP);

	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		x_mobile++;
		if (inhibitRight) {

		}
		else {
			vx = vx + 1;
			inhibitRight = true;
		}


	}
	else 
	{
		inhibitRight = false;
	}

	// left
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		x_mobile--;
		if (inhibitLeft) 
		{

		}
		else
		{
			vx = vx - 1;
			inhibitLeft = true;
		}
		
	}
	else
	{
		inhibitLeft = false;
	}

	// down
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		y_mobile++;
		if (inhibitDown) 
		{

		}
		else
		{
			vy = vy + 1;
			inhibitDown = true;
		}

	}
	else
	{
		inhibitDown = false;
	}

	// up
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		y_mobile--;
		if (inhibitUp)
		{

		}
		else
		{
			vy = vy - 1;
			inhibitUp = true;
		}

	}
	else
	{
		inhibitUp = false;
	}


	//check colliding
	colliding = OverlapTest(x_fixed, y_fixed, x_mobile, y_mobile);
	 
	x = x + vx;
	y = y + vy;

	// check x, y
	if(x + 6 >= gfx.ScreenWidth)
	{
		x = gfx.ScreenWidth - 6;
		vx = 0;
	}
	if(x-6 <0)
	{
		x = 6;
		vx = 0;
	}

	if (y + 6 >= gfx.ScreenHeight)
	{
		y = gfx.ScreenHeight - 6;
		vy = 0;
	}
	if(y-6 <0)
	{
		y = 6;
		vy = 0;
	}

	//
	controlIsPressed = false;
	if(x>200 && x<300)
	{
		controlIsPressed = true;
	}


	shapeIsChanged = wnd.kbd.KeyIsPressed(VK_SHIFT);
 


	

}


void Game::DrawBox(int x_center, int y_center, int r, int g, int b)
{

	gfx.PutPixel(-5 + x_center, -5 + y_center, r, g, b);
	gfx.PutPixel(-5 + x_center, -4 + y_center, r, g, b);
	gfx.PutPixel(-5 + x_center, -3 + y_center, r, g, b);
	gfx.PutPixel(-4 + x_center, -5 + y_center, r, g, b);
	gfx.PutPixel(-3 + x_center, -5 + y_center, r, g, b);
	gfx.PutPixel(-5 + x_center,  5 + y_center, r, g, b);
	gfx.PutPixel(-5 + x_center,  4 + y_center, r, g, b);
	gfx.PutPixel(-5 + x_center,  3 + y_center, r, g, b);
	gfx.PutPixel(-4 + x_center,  5 + y_center, r, g, b);
	gfx.PutPixel(-3 + x_center,  5 + y_center, r, g, b);

	gfx.PutPixel( 5 + x_center, -5 + y_center, r, g, b);
	gfx.PutPixel( 5 + x_center, -4 + y_center, r, g, b);
	gfx.PutPixel( 5 + x_center, -3 + y_center, r, g, b);
	gfx.PutPixel( 4 + x_center, -5 + y_center, r, g, b);
	gfx.PutPixel( 3 + x_center, -5 + y_center, r, g, b);
	gfx.PutPixel( 5 + x_center,  5 + y_center, r, g, b);
	gfx.PutPixel( 5 + x_center,  4 + y_center, r, g, b);
	gfx.PutPixel( 5 + x_center,  3 + y_center, r, g, b);
	gfx.PutPixel( 4 + x_center,  5 + y_center, r, g, b);
	gfx.PutPixel( 3 + x_center,  5 + y_center, r, g, b);

}

bool Game::OverlapTest(int xa, int ya, int xb, int yb)
{
	return xa - 5 <= xb + 5
		&& xb - 5 <= xa + 5
		&& ya - 5 <= yb + 5
		&& yb - 5 <= ya + 5;
	 
}
 

void Game::ComposeFrame()
{

	// draw box fix
	DrawBox(x_fixed, y_fixed, 0, 255, 0);

	// draw box 
	if(colliding)
	{
		DrawBox(x_mobile, y_mobile, 255, 0, 0);
	}
	else
	{
		DrawBox(x_mobile, y_mobile, 255, 255, 255);
	}

	//{

	//	gfx.PutPixel(x - 2, y, 255, gb, gb);
	//	gfx.PutPixel(x - 1, y, 255, gb, gb);

	//	gfx.PutPixel(x, y - 2, 255, gb, gb);
	//	gfx.PutPixel(x, y - 1, 255, gb, gb);
	//	//gfx.PutPixel(x+2   , y, 255, 255, 255);
	//	gfx.PutPixel(x, y+1, 255, gb, gb);
	//	gfx.PutPixel(x, y+2, 255, gb, gb);

	//	gfx.PutPixel(x + 1, y , 255, gb, gb);
	//	gfx.PutPixel(x + 2, y , 255, gb, gb);
	//}

}
