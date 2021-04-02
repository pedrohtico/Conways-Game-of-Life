#pragma once

#include <allegro5/allegro_primitives.h>

class Cell
{
private:
	int x, y;
	bool alive = false;
public:
	Cell(double x, double y)
	{
		this->x = x;
		this->y = y;
	}

	void setAlive(bool isAlive)
	{
		if (isAlive) this->alive = true;
		else this->alive = false;
	}

	bool isAlive()
	{
		return alive;
	}

	void reverse()
	{
		alive = !alive;
	}

	void draw()
	{
		if (alive)
			al_draw_filled_rectangle(x*8, y*8, x*8 + 8, y*8 + 8, al_map_rgb_f(1, 1, 1));
	}

	int getX()
	{
		return this->x;
	}

	int getY()
	{
		return this->y;
	}
};

