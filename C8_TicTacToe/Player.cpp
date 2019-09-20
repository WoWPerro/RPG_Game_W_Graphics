#include "stdafx.h"
#include "pch.h"
#include "Player.h"
#include "TEXTCOUT2.h"

Player::Player()
{
	_cargaActual = 0;
}

Player::Player(std::string name)
{
	_name = name;
}

int Player::GetCuartoActual()
{
	return _cuartoActual;
}

void Player::SetCuartoActual(int cuarto)
{
	_cuartoActual = cuarto;
}

void Player::move(int cuarto)
{
	SetCuartoActual(cuarto);
}

void Player::drop(DLLObjetos* obj)
{
	_DLLObjetos.remove(obj);

}

void Player::take(DLLObjetos * DLLObjetos)
{
	_DLLObjetos.push_back(DLLObjetos);
}

void Player::takeKey(Llave Llave)
{
	_llaves.push_back(Llave);
}

vector <Llave> Player::GetKeys()
{
	return _llaves;
}

void Player::takeDamage(int damage)
{
	_vida -= damage;
}

int Player::makeDamage()
{
	int Result = 0;
	if (_currentweapon.EffectActive())
	{
		if (_currentweapon.getEffectType() == 1)
		{
			srand(time(0));
			Result += (rand() % 10);
			std::cout << "Suma " << Result << " Porque tu " << _currentweapon.GetName() << " contiene SHARPNESS";
		}
	}

	else 
	{
		Result += _currentweapon.getDamage();
	}
	Result *= _fuerza;
	return Result;
}

int Player::getVida()
{
	return _vida;
}

void Player::setVida(int vida)
{
	_vida = vida;
}

void Player::SetWeapon(Weapon &weapon)
{
	_currentweapon = weapon;
}

list <DLLObjetos*> &Player::GetObjects()
{
	return _DLLObjetos;
}

void Player::showInventory(TEXTCOUT2 &main)
{
	list <Weapon*> weaponlist;
	list <Weapon*>::iterator weaponlistitr = weaponlist.begin();
	for (DLLObjetos* DLLObjetos : _DLLObjetos)
	{
		if (DLLObjetos == dynamic_cast<Weapon*>(DLLObjetos))
		{
			weaponlist.insert(weaponlistitr, dynamic_cast<Weapon*>(DLLObjetos));
			if (weaponlistitr != weaponlist.end())
			{
				weaponlistitr++;
			}
		}
	}

	int weaponN = 0;
	cout << "Armas------------------------------------------------" << endl;
	main.addText("Armas------------------------------------------------\n");
	for (weaponlistitr = weaponlist.begin(); weaponlistitr != weaponlist.end(); weaponlistitr++)
	{
		cout << "Arma [" << weaponN << "]------------" << endl;
		main.addText("Arma" + std::to_string(weaponN) + "]-------\n");
		(**weaponlistitr).showStats(main);
		weaponN++;
	}
	cout << "-----------------------------------------------------" << endl;
}

bool Player::SetCargactual(int carga)
{
	_cargaActual += carga;
	if (_cargaActual > _maxCarga)
	{
		return false;
	}
	else
	{
		return true;
	}
}

string Player::GetName()
{
	return _name;
}

int Player::GetExp()
{
	return _exp;
}

int Player::GetCarga()
{
	return _cargaActual;
}

int Player::GetMaxCarga()
{
	return _maxCarga;
}

float Player::GetFuerza()
{
	return _fuerza;
}

int Player::GetMana()
{
	return _currentMana;
}

int Player::GetManaMax()
{
	return _maxMana;
}

int Player::GetMaxExp()
{
	return _maxExp;
}

int Player::GetMaxVida()
{
	return _maxVida;
}

Weapon Player::GetCurrentWeapon()
{
	return _currentweapon;
}

void Player::LevelUp()
{
	_maxCarga = _maxCarga + 10;
	_maxExp = _maxExp + 10;
	_maxMana = _maxMana + 10;
	_maxVida = _maxVida + 10;
	_fuerza += .5f;
	_currentMana = _maxMana;
	_vida = _maxVida;
}

void Player::SetExp(int exp)
{
	_exp = exp;
	if (_exp > _maxExp)
	{
		LevelUp();
		_exp = 0;
	}
}

int Player::makeDamageWhitSpell(TEXTCOUT2 &main)
{
	int Result = 1;
	if (_currentspell.EffectActiveWS())
	{
		if (_currentspell.getEffectTypeWS() == 1)
		{
			if (_currentMana > 10)
			{
				_currentMana -= 10;
				srand(time(0));
				Result += (rand() % 10);
				std::cout << "Suma " << Result << " Porque tu " << " hechizo " << " hizo un efecto de quemadura";
				main.addText("suma " + std::to_string(Result) + "porque te hechizo hizo quemadura\n");
			}
			else
			{
				std::cout << "No tienes suficiente mana" << std::endl;
				main.addText("NO tienes suficiente Mana\n");
			}
			
		}
	}

	if (_currentspell.EffectActiveWS())
	{
		if (_currentspell.getEffectTypeWS() == 2)
		{
			if (_currentMana > 10)
			{
				_currentMana -= 10;
				srand(time(0));
				Result += (rand() % 10);
				std::cout << "Suma " << Result << " Porque tu " << " hechizo " << " hizo un efecto de envenenamiento";
				main.addText("suma " + std::to_string(Result) + "porque te hechizo hizo envenenar\n");
			}
			else
			{
				std::cout << "No tienes suficiente mana" << std::endl;
				main.addText("NO tienes suficiente Mana\n");
			}
		}
	}

	if (_currentspell.EffectActiveWS())
	{
		if (_currentspell.getEffectTypeWS() == 3)
		{
			if (_currentMana > 10)
			{
				srand(time(0));
				Result += (rand() % 10);
				std::cout << "Suma " << Result << " Porque tu " << " hechizo " << " hizo un efecto de hielo";
				main.addText("suma " + std::to_string(Result) + "porque te hechizo hizo hielo\n");
			}
			else
			{
				std::cout << "No tienes suficiente mana" << std::endl;
				main.addText("NO tienes suficiente Mana\n");
			}
		}
	}

	else
	{
		Result += (_currentspell.getDamageWS() * _fuerza);
	}

	return Result;
}

Player::~Player()
{
	
}
