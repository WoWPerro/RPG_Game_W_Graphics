#include "stdafx.h"
#include "TEXTCOUT.h"

TEXTCOUT::TEXTCOUT()
{

}

TEXTCOUT::TEXTCOUT(HWND hWnd)
{
	_FinalText = CreateWindowA("STATIC", "NULL", WS_VISIBLE | WS_CHILD | SS_LEFT | WS_VSCROLL, _POSX, _POSY, _SIZEX, _SIZEY, hWnd, NULL, NULL, NULL);
	//BOOL EnableScrollBar(hWnd, UINT wSBflags,UINT wArrows);	
	messages.push_back("HOLA\n");
}

TEXTCOUT::TEXTCOUT(HWND hWnd, int POSX, int POSY, int SIZEX, int SIZEY)
{
	_POSX = POSX;
	_POSY = POSY;
	_SIZEX = SIZEX;
	_SIZEY = SIZEY;
	_FinalText = CreateWindowA("STATIC", "NULL", WS_VISIBLE | WS_CHILD | SS_LEFT | WS_VSCROLL, _POSX, _POSY, _SIZEX, _SIZEY, hWnd, NULL, NULL, NULL);
	messages.push_back("HOLA\n");

	//BOOL EnableScrollBar(hWnd, UINT wSBflags,UINT wArrows);	
}

void TEXTCOUT::UpdatePos(int POSX, int POSY)
{
	_POSX = POSX;
	_POSY = POSY;
}

void TEXTCOUT::UpdateSize(int SIZEX, int SIZEY)
{
	_SIZEX = SIZEX;
	_SIZEY = SIZEY;
}

void TEXTCOUT::addText(string text)
{
	/*_message += text;
	std::wstring stemp = std::wstring(_message.begin(), _message.end());
	LPCWSTR sw = stemp.c_str();*/
	/*SetWindowText(_FinalText, (sw));
	RedrawWindow(_FinalText, NULL, NULL, RDW_VALIDATE | RDW_UPDATENOW);*/
	messages.push_back(text);
}

void TEXTCOUT::Move(int POSX, int POSY, int SIZEX, int SIZEY)
{
	_POSX = POSX;
	_POSY = POSY;
	_SIZEX = SIZEX;
	_SIZEY = SIZEY;
	MoveWindow(_FinalText, _POSX, _POSY, _SIZEX, _SIZEY, true);
	//SetWindowText(_FinalText, (sw));
	//RedrawWindow(_FinalText, NULL, NULL, RDW_VALIDATE | RDW_UPDATENOW);
	//InvalidateRect(_FinalText, NULL, TRUE);
	
}

void TEXTCOUT::Clear()
{
	_message = "";
	std::wstring stemp = std::wstring(_message.begin(), _message.end());
	LPCWSTR sw = stemp.c_str();
	SetWindowText(_FinalText, (sw));
}

void TEXTCOUT::scroll(int dx, int dy)
{
	/*RECT *rectclipling = new RECT;
	rectclipling->bottom = 100;
	rectclipling->left = 0;
	rectclipling->right = 100;
	rectclipling->top = 0;
	ScrollWindowEx(_FinalText, dx, dy, NULL, NULL, NULL, NULL, NULL);*/


	/*std::wstring stemp = std::wstring(_message.begin(), _message.end());
	LPCWSTR sw = stemp.c_str();
	SetWindowText(_FinalText, (sw));*/
	//RedrawWindow(_FinalText, NULL, NULL, RDW_VALIDATE | RDW_UPDATENOW);
	//RedrawWindow(_FinalText, NULL, NULL, RDW_VALIDATE | RDW_UPDATENOW);
	//UpdateWindow(_FinalText);
	//InvalidateRect(_FinalText, NULL, TRUE);
}

HWND &TEXTCOUT::GetWindow()
{
	return _FinalText;
}

void TEXTCOUT::display(HDC &hdc, RECT &rc)
{
	int x = 0;
	int y = 0;
	if (messages.size() < 20)
	{
		for (int i = 0; i < messages.size() - 1; i++)
		{

			string narrow_string(messages[i + _index]);

			std::wstring stemp = std::wstring(messages[_index].begin(), messages[_index].end());
			LPCWSTR sw = stemp.c_str();

			SetTextColor(hdc, RGB(0, 0, 0));
			SetBkMode(hdc, TRANSPARENT);
	
			std::string text = messages[i + _index];
			TextOut(hdc, x , y + (i*20), sw, text.length());
			EndPath(hdc);
			SelectClipPath(hdc, RGN_AND);
			FillRect(hdc, &rc, (HBRUSH)GetStockObject(GRAY_BRUSH));
		}
	}
	else 
	{
		for (int i = 0; i <= 20; i++)
		{

			string narrow_string(messages[i + _index]);

			std::wstring stemp = std::wstring(messages[_index].begin(), messages[_index].end());
			LPCWSTR sw = stemp.c_str();

			SetTextColor(hdc, RGB(0, 0, 0));
			SetBkMode(hdc, TRANSPARENT);
			//TextOut(hdc, 0, 0, sw, ARRAYSIZE(sw)); //Imprime cosas en la pantalla			
			std::string text = messages[_index];
			TextOut(hdc, 0, 0, sw, text.length());
			EndPath(hdc);
			SelectClipPath(hdc, RGN_AND);
			FillRect(hdc, &rc, (HBRUSH)GetStockObject(GRAY_BRUSH));
		}
	}
	
	
}

void TEXTCOUT::setIndex(int index)
{
	_index = index;
}

int TEXTCOUT::getIndex()
{
	return _index;
}


TEXTCOUT::~TEXTCOUT()
{
}
