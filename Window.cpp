
#include "Window.h"

HDC hdc;
PAINTSTRUCT ps;
Snake_Game * Snake = new Snake_Game();

long __stdcall WindowProc(HWND window, UINT msg, WPARAM wp, LPARAM lp)
{

	switch (msg)
	{
	//when the window is created
	case WM_CREATE:
	{
		cout << "Snake Game Created " << endl;
		break;
	}
	case WM_PAINT:
	{
		hdc = BeginPaint(window, &ps);
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 17; j++)
			{
				//j is x
				//i is y
				if (Snake->map_cordinate(i,j) == 1)
				{
					Rectangle(hdc, j*50,i*50,(j*50)+50,(i*50)+50);	
				}
				if (Snake->map_cordinate(i, j) == 2)
				{
					cout << i << j << endl;
					Ellipse(hdc, j * 50, i * 50, (j * 50) + 50, (i * 50) + 50);
				}
			}
		}
		EndPaint(window, &ps);
		break;
	}
	case WM_DESTROY: //when x is closed 
	{
		cout << "Snake Game Closed" << endl;
		PostQuitMessage(0);
		break;
	}
	//charector input
	case WM_CHAR:
	{
		switch (wp)
		{
		case 'w': //w key
			cout << "W key has been pressed" << endl;
			Snake->move();
			InvalidateRgn(window, NULL, TRUE);

			break;
		case 'a': //a key
			cout << "A key has been pressed" << endl;
			break;
		case 's': //s key
			cout << "S key has been pressed" << endl;
			break;
		case 'd': //d key
			cout << "D key has been pressed" << endl;
			break;
		}
		break;
	}

	case WM_LBUTTONDOWN: //for left button down
	{
		int iPosX = LOWORD(lp);
		int iPosY = HIWORD(lp);
		Snake->mouse_x = iPosX;
		Snake->mouse_y = iPosY;
		Snake->mouse_clicked = true;
		break;
	}


	}


	return DefWindowProc(window, msg, wp, lp);
}

Window::Window()
{

	HINSTANCE hINSTANCE = (HINSTANCE)GetModuleHandle(NULL);
	snake_window = {};

	snake_window.cbSize = sizeof(WNDCLASSEX);
	snake_window.style = CS_DBLCLKS; //no close && no double click CS_NOCLOSE ||

	snake_window.lpfnWndProc = WindowProc;
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
		"First Window",
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
		UpdateWindow(hwnd);
	}
}