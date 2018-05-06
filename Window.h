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

};

