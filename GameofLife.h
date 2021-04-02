#pragma once

#include "Cell.h"
#include <vector>
#include <cstdlib>
#include <ctime>

class GameofLife
{
private:
	std::vector<Cell> cells;
	int width, height;
public:
	GameofLife(int width, int height)
	{
		this->width = width;
		this->height = height;

		srand(time(0));
		for (int i = 0; i < width*height; i++)
		{
			Cell cell(i % width, int (i / width));
			cell.setAlive((float) rand() / RAND_MAX < 0.1 ? true : false);
			cells.push_back(cell);
		}
	}

	int neighbors(Cell c)
	{
		int count = 0;
		for (int i = c.getX() - 1; i < c.getX() + 2; i++)
			if (i >= 0 && i < width)
				for (int j = c.getY() - 1; j < c.getY() + 2; j++)
					if (j >= 0 && j < height && !(c.getX() == i && c.getY() == j))
					{
						int k = i + j * this->width;
						if (cells[k].isAlive())
							count++;
					}

		return count;
	}

	void update()
	{
		std::vector<int> aux;
		int i = 0;
		for (Cell c : cells)
		{
			int n = neighbors(c);
			if (c.isAlive())
			{
				if (n != 2 && n != 3)
					aux.push_back(i);
			} else if (n == 3)
				aux.push_back(i);
			i++;
		}
		
		for (int num : aux)
			cells[num].reverse();
	}

	void draw()
	{
		for (Cell c : cells)
			c.draw();
	}
};
