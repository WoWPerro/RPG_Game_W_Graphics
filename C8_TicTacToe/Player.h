#pragma once
#include <list>
#include <vector>
#include "DLLObjetos2.h"
#include "Llave.h"
#include "Habitación.h"
#include "Weapon.h"
#include "Spells.h"
#include "TEXTCOUT2.h"
#include <time.h>

class Player
{
public:
	Player();
	Player(std::string name);

private:
	std::string _name;
	int _cuartoActual = 1;
	std::list <DLLObjetos *> _DLLObjetos;
	std::vector <Llave> _llaves;
	int _maxCarga = 100;
	int _cargaActual = 0;
	float _fuerza = 1;
	int _currentMana = 10;
	int _maxMana = 10;
	int _exp = 0;
	int _maxExp = 100;
	int _vida = 100;
	int _maxVida = 100;
	Weapon _currentweapon;
	Spells _currentspell;
public:
	void move(int cuarto);
	void SetCuartoActual(int cuarto);
	int GetCuartoActual();
	void drop(DLLObjetos *);
	void take(DLLObjetos *);
	void takeKey(Llave Llave);
	vector <Llave> GetKeys();
	void takeDamage(int damage);
	int makeDamage();
	int getVida();
	void setVida(int vida);
	void SetWeapon(Weapon &weapon);
	void showInventory(TEXTCOUT2 &main);
	bool SetCargactual(int carga);
	list <DLLObjetos*> &GetObjects();
	string GetName();
	int GetCarga();
	int GetMaxCarga();
	float GetFuerza();
	int GetMana();
	int GetManaMax();
	int GetExp();
	int GetMaxExp();
	int GetMaxVida();
	Weapon GetCurrentWeapon();
	void LevelUp();
	void SetExp(int exp);
	void SetSpells(Spells& spell);
	int makeDamageWhitSpell(TEXTCOUT2 &main);
	~Player();
};

