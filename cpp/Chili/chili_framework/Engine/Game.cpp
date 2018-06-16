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
#include <random>

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	rng(rd()),
	x_Dist(0, 770),
	y_Dist(0, 570),
	dude(400, 300)
{

	for(int i=0; i<mPooNum; ++i)
	{
		mPoo[i] = Poo(x_Dist(rng), y_Dist(rng));
	}
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

	// draw rect
	gfx.DrawRect(100, 100, 200, 200, { 255, 255, 0 });

	int step = 3;
	int destX = dude.location().x;
	int destY = dude.location().y;
	// move
	if(wnd.kbd.KeyIsPressed(VK_UP))
	{
		destY -=step;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		destY +=step;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		destX-=step;
	}

	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		destX+=step;
	}
	destX = ClampScreenX(destX, dude.rect().width);
	destY = ClampScreenY(destY, dude.rect().height);
	dude.move(Point(destX, destY));


	for(int i=0; i<mPooNum; ++i)
	{
		if (!mPoo[i].is_eaten() && dude.IsColliding(mPoo[i]))
		{
			mPoo[i].set_eaten(true);
		}
	}

	
}


int Game::ClampScreenX(int x, int width)
{
	const int right = x + dude.rect().width;
	if(x<0)
	{
		return 0;
	}
	else if(right >= gfx.ScreenWidth)
	{
		return gfx.ScreenWidth - 1 - width;
	}
	else
	{
		return x;
	}
}

int Game::ClampScreenY(int y, int height)
{
	if(y<0)
	{
		return 0;
	}
	else if(y + height >= gfx.ScreenHeight)
	{
		return gfx.ScreenHeight - 1 - height;
	}
	else
	{
		return y;
	}
}

void Game::ComposeFrame()
{
	dude.Draw(gfx);
	for (int i = 0; i<mPooNum; ++i)
	{
		if (!mPoo[i].is_eaten()  )
		{
			mPoo[i].RandomMove(Rect(gfx.ScreenWidth, gfx.ScreenHeight));
			mPoo[i].Draw(gfx);
		}
	}


}
