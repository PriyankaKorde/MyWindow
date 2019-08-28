//Headers
#include<windows.h>

//global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	//variable declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	Char AppName[] ="Windows";

	//code
	//initialization of WNDCLASSEX
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszClassName = AppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);


	//register above class
	RegisterClassEx(&wndclass);


	// create window
	hwnd = CreateWindow(AppName, "SaGaR's First Window", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	//message loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return(msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//code
	switch (iMsg)
	{
	 case WM_CREATE:
		MessageBox() (hwnd,"WM_CREATE message is sent","Messages",MB_OK);
		break;

	 case WM_MOVE:
		 MessageBox() (hwnd, "WM_MOVE message is sent", "Messages", MB_OK);
		 break;

	 case WM_SIZE:
		 MessageBox() (hwnd, "WM_SIZE message is sent", "Messages", MB_OK);
		 break;

	 case WM_KEYDOWN:
		 MessageBox() (hwnd, "WM_KEYDOWN message is sent", "Messages", MB_OK);
		 break;

	 case WM_LBUTTONDOWN:
		 MessageBox() (hwnd, "WM_LBUTTONDOWN message is sent", "Messages", MB_OK);
		 break;

	 case WM_DESTROY:
		 PostQuitMessage(0);
		 break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}