// C8_TicTacToe.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "C8_TicTacToe.h"
#include <windowsx.h>

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
const int CELL_SIZE = 100;
HICON hIcon1, hIcon2;
HWND TextBox;
char textReadead[20];

BOOL GetGameBoardRect(HWND hWnd, RECT *pRect)
{
	RECT rc;
	if (GetClientRect(hWnd, &rc))
	{
		int width = rc.right - rc.left;
		int height = rc.bottom - rc.top;
		pRect->left = (width - CELL_SIZE * 3) / 2;
		pRect->top = (height - CELL_SIZE * 3) / 2;
		pRect->right = (pRect->left + CELL_SIZE * 3);
		pRect->bottom = (pRect->top + CELL_SIZE * 3);
	}
	return TRUE;
}

void DrawLine(HDC hdc, int x1, int y1, int x2, int y2)
{
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
}

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_C8TICTACTOE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_C8TICTACTOE));

    MSG msg;

    // Main message loop (Update de cosas):
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_C8TICTACTOE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW); //Cambiar el cursor
    //wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.hbrBackground  = (HBRUSH)(GetStockObject(GRAY_BRUSH));
    //wcex.hbrBackground  = (HBRUSH)(GetStockObject(GRADIENT_FILL_TRIANGLE));
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_C8TICTACTOE);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//

int GetCellNumberFromPoint(HWND hWnd, int x, int y)
{
	RECT rc;
	POINT pt = { x,y };
	if (GetGameBoardRect(hWnd, &rc))
	{
		if (PtInRect(&rc, pt))
		{
			x = pt.x - rc.left;
			y = pt.y - rc.top;
			int column = x / CELL_SIZE;
			int row = y / CELL_SIZE;
			return column + row * 3;
		}
	}
	return -1;
}

BOOL GetCellRect(HWND hWnd, int index, RECT* pRect)
{
	RECT rcBoard;
	SetRectEmpty(pRect);
	if (index < 0 || index > 8) return false;
	if (GetGameBoardRect(hWnd, &rcBoard))
	{
		int y = index / 3;
		int x = index % 3;
		pRect->left = rcBoard.left + x * CELL_SIZE;
		pRect->top = rcBoard.top + y * CELL_SIZE;
		pRect->right = pRect->left + CELL_SIZE;
		pRect->bottom = pRect->top + CELL_SIZE;
		return TRUE;
	}
	return FALSE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_CREATE: {
		hIcon1 = LoadIcon(hInst, MAKEINTRESOURCE(IDI_SMALL));
		hIcon1 = LoadIcon(hInst, MAKEINTRESOURCE(IDI_C8TICTACTOE));
		TextBox = CreateWindowA("EDIT", "", WS_BORDER | WS_CHILD | WS_VISIBLE, 10, 10, 400, 20, hWnd, NULL, NULL, NULL);
		CreateWindowA("BUTTON", "OKIDOKI", WS_VISIBLE | WS_CHILD | WS_BORDER, 420, 10, 70, 20, hWnd, (HMENU)1, NULL, NULL);
	}
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
			case 1:
			{
				int length = GetWindowTextLength(TextBox) + 1;
				GetWindowTextA(TextBox, textReadead, length);
				MessageBeep(MB_ICONASTERISK);
				MessageBoxA(hWnd, textReadead, textReadead, MB_OK);
				break;
			}
			case ID_Menu:
			{
				MessageBoxA(hWnd, "Estás Sure", "Really", MB_YESNO | MB_ICONQUESTION);
				break;
			}
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About); //Para crear cuadros de dialogo, usar otra funcion diferente a "About"
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
	case WM_LBUTTONDOWN: 
	{
		int xPos = GET_X_LPARAM(lParam);
		int yPos = GET_Y_LPARAM(lParam);
		int index = GetCellNumberFromPoint(hWnd, xPos, yPos);
		HDC hdc = GetDC(hWnd);
		if (hdc)
		{
			//WCHAR temp[100];
			//wsprintf(temp, L"Index = %d", index); // L"" la L convierte el char en WCHAR
			//TextOut(hdc, xPos, yPos, temp, lstrlen(temp));
			////ReleaseDC(hWnd, hdc); // Sirve para liberar y dar muchos clicks
			if (index != -1)
			{
				RECT rcCell;
				if (GetCellRect(hWnd, index, &rcCell))
				{
					//DrawIcon(hdc, rcCell.left + (CELL_SIZE / 2) - 16, rcCell.top + (CELL_SIZE / 2) - 16, hIcon1);
					//DrawIcon(hdc, rcCell.left + (CELL_SIZE / 2) - 16, rcCell.top + (CELL_SIZE / 2) - 16, hIcon2);
					//FillRect(hdc, &rcCell, GetStockBrush(BLACK_BRUSH));
				}
			}
		}
		break;
	}
	case WM_GETMINMAXINFO:
	{
		MINMAXINFO * pMinMax = (MINMAXINFO*)lParam;
		pMinMax->ptMinTrackSize.x = CELL_SIZE * 5;
		pMinMax->ptMinTrackSize.y = CELL_SIZE * 5;
	}
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
			RECT rc;
			if (GetGameBoardRect(hWnd, &rc))
			{
				RECT rcClient;
				if (GetClientRect(hWnd, &rcClient))
				{
					const WCHAR szText[] = L"Holi";
					SetBkMode(hdc, TRANSPARENT); //no tiene el recuadro
					SetTextColor(hdc, RGB(30, 150, 250));
					TextOut(hdc, rcClient.right -100, 200, szText, ARRAYSIZE(szText)); //Imprime cosas en la pantalla					
				}
				FillRect(hdc, &rc, (HBRUSH)GetStockObject(WHITE_BRUSH));
				//Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
			}
			for (int i = 0; i < 4; i++)
			{
				DrawLine(hdc, rc.left + CELL_SIZE * i, rc.top, rc.left + CELL_SIZE * i, rc.bottom);
				DrawLine(hdc, rc.left , rc.top + CELL_SIZE * i, rc.right, rc.top + CELL_SIZE * i);
			}

            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
		DestroyIcon(hIcon1);
		DestroyIcon(hIcon2);
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
