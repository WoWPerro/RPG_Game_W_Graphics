#pragma once
#pragma once
#include <time.h>
#include <iostream>

using std::cout;
using std::endl;

class Spells
{
private:
	//std::string _spellname = "NONAME";
	int _damage = 0;
	bool _effect = false;
	bool _fire = false;
	bool _poison = false;
	bool _freeze = false;
	int _typeEffect = 0;
	int _type;
public:
	void setDamageWS(int damage);
	int getDamageWS();
	//void setSNameWS(std::string name);
	//std::string getSNameWS();
	void setEffectWS();
	bool EffectActiveWS();
	int getEffectTypeWS();
	void showStatsWS();
	Spells();
	Spells(int type);
	~Spells();
};