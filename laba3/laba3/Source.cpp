#include <Windows.h>
#include "resource.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

BOOL CALLBACK EnumWndProc(HWND hWnd, LPARAM lParam);

BOOL CALLBACK EnumChildProc(HWND hWnd, LPARAM lParam);

//Дескрипторы элементов управления
HWND hEdit1,
	hStc1,
	hBtn1,
	hBtn2,
	hBtn3,
	hBtn4,
	hBtn5,
	hBtn6,
	hBtn7,
	hBtn8,
	hBtn9,
	hWnd1,
	hWnd2,
	hWnd3;

POINT pt1;

HWND hExternalBtn1;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	HWND hMainWnd;
	TCHAR szClassName[] = L"MyClass";
	MSG msg;
	WNDCLASSEX wc;
	int iWIDTH = 600;
	int iHEIGHT = 400;
	//Заполняем структуру класса окна
	wc.cbSize = sizeof(wc);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szClassName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	// Регистрируем класс окна
	if (!RegisterClassEx(&wc)) {
		MessageBox(NULL, L"Cannot register class", L"Error!", MB_OK);
		return 0;
	}

	//Создаем основное окно приложения
	hMainWnd = CreateWindow(
		szClassName, L"A Hello1 Application", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, iWIDTH, iHEIGHT,
		(HWND)NULL, (HMENU)NULL,
		(HINSTANCE)hInstance, NULL);

	if (!hMainWnd) {
		MessageBox(NULL, L"Cannot create main window", L"Error", MB_OK);
		return 0;
	}

	//Создаем управлящие элементы
	hBtn1 = CreateWindow(L"BUTTON", L"Кнопка1", WS_VISIBLE | WS_CHILD, 60,
		90, 80, 25, hMainWnd, (HMENU)ID_BTN1, hInstance, NULL);
	hBtn2 = CreateWindow(L"BUTTON", L"Кнопка2", WS_VISIBLE | WS_CHILD, 180,
		90, 80, 25, hMainWnd, (HMENU)ID_BTN2, hInstance, NULL);
	hBtn3 = CreateWindow(L"BUTTON", L"Кнопка3", WS_VISIBLE | WS_CHILD, 300,
		90, 80, 25, hMainWnd, (HMENU)ID_BTN3, hInstance, NULL);
	hBtn4 = CreateWindow(L"BUTTON", L"Кнопка4", WS_VISIBLE | WS_CHILD, 60,
		130, 80, 25, hMainWnd, (HMENU)ID_BTN4, hInstance, NULL);
	hBtn5 = CreateWindow(L"BUTTON", L"Кнопка5", WS_VISIBLE | WS_CHILD, 180,
		130, 80, 25, hMainWnd, (HMENU)ID_BTN5, hInstance, NULL);
	hBtn6 = CreateWindow(L"BUTTON", L"Кнопка6", WS_VISIBLE | WS_CHILD, 300,
		130, 80, 25, hMainWnd, (HMENU)ID_BTN6, hInstance, NULL);
	hBtn7 = CreateWindow(L"BUTTON", L"Кнопка7", WS_VISIBLE | WS_CHILD, 60,
		170, 80, 25, hMainWnd, (HMENU)ID_BTN7, hInstance, NULL);
	hBtn8 = CreateWindow(L"BUTTON", L"Кнопка8", WS_VISIBLE | WS_CHILD, 300,
		170, 80, 25, hMainWnd, (HMENU)ID_BTN8, hInstance, NULL);
	hEdit1 = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"Ввод", WS_VISIBLE | WS_CHILD,
		60, 30, 120, 25, hMainWnd, (HMENU)ID_EDT1, hInstance, NULL);
	hStc1 = CreateWindowEx(WS_EX_CLIENTEDGE, L"STATIC", L"Вывод", WS_VISIBLE | WS_CHILD,
		245, 30, 120, 25, hMainWnd, (HMENU)ID_STC1, hInstance, NULL);

	//Показываем наше окно
	ShowWindow(hMainWnd, nCmdShow);
	// UpdateWindow(hMainWnd)

	//Выполняем цикл обработки сообщений до закрытия приложения
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT ps;
	RECT rect;
	TCHAR str[100] = L"";
	int cnt = 0;

	switch (uMsg) {
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case ID_BTN1:
			hWnd1 = FindWindow(NULL, L"Window1");
			hWnd2 = FindWindow(NULL, L"Window2");
			hWnd3 = FindWindow(NULL, L"Window3");
			if (IsWindowVisible(hWnd1))
				ShowWindow(hWnd1, SW_HIDE);
			else
				ShowWindow(hWnd1, SW_RESTORE);
			if (IsWindowVisible(hWnd2))
				ShowWindow(hWnd2, SW_HIDE);
			else
				ShowWindow(hWnd2, SW_RESTORE);
			if (IsWindowVisible(hWnd3))
				ShowWindow(hWnd3, SW_HIDE);
			else
				ShowWindow(hWnd3, SW_RESTORE);
			SetWindowText(hStc1, L"1btn");
			break;
		case ID_BTN2:
			hWnd1 = FindWindow(NULL, L"Window1");
			hWnd2 = FindWindow(NULL, L"Window2");
			hWnd3 = FindWindow(NULL, L"Window3");
			if (IsWindowEnabled(hWnd1))
				EnableWindow(hWnd1, false);
			else
				EnableWindow(hWnd1, true);
			if (IsWindowEnabled(hWnd2))
				EnableWindow(hWnd2, false);
			else
				EnableWindow(hWnd2, true);
			if (IsWindowEnabled(hWnd3))
				EnableWindow(hWnd3, false);
			else
				EnableWindow(hWnd3, true);
			SetWindowText(hStc1, L"2btn");
			break;
		case ID_BTN3:
			hWnd3 = FindWindow(NULL, L"Window3");
			if(hWnd3 && IsWindowEnabled(hWnd3))
			SendMessage(hWnd3, WM_SYSCOMMAND, SC_CLOSE, 0);
			SetWindowText(hStc1, L"3btn");
			break;
		case ID_BTN4:
			hWnd1 = FindWindow(NULL, L"Window1");
			if (hWnd1) {
				hExternalBtn1 = GetDlgItem(hWnd1, ID_BTN1);
				if (hExternalBtn1) {
					SendMessageW(hExternalBtn1, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
					Sleep(50);
					SendMessageW(hExternalBtn1, WM_LBUTTONUP, NULL, NULL);
				}
			}
			break;
		case ID_BTN5:
			hWnd1 = FindWindow(NULL, L"Window1");
			if(hWnd1)
				SendMessageW(hWnd1, WM_COMMAND, IDM_RESIZE_WINDOW, NULL);
		case ID_BTN6:
			hWnd1 = FindWindow(NULL, L"Window1");
			if (hWnd1) {
				SendMessageW(hWnd1, WM_RBUTTONDOWN, NULL, NULL);
			}
		case ID_BTN7:
			hWnd1 = FindWindow(NULL, L"Window1");
			if (hWnd1) {
				EnumChildWindows(hWnd1, EnumChildProc, (LPARAM)&cnt);
			}
			break;
		case ID_BTN8:
			EnumWindows(EnumWndProc, (LPARAM)& cnt);
			break;
		}
		break;
	case WM_RBUTTONDOWN:
		hWnd1 = FindWindow(NULL, L"Window1");
		if (hWnd1) {
			pt1.x = LOWORD(lParam);
			pt1.y = HIWORD(lParam);
			ScreenToClient(hWnd1, &pt1);
			SendMessage(hWnd1, WM_LBUTTONDOWN, wParam, MAKELONG(pt1.x, pt1.y));
		}
		break;
	case WM_MOUSEMOVE:
		if (LOWORD(wParam) == MK_RBUTTON){
			hWnd1 = FindWindow(NULL, L"Window1");
			if (hWnd1) {
				POINT pt2;
				pt2.x = LOWORD(lParam);
				pt2.y = HIWORD(lParam);
				ScreenToClient(hWnd1, &pt2);
				SendMessage(hWnd1, WM_MOUSEMOVE, MK_LBUTTON, MAKELONG(pt2.x, pt2.y));
			}
		}
			break;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}


BOOL CALLBACK EnumWndProc(HWND hWnd, LPARAM lParam)
{
	TCHAR str[50] = L"Окно", n[50] = L"";
	if (IsWindowVisible(hWnd)) {
		int* k = (int*)lParam;
		_itow_s(++(*k), n, 10);
		wcscat_s(str, n);
		SetWindowText(hWnd, str);
		int cnt = 0;
		EnumChildWindows(hWnd, EnumChildProc, (LPARAM)& cnt);
	}
	return TRUE;
}


BOOL CALLBACK EnumChildProc(HWND hWnd, LPARAM lParam)
{
	TCHAR str[50] = L"Д.Окно", n[50] = L"";
	int* k = (int*)lParam;
	_itow_s(++(*k), n, 10);
	wcscat_s(str, n);
	SendMessage(hWnd, WM_SETTEXT, 0, (LPARAM) str);
	return TRUE;
}