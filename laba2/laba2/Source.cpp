#include <Windows.h>
#include "resource.h"

//Дескрипторы элементов управления
HWND hEdit1;
HWND hStc1;
HWND hBtn1;
HWND hBtn2;
HWND hBtn3;

int events[] = { 0,0,0,0 };

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	HWND hMainWnd;
	TCHAR szClassName[] = L"MyClass";
	MSG msg;
	WNDCLASSEX wc;
	int iWIDTH = 600;
	int iHEIGHT = 400;
	//Заполняем структуру класса окна
	wc.cbSize = sizeof(wc);
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wc.lpszClassName = szClassName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	// Регистрируем класс окна
	if (!RegisterClassEx(&wc)) {
		MessageBox(NULL, L"Cannot register class", L"Error!", MB_OK);
		return 0;
	}

	//Создаем основное окно приложения
	hMainWnd = CreateWindow(
		szClassName, L"Window1", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, iWIDTH, iHEIGHT,
		(HWND)NULL, (HMENU)NULL,
		(HINSTANCE)hInstance, NULL
	);

	if (!hMainWnd) {
		MessageBox(NULL, L"Cannot create main window", L"Error", MB_OK);
		return 0;
	}

	//Создаем управлящие элементы
	hBtn1 = CreateWindow(L"BUTTON", L"Кнопка1", WS_VISIBLE | WS_CHILD, 60,
		90, 60, 25, hMainWnd, (HMENU)ID_BTN1, hInstance, NULL);
	hBtn2 = CreateWindow(L"BUTTON", L"Кнопка2", WS_VISIBLE | WS_CHILD, 245,
		90, 60, 25, hMainWnd, (HMENU)ID_BTN2, hInstance, NULL);
	hBtn3 = CreateWindow(L"BUTTON", L"Кнопка3", WS_VISIBLE | WS_CHILD, 60,
		140, 60, 25, hMainWnd, (HMENU)ID_BTN3, hInstance, NULL);
	hEdit1 = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"Ввод", WS_VISIBLE | WS_CHILD,
		60, 30, 60, 25, hMainWnd, (HMENU)ID_EDT1, hInstance, NULL);
	hStc1 = CreateWindowEx(WS_EX_CLIENTEDGE, L"STATIC", L"Вывод", WS_VISIBLE | WS_CHILD,
		245, 30, 180, 25, hMainWnd, (HMENU)ID_STC1, hInstance, NULL);

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
	TCHAR str[100] = L"", sX[50] = L"", sY[50] = L"", ev[100] = L"";;
	int num;
	LRESULT currentArea;
	WORD x, y;

	switch (uMsg) {
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
			// > Первая кнопка
		case ID_BTN1:
			GetWindowText(hEdit1, str, 50);
			num = _wtoi(str);
			_itow_s(num * num, str,10);
			SetWindowText(hStc1, str);
			break;
			// > Вторая кнопка
		case ID_BTN2:
			// 1 способ
			/*SendMessageW(hBtn1, BM_SETSTATE, true, NULL);
			SendMessageW(hWnd, WM_COMMAND, ID_BTN1, NULL);
			Sleep(50);
			SendMessageW(hBtn1, BM_SETSTATE, false, NULL);*/

			// 2 способ
			SendMessageW(hBtn1, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
			Sleep(50);
			SendMessageW(hBtn1, WM_LBUTTONUP, NULL, NULL);

			break;
			// > Третья кнопка
		case ID_BTN3:
			wcscat_s(str, L"WM_LBUTTONDBLCLK: ");
			_itow_s(events[0], ev, 10);
			wcscat_s(str, ev);
			wcscat_s(str, L"; WM_LBUTTONDOWN: ");
			_itow_s(events[1], ev, 10);
			wcscat_s(str, ev);
			wcscat_s(str, L"; WM_LBUTTONUP: ");
			_itow_s(events[2], ev, 10);
			wcscat_s(str, ev);
			wcscat_s(str, L"; WM_NCHITTEST: ");
			_itow_s(events[3], ev, 10);
			wcscat_s(str, ev);
			MessageBox(hWnd, str, L"Подсчет событий", MB_OK);
			break;
			// > Изменение размера окна по умолчанию
		case IDM_RESIZE_WINDOW:
			MoveWindow(hWnd, 0, 0, 600, 600, true);
			SetWindowText(hStc1, L"IDM_MOVE_WINDOW");
			break;
			// > Выход
		case IDM_EXIT:
			PostMessage(hWnd, WM_CLOSE, 0, 0);
			break;
		}
		break;

	case WM_RBUTTONDOWN:
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		_itow_s(x, sX, 10);
		_itow_s(y, sY, 10);
		wcscat_s(str, L"x = ");
		wcscat_s(str, sX);
		wcscat_s(str, L"; y = ");
		wcscat_s(str, sY);
		SetWindowText(hStc1, str);
		break;
	case WM_LBUTTONDBLCLK:
		events[0]++;
		break;
	case WM_LBUTTONDOWN:
		events[1]++;
		SendMessage(hWnd, WM_SYSCOMMAND, SC_MOVE | HTCAPTION, 0);
		break;
	case WM_LBUTTONUP:
		events[2]++;
		break;
	case WM_NCHITTEST:
		events[3]++;
		return DefWindowProc(hWnd, WM_NCHITTEST, wParam, lParam);
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


