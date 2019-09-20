#include "stdafx.h"
#include "TEXTCOUT2.h"
#include <exception>

TEXTCOUT2::TEXTCOUT2()
{
}

TEXTCOUT2::TEXTCOUT2(std::string s)
{
	try
	{
		messages.push_back(s);
	}
	catch (...)
	{

	}
}

void TEXTCOUT2::display(HDC &hdc, RECT &rc)
{
	int x = 0;
	int y = 0;
	try
	{
		if (messages.size() < 25)
		{
			for (int i = 0; i < messages.size(); i++)
			{

				std::string narrow_string(messages[i + _index]);

				std::wstring stemp = std::wstring(messages[i + _index].begin(), messages[i + _index].end());
				LPCWSTR sw = stemp.c_str();

				//SetTextColor(hdc, RGB(0, 0, 0));
				//SetBkMode(hdc, TRANSPARENT);

				std::string text = messages[i + _index];
				TextOut(hdc, x + 500, 30 + y + (i * 20), sw, text.length());
				EndPath(hdc);
				//SelectClipPath(hdc, RGN_AND);
				//FillRect(hdc, &rc, (HBRUSH)GetStockObject(GRAY_BRUSH));
			}
		}
		else
		{
			for (int i = 0; i <= 25; i++)
			{

				std::string narrow_string(messages[i + _index]);

				std::wstring stemp = std::wstring(messages[i + _index].begin(), messages[i + _index].end());
				LPCWSTR sw = stemp.c_str();

				SetTextColor(hdc, RGB(0, 0, 0));
				SetBkMode(hdc, TRANSPARENT);
				//TextOut(hdc, 0, 0, sw, ARRAYSIZE(sw)); //Imprime cosas en la pantalla			
				std::string text = messages[i + _index];
				TextOut(hdc, x + 500, 30 + y + (i * 20), sw, text.length());
				EndPath(hdc);
			/*	SelectClipPath(hdc, RGN_AND);
				FillRect(hdc, &rc, (HBRUSH)GetStockObject(GRAY_BRUSH));*/
			}
		}
	}
	catch (std::exception &e)
	{

	}

}

void TEXTCOUT2::addText(std::string text)
{
	messages.push_back(text);
}

void TEXTCOUT2::Move(int x, int y, int w, int h)
{

}

int TEXTCOUT2::GetIndex()
{
	return _index;
}

void TEXTCOUT2::SetIndex(int index)
{
	_index = index;
	if (_index < 0)
	{
		_index = 0;
	}
	if (_index > messages.size() - 26)
	{
		_index = messages.size() - 26;
	}
}

int TEXTCOUT2::size()
{
	return messages.size();
}

TEXTCOUT2::~TEXTCOUT2()
{
}
