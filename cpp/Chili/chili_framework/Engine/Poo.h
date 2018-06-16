#pragma once

#include "MyCommon.h"
#include "Graphics.h"

class Poo
{

	bool eaten = false;
	bool initialized = false;
public:
	bool is_eaten() const
	{
		return eaten;
	}

	void set_eaten(bool eaten)
	{
		this->eaten = eaten;
	}

	Point location; 

	Velocity velocity;

	Rect rect = Rect(24, 24);
	//
	Poo();
	Poo(int x, int y);
	void init(int x, int y);
	//
	// move
	void RandomMove(Rect screen);

	void Draw(Graphics& gfx);
};



