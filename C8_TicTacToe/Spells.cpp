#include "stdafx.h"
#include "pch.h"
#include "Spells.h"

Spells::Spells()
{
}

void Spells::setEffectWS()
{
	srand(time(0));
	int r = (rand() % 10) + 1;
	if (r == 5)
	{
		_effect = true;
		_typeEffect = (rand() % 3) + 1;
		switch (_typeEffect)
		{
		case 1:
			_fire = true;
			break;

		case 2:
			_poison = true;
			break;

		case 3:
			_freeze = true;
			break;
		}
	}
}

Spells::Spells(int type)
{
	_type = type;
	switch (_type)
	{
	case 1:
		//_spellname = "Hechizo de fuego";
		srand(time(0));
		setDamageWS(rand() % 20);
		setEffectWS();
		//setSNameWS(getSNameWS());
		break;
	}
}

void Spells::setDamageWS(int damage)
{
	_damage = damage;
}

int Spells::getDamageWS()
{
	return _damage;
}

//void Spells::setSNameWS(std::string name)
//{
//	_spellname = name;
//}
//
//std::string Spells::getSNameWS()
//{
//	return _spellname;
//}

int Spells::getEffectTypeWS()
{
	return _typeEffect;
}

bool Spells::EffectActiveWS()
{
	return _effect;
}

void Spells::showStatsWS()
{
	//cout << "Nombre: " << _spellname << endl;
	cout << "Danio: " << _damage << endl;
	cout << "Efecto: " << _effect << endl;
	if (_effect)
	{
		switch (_typeEffect)
		{
		case 1:
			cout << "Efecto: Fire (Fuego) " << endl;
			break;

		case 2:
			cout << "Efecto: Poison (Veneno) " << endl;
			break;

		case 3:
			cout << "Efecto: Freeze (Hielo) " << endl;
			break;
		}
	}
}

Spells::~Spells()
{
}
