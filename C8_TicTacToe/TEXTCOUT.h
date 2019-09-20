#pragma once
#include <string>
#include <list>
#include <vector>

using std::string;

class TEXTCOUT
{
private:
	std::vector <string> messages;
	string _message;
	HWND _FinalText;
	int _SIZEX = 500;
	int _POSX = 100;
	int _SIZEY = 200;
	int _POSY = 100;
	int _index = 0;
public:
	TEXTCOUT();
	TEXTCOUT(HWND hWnd);
	TEXTCOUT(HWND hWnd, int POSX, int POSY, int SIZEX, int SIZEY);
	void UpdatePos(int POSX, int POSY);
	void UpdateSize(int SIZEX, int SIZEY);
	void Move(int POSX, int POSY, int SIZEX, int SIZEY);
	void addText(string text);
	void scroll(int x, int y);
	void Clear();
	void display(HDC &hdc, RECT &rc);
	HWND &GetWindow();
	void setIndex(int index);
	int getIndex();
	~TEXTCOUT();
};

