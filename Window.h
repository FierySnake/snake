#pragma once



#include <iostream>
#include <Windows.h>
#include <stdlib.h>

#include "Snake.h" 



using std::cout;
using std::cin;
using std::endl;

class Window
{

	public:
		Window();
		void start_window();
		


	private:
		HWND hwnd; //handle of this window
		WNDCLASSEX snake_window; //
		HINSTANCE hINSTANCE;

		char const window_class[11] = "Snake_Game";


		COLORREF Snake = RGB(255, 0, 0); //snake is red
		COLORREF Food = RGB(0, 0, 255); //food is blue;
		COLORREF Border = RGB(255, 255, 255); //Borders are Black;


};

