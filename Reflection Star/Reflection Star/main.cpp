#include <windows.h>
#include <mmsystem.h>
#include <tchar.h>
#include <locale.h>

namespace window
{
	const int Width = 1280;
	const int Height = 720;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);

/**
*メインルーチン
*/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR lpCmdLine, int nCmdShow)
{
	setlocale(LC_ALL, "Japanese");   //ロケール（地域言語）を日本語でセット
	MSG msg;
	WNDCLASS Wndclass;
	HWND hWnd;

	//Windows情報の設定
	Wndclass.style = CS_HREDRAW | CS_VREDRAW;
	Wndclass.lpfnWndProc = WndProc;
	Wndclass.cbClsExtra = Wndclass.cbWndExtra = 0;
	Wndclass.hInstance = hInstance;
	Wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	Wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	Wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	Wndclass.lpszMenuName = NULL;
	Wndclass.lpszClassName = "Reflection Star";	//クラス名
									//Windowの登録
	RegisterClass(&Wndclass);

	RECT Rect;
	Rect.left = 0;
	Rect.top = 0;
	Rect.right = window::Width;
	Rect.bottom = window::Height;
	AdjustWindowRect(&Rect, WS_OVERLAPPEDWINDOW | WS_VISIBLE, false);

	int width = Rect.right - Rect.left;
	int height = Rect.bottom - Rect.top;

	//Windowの生成
	hWnd = CreateWindow(
		"Reflection Star",								//ウィンドウのクラス名
		"Reflection Star", 								//ウィンドウのタイトル
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,	//ウィンドウスタイル
		CW_USEDEFAULT,						// ウィンドウの横方向の位置x
		CW_USEDEFAULT,						// ウィンドウの縦方向の位置y
		width,							// Width（幅）
		height,							// Height（高さ）
		NULL,
		NULL,
		hInstance,							// アプリケーションインスタンスのハンドル
		NULL
	);
	if (!hWnd) return 0;

	
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		Sleep(1);
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			
		}
	}
	
	return (int)msg.wParam;
}


/**
*メッセージ処理
*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wp, lp);
}
