#include <Windows.h>
#include "resource.h"

//����������� ��������� ����������
HWND hEdit1;
HWND hStc1;
HWND hBtn1;
HWND hBtn2;

// ���������� ��� �������� ������
int SCRWIDTH = GetSystemMetrics(SM_CXSCREEN);
int SCRHEIGHT = GetSystemMetrics(SM_CYSCREEN);
int spdx = 30, spdy = 30;
int posx = 10, posy = 10;
int btnwidth = 100, btnheight = 50;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	HWND hMainWnd;
	TCHAR szClassName[] = L"MyClass";
	MSG msg;
	TCHAR szTitle[] = L"��1-��������";
	int WIDTH = 400;
	int HEIGHT = 200;
	WNDCLASSEX wc;
	//��������� ��������� ������ ����
	wc.cbSize = sizeof(wc);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_Rocket));
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wc.lpszClassName = szClassName;
	wc.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_Rocket));
	// ������������ ����� ����
	if (!RegisterClassEx(&wc)) {
		MessageBox(NULL, L"Cannot register class", L"Error!", MB_OK);
		return 0;
	}

	//������� �������� ���� ����������
	hMainWnd = CreateWindow(
		szClassName, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, WIDTH, HEIGHT,
		(HWND)NULL, (HMENU)NULL,
		(HINSTANCE)hInstance, NULL
	);
	//������� ���������� ��������
	hBtn1 = CreateWindow(L"BUTTON", L"������1", WS_VISIBLE | WS_CHILD, 60, 
		90, 60, 25, hMainWnd, (HMENU)ID_BTN1, hInstance, NULL);
	hBtn2 = CreateWindow(L"BUTTON", L"������2", WS_VISIBLE | WS_CHILD, 245, 
		90, 60, 25, hMainWnd, (HMENU)ID_BTN2, hInstance, NULL);
	hEdit1 = CreateWindowEx(WS_EX_CLIENTEDGE,L"EDIT", L"����", WS_VISIBLE | WS_CHILD, 
		60, 30, 60, 25, hMainWnd, (HMENU)ID_EDT1, hInstance, NULL);
	hStc1 = CreateWindowEx(WS_EX_CLIENTEDGE,L"STATIC", L"�����", WS_VISIBLE | WS_CHILD, 
		245, 30, 120, 25, hMainWnd, (HMENU)ID_STC1, hInstance, NULL);
	RECT wRect;
	const int g_1 = 150;
	const int g_2 = 100;
	GetWindowRect(hMainWnd, &wRect);
	HRGN Rgn1 = CreateEllipticRgn(-g_1, -g_1, wRect.right - wRect.left + g_1, wRect.bottom - wRect.top);
	HRGN Rgn2 = CreateEllipticRgn(g_1 + g_2, g_1, wRect.bottom - wRect.top - g_1 + g_2, wRect.bottom - wRect.top - g_1);
	CombineRgn(Rgn1, Rgn1, Rgn2, RGN_XOR);
	SetWindowRgn(hMainWnd, Rgn1, FALSE);

	//���������� ���� ����
	ShowWindow(hMainWnd, nCmdShow);
	// UpdateWindow(hMainWnd)

	//��������� ���� ��������� ��������� �� �������� ����������
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	RECT rct;
	TCHAR str[50];

	switch (uMsg) {
	case WM_CREATE:
		SetTimer(hWnd, NULL, 50, NULL);
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		// > ������ ������
		case ID_BTN1:
			GetWindowText(hEdit1, str, 50);
			SetWindowText(hStc1, str);
			break;
		// > ������ ������
		case ID_BTN2:
			GetWindowText(hWnd, str, 50);
			SetWindowText(hStc1, str);
			break;
		// > ����������� ����
		case IDM_MOVE_WINDOW:
			MoveWindow(hWnd, 0, 0, 600, 600, true);
			SetWindowText(hStc1, L"IDM_MOVE_WINDOW");
			break;
		// > ����� ��������
		case IDM_CHANGE_PARENT:
			SetParent(hBtn1, NULL);
			SetWindowText(hStc1, L"IDM_CHANGEPARENT");
			break;
		// > � ���������
		case IDM_ABOUT:
			MessageBox(hWnd, L" ������������ ������ �1\n\n �-05-19 �������� �������", L"� ���������", MB_OK);
			SetWindowText(hStc1, L"IDM_ABOUT");
			break;
		// > �����
		case IDM_EXIT:
			PostMessage(hWnd, WM_CLOSE, 0, 0);
			break;
		}
		break;
	case WM_TIMER:
		// ���� ������ �� ����������� ����, �� ���������
		if (GetParent(hBtn1) != hWnd) {
			GetWindowRect(hBtn1, &rct);
			if (rct.top <= 0 || rct.bottom >= SCRHEIGHT)
				spdy = -spdy;
			if (rct.left <= 0 || rct.right >= SCRWIDTH)
				spdx = -spdx;
			MoveWindow(hBtn1, rct.left + spdx, rct.top + spdy, btnwidth,
				btnheight, false);
		}
	break;
	// > ������ ������ ����
	case WM_RBUTTONDOWN:
		SetWindowText(hStc1, L"WM_RBUTTONDOWN");
		SetParent(hBtn1, hWnd); // ������� ������ � ����
		MoveWindow(hBtn1, 60, 90, 60, 25, false);
		break;
	// > ����� ������ ����
	case WM_LBUTTONDOWN:
		SetWindowText(hStc1, L"WM_LBUTTONDOWN");
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


