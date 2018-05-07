
#include "Window.h"

#define TIMER1 1001

//Allow WindowProc to Draw on the window
HDC hdc;
PAINTSTRUCT ps;

//Create a new Snake Game for logic
Snake_Game * Snake = new Snake_Game();
//correspong which directionn you go 
char movement = ' ';
bool state_of_game = true; 
//game is good && and you havn't lose yet

long __stdcall WindowProc(HWND window, UINT msg, WPARAM wp, LPARAM lp)
{

	switch (msg)
	{

	//when the window is created
	case WM_CREATE:
	{
		SetTimer(window, TIMER1, 250, (TIMERPROC)NULL);
		//Sets a Timer to call WM_Timer every 250 millescodns or 1/4 a second
		cout << "Snake Game Created " << endl;
		break;
	}
	//When Invalidate is Called. RePaints Window. 
	case WM_PAINT:
	{
		//cout << "Painting Window" << endl;
		hdc = BeginPaint(window, &ps);
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 17; j++)
			{
				//j is x
				//i is y
				if (Snake->map_cordinate(i, j) == 0)
				{
					//does nothing if blank
				}
				else if (Snake->map_cordinate(i,j) == 1)
				{
					COLORREF Border = RGB(245, 245, 245); //Borders are Black
					HBRUSH Border_Black = CreateSolidBrush(Border);
					SelectObject(hdc, Border_Black);

					Rectangle(hdc, j*50,i*50,(j*50)+50,(i*50)+50);

					DeleteObject(Border_Black);

				}
				else if (Snake->map_cordinate(i, j) == 2)
				{
					COLORREF Snake = RGB(255, 0, 0); //snake is red
					HBRUSH Snake_Red = CreateSolidBrush(Snake);
					SelectObject(hdc, Snake_Red);

					//cout << i << j << endl;
					Ellipse(hdc, j * 50, i * 50, (j * 50) + 50, (i * 50) + 50);
					DeleteObject(Snake_Red);
				}

				else
				{
					COLORREF Food = RGB(0, 0, 255); //food is blue;
					HBRUSH Food_Blue = CreateSolidBrush(Food);
					//is food

					//have to declare vertices for triangles
					POINT vertices[] = {
						{ (j * 50) +25 , (i * 50) + 25 },
						{ (j * 50) , (i * 50) + 50 },
						{ (j*50) + 50 , (i * 50) + 50 }
					};

					SelectObject(hdc, Food_Blue);
					Polygon(hdc, vertices, sizeof(vertices) / sizeof(vertices[0]));
					DeleteObject(Food_Blue);
				}
			}
		}
		EndPaint(window, &ps);
		break;
	}
	case WM_DESTROY: //when x is closed 
	{
		cout << "Snake Game Closed" << endl;

		//Timer has to die
		KillTimer(window, TIMER1);
		PostQuitMessage(0);
		break;
	}
	//charector input
	case WM_CHAR:
	{
		switch (wp)
		{
		case 'w': //w key
			//cout << "W key has been pressed" << endl;
			movement = 'w';
			break;
		case 'a': //a key
			//cout << "A key has been pressed" << endl;
			movement = 'a';
			break;
		case 's': //s key
			//cout << "S key has been pressed" << endl;
			movement = 's';
			break;
		case 'd': //d key
			//cout << "D key has been pressed" << endl;
			movement = 'd';
			break;
		}
		break;
	}

	case WM_LBUTTONDOWN: //for left button down
	{
		int iPosX = LOWORD(lp);
		int iPosY = HIWORD(lp);
		Snake->mouse_x = (iPosX/50);
		Snake->mouse_y = (iPosY/50);
		Snake->mouse_clicked = true;
		msg = WM_CLOSE;
		break;
	}

	case WM_TIMER: //Every 1/4 of a second it moves the snake to the direction of movement
		if (state_of_game)
		{
			state_of_game = Snake->move(movement);
			InvalidateRect(window, NULL, TRUE);
		}
		break;
	}

	return DefWindowProc(window, msg, wp, lp);
}

Window::Window()
{

	//Initlilaizing the windows. 

	HINSTANCE hINSTANCE = (HINSTANCE)GetModuleHandle(NULL);
	snake_window = {};

	snake_window.cbSize = sizeof(WNDCLASSEX);
	snake_window.style = CS_DBLCLKS; //no close && no double click CS_NOCLOSE ||

	snake_window.lpfnWndProc = WindowProc;
	snake_window.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	snake_window.hInstance = hINSTANCE;
	snake_window.lpszClassName = window_class;
	RegisterClassEx(&snake_window);

	start_window();

}
void Window::start_window()
{

	hwnd = CreateWindowEx(
		0,
		window_class,
		"Snake_Game",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL,
		NULL,
		hINSTANCE,
		NULL);

	if (hwnd == NULL)
	{
		cout << "Window didn't work " << endl;
	}

	ShowWindow(hwnd, 1);

	MSG msg = {};
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}