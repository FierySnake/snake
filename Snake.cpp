#include "Snake.h"

int Snake_Game::map_cordinate(int i,int j)
{	
	return map[i][j];
}

bool Snake_Game::move(char c)
{
	if (game_Over == true)
	{	
		std::cout << "Lul you lost " << std::endl;
		return false;
	}
	else
	{
		if (snake_x.empty())
		{
			srand(time(NULL)); //call for random

			//std::cout << "Empty should be called" << std::endl;
			snake_x.push_back(8);
			snake_y.push_back(4);
			map[snake_y[0]][snake_x[0]] = 2;
			//default

			up = true;
			left = true;
			right = true;
			down = true;

			food_respawn();
		}
		else if (c == 'w' && up != false)
		{
			check_collision(snake_x[0], snake_y[0] - 1);
			
			//disable down
			down = false;

			//allow left and right
			right = true;
			left = true;

		}
		else if (c == 'a'  && left != false)
		{
			check_collision(snake_x[0] - 1, snake_y[0]);

			right = false;

			up = true;
			down = true;

		}
		else if (c == 'd' && right != false)
		{
			check_collision(snake_x[0] + 1, snake_y[0]);

			left = false;

			up = true;
			down = true;

		}
		else if (c == 's' && down != false)
		{
			//check collisions first
			check_collision(snake_x[0], snake_y[0] + 1);

			//disable down
			up = false;

			//allow left and right
			right = true;
			left = true;

		}
		else if (win)
		{
			std::cout << "You have won Snake" << std::endl;
			return false; //stops game
		}
		else // user tries to go backwards
		{
			if (c == 's' && down == false)
			{
				check_collision(snake_x[0], snake_y[0] - 1);
			}
			else if (c == 'd' && right == false)
			{
				check_collision(snake_x[0] - 1, snake_y[0]);
			}
			else if (c == 'w' && up == false)
			{
				check_collision(snake_x[0], snake_y[0] + 1);
			}
			else if (c == 'a' && left == false)
			{
				check_collision(snake_x[0] + 1, snake_y[0]);
			}
			else
			{
				// do nothing
			}

		}
	}

}


void Snake_Game::check_collision(int x, int y)
{
	if (map[y][x] == 1)
	{
		std::cout << "You hit the wall " << std::endl;
		game_over();

	}
	else if (map[y][x] == 2)
	{
		std::cout << "You ate yourself " << std::endl;
		game_over();
	}
	else if (map[y][x] == 3)
	{
		snake_y.insert(snake_y.begin(), y);
		snake_x.insert(snake_x.begin(), x);


		for (int i = 0; i < snake_x.size(); i++)
		{
			//std::cout << x << y << std::endl;
			map[snake_y[i]][snake_x[i]] = 2;
		}

		food_respawn();
		food_eaten += 1;

		if (food_eaten == 144)
		{
			win = true;
		}

	}
	else
	{
		//takes location last visisted and pushed it into the back;
		snake_y.insert(snake_y.begin(), y);
		snake_x.insert(snake_x.begin(), x);

		map[snake_y.back()][snake_x.back()] = 0;

		snake_y.pop_back();
		snake_x.pop_back();

		for (int i = 0; i < snake_x.size(); i++)
		{
			map[snake_y[i]][snake_x[i]] = 2;
		}

	}
}

void Snake_Game::food_respawn()
{
	int rand_y;
	int rand_x;
	do
	{
		rand_x = 1 + rand() % 16;
		rand_y = 1 + rand() % 9;

	}while (map[rand_y][rand_x] != 0);

	//std::cout << rand_x << rand_y << std::endl;
	map[rand_y][rand_x] = 3;

}


void Snake_Game::game_over()
{
	std::cout << "You have eatan " << food_eaten << " fruits" << std::endl;
	game_Over = true;

}