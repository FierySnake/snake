#pragma once

#include <iostream>
#include <Windows.h>

//logic
//how to end = if snake touch wall or itself
//each food gives +3 lenght; 





class Snake_Game
{

	public:
		int map_cordinate(int i,int j);
		void move();
		void check_colliion();
		void game_over();
		void food_respawn();
		


	private:

		int map[10][17] =
		{
			1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
			1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
			1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		};

		int snake_x[130];
		int snake_y[130];

		bool up;
		bool down;
		bool left;
		bool right;
		
		bool food_eaten;
		bool snake_ate_himself;
		bool snake_touched_border;


		int fruit_x;
		int fruit_y;

		COLORREF Snake = RGB(255, 0, 0); //snake is red
		COLORREF Food = RGB(0, 0, 255); //food is blue;
		COLORREF Border = RGB(255, 255, 255); //Borders are Black;






};