#include "stdafx.h"
#include "TEXTCOUT2.h"


TEXTCOUT2::TEXTCOUT2()
{
}

TEXTCOUT2::TEXTCOUT2(std::string s)
{
	messages.push_back(s);
}

void TEXTCOUT2::display(HDC &hdc, RECT &rc)
{
	int x = 0;
	int y = 0;
		if (messages.size() < 20)
		{
			for (int i = 0; i < messages.size() - 1; i++)
			{

				std::string narrow_string(messages[i + _index]);

				std::wstring stemp = std::wstring(messages[_index].begin(), messages[_index].end());
				LPCWSTR sw = stemp.c_str();

				//SetTextColor(hdc, RGB(0, 0, 0));
				//SetBkMode(hdc, TRANSPARENT);

				std::string text = messages[i + _index];
				TextOut(hdc, x + 500, 500 + y + (i * 20), sw, text.length());
				EndPath(hdc);
				SelectClipPath(hdc, RGN_AND);
				FillRect(hdc, &rc, (HBRUSH)GetStockObject(GRAY_BRUSH));
			}
		}
		else
		{
			for (int i = 0; i <= 20; i++)
			{

				std::string narrow_string(messages[i + _index]);

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
}

TEXTCOUT2::~TEXTCOUT2()
{
}
