#include "stdafx.h"
#include "pch.h"
#include "Weapon.h"

Weapon::Weapon():DLLObjetos()
{
}

void Weapon::setEffect()
{
	srand(time(0));
	int r = (rand() % 10) + 1;
	if (r == 5)
	{ 
		_effect = true;
		_typeEffect = (rand() % 3) + 1;
		switch(_typeEffect)
		{
		case 1:
			_sharp = true;
			break;

		case 2:
			_fire = true;
			break;

		case 3:
			_poison = true;
			break;

		case 4:
			_freeze = true;
			break;
		}
	}
}

Weapon::Weapon(int type) :DLLObjetos()
{
	_type = type;

	if (_type == 1)
	{
		_weaponName = "Khopesh";
		srand(time(0));
		int damage = (rand() % 20) + 6;
		setDamage(damage);
		setEffect();
		SetPeso(10);
		SetName(getWName());
	}

	if (_type == 2)
	{
		_weaponName = "Arco";
		srand(time(0));
		setDamage(rand() % 6);
		switch (rand())
		{
		case 0:
			setDamage(0);
			break;
		case 1:
			setDamage(0);
			break;
		case 2:
			setDamage(15);
			break;
		case 3:
			setDamage(15);
			break;
		case 4:
			setDamage(15);
			break;
		case 5:
			setDamage(15);
			break;
		case 6:
			setDamage(15);
			break;
		}
		setEffect();
		SetPeso(7);
		SetName(getWName());
	}


	if (_type == 3)
	{
		_weaponName = "Cuchillo";
		srand(time(0));
		setDamage(rand() % 10);
		setEffect();
		SetPeso(5);
		SetName(getWName());
	}

	if (_type == 4)
	{
			_weaponName = "Arma especial";
			srand(time(0));
			setDamage(rand() % 40);
			setEffect();
			SetPeso(20);
			SetName(getWName());
	}

}

void Weapon::setDamage(int damage)
{
	_damage = damage;
}

int Weapon::getDamage()
{
	return _damage;
}

void Weapon::setWName(std::string name)
{
	_weaponName = name;
}

std::string Weapon::getWName()
{
	return _weaponName;
}

int Weapon::getEffectType()
{
	return _typeEffect;
}

bool Weapon::EffectActive()
{
	return _effect;
}

void Weapon::showStats(TEXTCOUT2 & main)
{
	cout << "Nombre: " << _weaponName << endl;
	main.addText("Nombre: " + _weaponName + "\n");
	cout << "Danio: " << _damage << endl;
	main.addText("Danio: " + std::to_string(_damage) + "\n");
	cout << "Efecto: " << _effect << endl;
	main.addText("Efecto: " + std::to_string(_effect) + "\n");

	if (_effect)
	{
		switch (_typeEffect)
		{
		case 1:			
			cout << "Efecto: Sharpness (Filo) " << endl;
			main.addText("Efecto: Sharpness(Filo) \n");
			break;

		case 2:
			cout << "Efecto: Fire (Fuego) " << endl;
			main.addText("Efecto: Fire (Fuego) \n");
			break;

		case 3:
			cout << "Efecto: Poison (Veneno) " << endl;
			main.addText("Efecto: Poison (Veneno) \n");
			break;

		case 4:
			cout << "Efecto: Freeze (Hielo) " << endl;
			main.addText("Efecto: Freeze (Hielo) \n");
			break;
		}
	}
	cout << "Peso: " << DLLObjetos::GetPeso() << endl;
	main.addText("Peso: " + std::to_string(DLLObjetos::GetPeso()) + "\n");
}

Weapon::~Weapon()
{
}