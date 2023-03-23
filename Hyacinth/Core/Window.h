#pragma once

#include <string>
#include <Windows.h>
#pragma comment(lib, "opengl32.lib")

namespace Window
{
	HWND hWnd;
	HDC hdc;

	LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	void Create(int width, int height, std::string title)
	{
		WNDCLASS wc = { 0 };
		wc.lpfnWndProc = WndProc;
		wc.lpszClassName = "WndHyacinth";

		RegisterClass(&wc);

		RECT rect;
		rect.top = 100;
		rect.left = 100;
		rect.right = 100 + width;
		rect.bottom = 100 + height;

		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW | WS_VISIBLE, false);

		hWnd = CreateWindow(
			"WndHyacinth", title.c_str(),
			WS_OVERLAPPEDWINDOW | WS_VISIBLE,
			CW_USEDEFAULT, CW_USEDEFAULT,
			rect.right - rect.left, rect.bottom - rect.top,
			NULL, NULL, NULL, NULL
		);

		hdc = GetDC(hWnd);

		PIXELFORMATDESCRIPTOR pfd;
		ZeroMemory(&pfd, sizeof(pfd));
		pfd.nSize = sizeof(pfd);
		pfd.nVersion = 1;
		pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_DRAW_TO_BITMAP | PFD_SUPPORT_OPENGL | PFD_GENERIC_ACCELERATED | PFD_DOUBLEBUFFER | PFD_SWAP_LAYER_BUFFERS;
		pfd.iPixelType = PFD_TYPE_RGBA;
		pfd.cColorBits = 32;
		pfd.cRedBits = 8;
		pfd.cGreenBits = 8;
		pfd.cBlueBits = 8;
		pfd.cAlphaBits = 8;
		pfd.cDepthBits = 32;
		pfd.cStencilBits = 8;

		int pixelFormat = ChoosePixelFormat(hdc, &pfd);
		SetPixelFormat(hdc, pixelFormat, &pfd);

		HGLRC context = wglCreateContext(hdc);
		wglMakeCurrent(hdc, context);
	}

	bool GetEvents()
	{
		MSG msg;
		PeekMessage(&msg, 0, 0, 0, PM_REMOVE);
		if (msg.message == WM_CLOSE)
			return false;
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		return true;
	}

	void Present()
	{
		SwapBuffers(hdc);
	}
}