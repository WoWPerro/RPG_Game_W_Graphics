#include "stdafx.h"
#include "TEXTCOUT.h"

TEXTCOUT::TEXTCOUT()
{

}

TEXTCOUT::TEXTCOUT(HWND hWnd)
{
	_FinalText = CreateWindowA("STATIC", "NULL", WS_VISIBLE | WS_CHILD | SS_LEFT | WS_VSCROLL, _POSX, _POSY, _SIZEX, _SIZEY, hWnd, NULL, NULL, NULL);
	//BOOL EnableScrollBar(hWnd, UINT wSBflags,UINT wArrows);	
}

TEXTCOUT::TEXTCOUT(HWND hWnd, int POSX, int POSY, int SIZEX, int SIZEY)
{
	_POSX = POSX;
	_POSY = POSY;
	_SIZEX = SIZEX;
	_SIZEY = SIZEY;
	_FinalText = CreateWindowA("STATIC", "NULL", WS_VISIBLE | WS_CHILD | SS_LEFT | WS_VSCROLL, _POSX, _POSY, _SIZEX, _SIZEY, hWnd, NULL, NULL, NULL);
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
	_counter++;
	_message += text;
	std::wstring stemp = std::wstring(_message.begin(), _message.end());
	LPCWSTR sw = stemp.c_str();
	SetWindowText(_FinalText, (sw));
}

void TEXTCOUT::Move(int POSX, int POSY, int SIZEX, int SIZEY)
{
	_POSX = POSX;
	_POSY = POSY;
	_SIZEX = SIZEX;
	_SIZEY = SIZEY;
	MoveWindow(_FinalText, _POSX, _POSY, _SIZEX, _SIZEY, true);
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
	ScrollWindowEx(_FinalText, dx, dy, NULL, NULL, NULL, NULL, NULL);
}

TEXTCOUT::~TEXTCOUT()
{
}
