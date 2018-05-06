#include "Snake.h"

int Snake_Game::map_cordinate(int i,int j)
{	
	return map[i][j];
}

void Snake_Game::move()
{
	if (snake_x.empty())
	{
		std::cout << "Empty should be called" << std::endl;
		snake_x.push_back(8);
		snake_y.push_back(4);
		map[snake_y[0]][snake_x[0]] = 2;
		//default
	}
	else
	{
		std::cout << "Not Empty should be called" << std::endl;
		snake_y.push_back(snake_y[0] + 1);
		snake_x.push_back(snake_x[0]);
		
		//for x
		map[snake_y.front()][snake_x.front()] = 0;
		snake_y.erase(snake_y.begin());
		snake_x.erase(snake_x.begin());
		map[snake_y[0]][snake_x[0]] = 2;


	}
}
