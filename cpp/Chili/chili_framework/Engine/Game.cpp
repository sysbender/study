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


	x = x + vx;
	y = y + vy;
	shapeIsChanged = wnd.kbd.KeyIsPressed(VK_SHIFT);
 


	

}

void Game::ComposeFrame()
{

	

	{

		gfx.PutPixel(x - 2, y, 255, gb, gb);
		gfx.PutPixel(x - 1, y, 255, gb, gb);

		gfx.PutPixel(x, y - 2, 255, gb, gb);
		gfx.PutPixel(x, y - 1, 255, gb, gb);
		//gfx.PutPixel(x+2   , y, 255, 255, 255);
		gfx.PutPixel(x, y+1, 255, gb, gb);
		gfx.PutPixel(x, y+2, 255, gb, gb);

		gfx.PutPixel(x + 1, y , 255, gb, gb);
		gfx.PutPixel(x + 2, y , 255, gb, gb);
	}

}
