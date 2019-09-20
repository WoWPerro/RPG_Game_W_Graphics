#pragma once
#include <vector>
#include <string>

class TEXTCOUT2
{
private:
	std::vector <std::string> messages;
	int _index = 0;
public:
	TEXTCOUT2();
	TEXTCOUT2(std::string s);	
	void addText(std::string text);
	void display(HDC &hdc, RECT &rc);
	void Move(int x, int y, int w, int h);
	int GetIndex();
	void SetIndex(int index);
	int size();
	~TEXTCOUT2();
};

