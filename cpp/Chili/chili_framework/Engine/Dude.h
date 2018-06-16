#pragma once
#include "MyCommon.h"
#include "Graphics.h"
#include "Poo.h"
class Dude
{
private:
	Point mLocation;
	Rect mRect;

	public:

	Point location()
	{
		return mLocation;
	}

	void location(Point pLocation)
	{
		mLocation = pLocation;
	}

	Rect rect()
	{
		return mRect;
	}

	void rect(Rect pRect)
	{
		mRect = pRect;
	}

	//---------
	Dude(int x, int y);


	// move
	void move(Point dest);

	// collision detection
	bool IsColliding(Poo poo) const;
	void Draw(Graphics & gfx);
};

