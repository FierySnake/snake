#pragma once

#include <iostream>
#include <Windows.h>
#include <vector>

#include <time.h>
#include <stdlib.h>


using std::vector;

//logic
//how to end = if snake touch wall or itself
//each food gives +3 lenght; 





class Snake_Game
{

	public:
		int map_cordinate(int i,int j);
		bool move(char x);
		void check_collision(int x, int y);
		void game_over();
		void food_respawn();
	

		int mouse_x;
		int mouse_y;
		bool mouse_clicked;


	private:

		int map[10][17] =
		{
			1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
			1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
			1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		};

		vector<int> snake_x;
		vector<int> snake_y;

		bool up;
		bool down;
		bool left;
		bool right;
		
		bool game_Over = false;
		int food_eaten = 0;

		bool win = false;





};