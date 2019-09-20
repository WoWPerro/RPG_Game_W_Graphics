// C8_TicTacToe.cpp : Defines the entry point for the application.
//

//Windows APP
#include "stdafx.h"
#include "C8_TicTacToe.h"
#include <windowsx.h>
#include "TEXTCOUT2.h"

#define MAX_LOADSTRING 100

//RPGGAME
#include "pch.h"
#include "Habitación.h"
#include "Player.h"
#include "Weapon.h"

#include <typeinfo>
#include <iostream>
#include <stdlib.h>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <exception>
#include <set>
#include <string>
#include <fstream>

//DLL
#include "DLLObjetos2.h"

using std::pair;
using std::vector;
using std::multimap;
using std::string;
using std::list;
using std::map;
using std::set;
using std::forward_list;
using std::stringstream;
using std::ofstream;
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using std::to_string;

//=============================================================================================================
//=============================================================================================================
//=============================================================================================================
// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
const int CELL_SIZE = 10;
HICON hIcon1, hIcon2, hIconEye;
HWND TextBox;
HWND Activar;
char textReadead[20];
char coutMessage[100];
RECT rcClient;
HBRUSH hbrWhite, hbrGray;

TEXTCOUT2 main;
bool up = false;
bool down = false;
Player hero("name");
bool win = false;
bool combat = false;
bool dead = false;
bool start = false;
//int LINES = 28;

//-----------------------------For the Scroll------------------------------------
//SCROLLINFO scrollinfo;
//static int xClient;     // width of client area 
//static int yClient;     // height of client area 
//static int xClientMax;  // maximum width of client area 
//
//static int xChar;       // horizontal scrolling unit 
//static int yChar;       // vertical scrolling unit 
//static int xUpper;      // average width of uppercase letters 
//
//static int xPos;        // current horizontal scrolling position 
//static int yPos;        // current vertical scrolling position 
//
//int x, y;               // horizontal and vertical coordinates
//
//int FirstLine;          // first line in the invalidated area 
//int LastLine;           // last line in the invalidated area 
//HRESULT hr;
//size_t abcLength;        // length of an abc[] item 

//------------------------------Dictionary-----------------------------------
multimap <int, string> Diccionario;

//-----------------------------Niveles--------------------------------
list<Habitación> mapa1
{
	Habitación
	(1,
	string(""),
	new list<DLLObjetos*>{new Weapon(1), new Weapon(1)},
	forward_list<Puerta>{Puerta(false, 2, 0)},
	list<Enemy>{},
	vector<Llave>{Llave(0)}),

	Habitación
	(2,
	string("Ves una habitacion siniestra"),
	new list<DLLObjetos*>{new Weapon(3), new Weapon(1)},
	forward_list<Puerta>{Puerta(true, 1, 0), Puerta(true, 3, 1), Puerta(false, 4, 2)},
	list<Enemy>{Enemy(1,1), Enemy(1,2)},
	vector<Llave>{}),

	Habitación
	(3,
	string("Cuidado adelante, te tiemblan las manos"),
	new list<DLLObjetos*>{new Weapon(1), new Weapon(2)},
	forward_list<Puerta>{Puerta(true, 2, 1), Puerta(true, 5, 3)},
	list<Enemy>{Enemy(1,1)},
	vector<Llave>{}),

	Habitación
	(4,
	string("escuchas una voz decir (Vaya, llegaste hasta aqui)"),
	new list<DLLObjetos*>{new Weapon(1), new Weapon(2)},
	forward_list<Puerta>{Puerta(true, 2, 2), Puerta(true, 6, 2), Puerta(true, 7, 2)},
	list<Enemy>{Enemy(2,1),Enemy(2,1),Enemy(2,1)},
	vector<Llave>{}),

	Habitación
	(5,
	string("Sonidos tenebrosos.mp3"),
	new list<DLLObjetos*>{new Weapon(3), new Weapon(1)},
	forward_list<Puerta>{Puerta(true, 3, 3), Puerta(true, 8, 3)},
	list<Enemy>{Enemy(2,1), Enemy(1,2)},
	vector<Llave>{}),

	Habitación
	(6,
	string("Todo esta en ruinas"),
	new list<DLLObjetos*>{new Weapon(2), new Weapon(1)},
	forward_list<Puerta>{Puerta(true, 4, 3), Puerta(true, 9, 3)},
	list<Enemy>{Enemy(1,1), Enemy(1,2)},
	vector<Llave>{}),

	Habitación
	(7,
	string("recuerdas que estas solo"),
	new list<DLLObjetos*>{new Weapon(1), new Weapon(1)},
	forward_list<Puerta>{Puerta(true, 4, 3), Puerta(true, 10, 3)},
	list<Enemy>{Enemy(1,1), Enemy(1,2)},
	vector<Llave>{}),

	Habitación
	(8,
	string("Cuidado si mueres"),
	new list<DLLObjetos*>{new Weapon(1), new Weapon(1)},
	forward_list<Puerta>{Puerta(true, 5, 3), Puerta(true, 11, 3), Puerta(false, 12, 3)},
	list<Enemy>{Enemy(1,1), Enemy(1,2)},
	vector<Llave>{}),
Habitación
	(9,
	string("Ves varios esqueletos tirados, y tratas de no pisarlos"),
	new list<DLLObjetos*>{new Weapon(3), new Weapon(3)},
	forward_list<Puerta>{Puerta(true, 6, 3), Puerta(false, 17, 3)},
	list<Enemy>{Enemy(1,1), Enemy(1,2)},
	vector<Llave>{}),

	Habitación
	(10,
	string("Parece que las paredes están cubiertas de oro"),
	new list<DLLObjetos*>{new Weapon(1), new Weapon(1)},
	forward_list<Puerta>{Puerta(true, 7, 3), Puerta(true, 13, 3)},
	list<Enemy>{Enemy(2,1), Enemy(1,2)},
	vector<Llave>{}),

	Habitación
	(11,
	string("..."),
	new list<DLLObjetos*>{new Weapon(2), new Weapon(1)},
	forward_list<Puerta>{Puerta(true, 8, 3)},
	list<Enemy>{Enemy(1,1), Enemy(1,2)},
	vector<Llave>{Llave(12)}),

	Habitación
	(12,
	string("Escuchas rugidos a lo lejos"),
	new list<DLLObjetos*>{new Weapon(1), new Weapon(1)},
	forward_list<Puerta>{Puerta(true, 8, 3)},
	list<Enemy>{Enemy(1,1), Enemy(1,2)},
	vector<Llave>{Llave(4)}),

	Habitación
	(13,
	string("........"),
	new list<DLLObjetos*>{new Weapon(1), new Weapon(1)},
	forward_list<Puerta>{Puerta(true, 10, 3), Puerta(true, 14, 3)},
	list<Enemy>{Enemy(1, 1), Enemy(1, 2)},
	vector<Llave>{}),

	Habitación
	(14,
	string("esta muy oscuro"),
	new list<DLLObjetos*>{new Weapon(3), new Weapon(2)},
	forward_list<Puerta>{Puerta(true, 13, 3), Puerta(true, 15, 3)},
	list<Enemy>{Enemy(1, 1), Enemy(1, 2)},
	vector<Llave>{}),

	Habitación
	(15,
	string("Hay una antorcha a la mitad de la habitacion"),
	new list<DLLObjetos*>{new Weapon(2), new Weapon(2)},
	forward_list<Puerta>{Puerta(true, 14, 3), Puerta(false, 19, 3), Puerta(false, 16, 3)},
	list<Enemy>{Enemy(2, 1), Enemy(1, 2)},
	vector<Llave>{}),

	Habitación
	(16,
	string("Que pasa? escuchas a lo lejos"),
	new list<DLLObjetos*>{ new Weapon(1), new Weapon(1) },
	forward_list<Puerta>{Puerta(true, 15, 3), Puerta(true, 17, 3)},
	list<Enemy>{Enemy(1, 1), Enemy(1, 2)},
	vector<Llave>{Llave(19)}),
Habitación
	(17,
	string("Axilio Escuchas a lo lejos"),
	new list<DLLObjetos*>{ new Weapon(1), new Weapon(1) },
	forward_list<Puerta>{Puerta(true, 9, 3), Puerta(true, 16, 3), Puerta(false, 18, 3)},
	list<Enemy>{Enemy(2, 1), Enemy(2, 2)},
	vector<Llave>{Llave(16)}),

	Habitación
	(18,
	string("Todo esta muy callado"),
	new list<DLLObjetos*>{ new Weapon(3), new Weapon(2) },
	forward_list<Puerta>{Puerta(true, 20, 3), Puerta(true, 17, 3)},
	list<Enemy>{Enemy(1, 1), Enemy(1, 2)},
	vector<Llave>{}),

	Habitación
	(19,
	string("..."),
	new list<DLLObjetos*>{ new Weapon(1), new Weapon(1) },
	forward_list<Puerta>{Puerta(true, 15, 3), Puerta(true, 21, 3)},
	list<Enemy>{Enemy(1, 1), Enemy(2, 2)},
	vector<Llave>{}),

	Habitación
	(20,
	string("Recuerdas que estas solo"),
	new list<DLLObjetos*>{ new Weapon(1), new Weapon(1) },
	forward_list<Puerta>{Puerta(true, 28, 3), Puerta(true, 22, 3)},
	list<Enemy>{Enemy(1, 1), Enemy(1, 2), Enemy(1, 2)},
	vector<Llave>{}),

	Habitación
	(21,
	string("Huye!"),
	new list<DLLObjetos*>{ new Weapon(2), new Weapon(3) },
	forward_list<Puerta>{Puerta(true, 19, 3)},
	list<Enemy>{Enemy(1, 1), Enemy(2, 2)},
	vector<Llave>{Llave(18)}),

	Habitación
	(22,
	string("..."),
	new list<DLLObjetos*>{ new Weapon(4)},
	forward_list<Puerta>{Puerta(true, 20, 3), Puerta(true, 23, 3)},
	list<Enemy>{Enemy(2, 1), Enemy(2, 2), Enemy(2, 2), Enemy(2, 2), Enemy(3, 2)},
	vector<Llave>{}),

	Habitación
	(23,
	string("Las paredes comienzan a brillar extrañamente"),
	new list<DLLObjetos*>{ new Weapon(1), new Weapon(1) },
	forward_list<Puerta>{Puerta(true, 9, 3), Puerta(true, 16, 3)},
	list<Enemy>{},
	vector<Llave>{}),
};

void StringToLower(string &text)
{
	std::transform(text.begin(), text.end(), text.begin(), [](unsigned char c) { return std::tolower(c); });
}

int countWords(string str)
{
	// breaking input into word using string stream 
	stringstream s(str); // Used for breaking words 
	string word; // to store individual words 

	int count = 0;
	while (s >> word)
		count++;
	return count;
}

void printFrequency(string st)
{
	// each word it mapped to it's frequency 
	map<string, int> FW;
	stringstream ss(st); // Used for breaking words 
	string Word; // To store individual words 

	while (ss >> Word)
		FW[Word]++;

	map<string, int>::iterator m;
	for (m = FW.begin(); m != FW.end(); m++)
		cout << m->first << " -> "
		<< m->second << "\n";
}

void searchMinorDoor(list<Habitación> mapa1, Habitación H, int n, Player &hero)
{
	bool found = false;
	Habitación h2;
	int r = 0;
	int m = 0;
	int o = 0;
	int o2 = 0;
	list<Habitación>::iterator mapa1itr;
	std::forward_list <Puerta> puertas;
	std::forward_list <Puerta>::iterator puertasitr;

	puertas = H.Getpuertas();
	for (puertasitr = puertas.begin(); puertasitr != puertas.end(); puertasitr++)
	{
		if (!found)
		{
			if (puertasitr->GetID() == n)
			{
				found = true;
				hero.move(n);
				for (mapa1itr = mapa1.begin(); mapa1itr != mapa1.end(); mapa1itr++)
				{
					if (mapa1itr->GetNumH() == n)
					{
						mapa1itr->LeerHabitacion(main);
					}
				}
			}
		}


		r = puertasitr->GetID() - n;
		if (m > r)
		{
			m = r;
			o2 = o;
		}
		o++;
	}

	if (!found)
	{
		puertasitr = puertas.begin();
		std::advance(puertasitr, o2);
		if (puertasitr->GetAbierta())
		{
			if (puertasitr->GetID() == hero.GetCuartoActual() || puertasitr->GetID() == n)
			{
				hero.move(n);
				for (mapa1itr = mapa1.begin(); mapa1itr != mapa1.end(); mapa1itr++)
				{
					if (mapa1itr->GetNumH() == n)
					{
						mapa1itr->LeerHabitacion(main);
					}
				}
			}
			else
			{
				for (mapa1itr = mapa1.begin(); mapa1itr != mapa1.end(); mapa1itr++)
				{
					if (puertasitr->GetID() == mapa1itr->GetNumH())
					{
						h2 = *mapa1itr;
					}
				}
				try
				{
					searchMinorDoor(mapa1, h2, n, hero);
				}
				catch (std::exception& e)
				{
					std::cout << "==========EXCEPTION: " << e.what() << '\n';					
				}
			}

		}
		else
		{
			cout << "El camino está cerrado, no puedes pasar, hay una puerta bloqueada en la habitación: " << H.GetNumH() << endl;
			main.addText("El camino está cerrado, no puedes pasar, hay una puerta bloqueada en la habitación: " + std::to_string(H.GetNumH()) + '\n');
		}
	}

}

void cambiarcuarto(int n, Player& hero, list<Habitación> mapa1)
{
	int r = 0;
	int m = 0;
	int o = 0;
	int o2 = 0;
	std::forward_list <Puerta> puertas;
	std::forward_list <Puerta>::iterator puertasitr;
	hero.GetCuartoActual();
	list<Habitación>::iterator mapa1itr = mapa1.begin();
	list<Habitación>::iterator mapa1itr2 = mapa1.begin();

	for (mapa1itr = mapa1.begin(); mapa1itr != mapa1.end(); mapa1itr++)
	{
		//if (mapa1itr->GetNumH() == hero.GetCuartoActual())
		if (mapa1itr->GetNumH() == 1)
		{
			mapa1itr2 = mapa1itr;
		}
	}

	//for (mapa1itr = mapa1.begin(); mapa1itr != mapa1.end(); mapa1itr++)
	//{
		//if (n == mapa1itr->GetNumH())
		//if (n == hero.GetCuartoActual())
	try
	{
		searchMinorDoor(mapa1, *mapa1itr2, n, hero);
	}
	catch (std::exception& e)
	{
		std::cout << "==========EXCEPTION: " << e.what() << '\n';
	}
}

void nextRoom(list<Habitación> &mapa1, int n, Player &hero)
{
	int maxH = 0;
	bool aprove = false;
	bool open = false;
	std::forward_list <Puerta> puertas;
	std::forward_list <Puerta>::iterator puertasitr;
	list<Habitación>::iterator mapa1itr = mapa1.begin();
	for (mapa1itr = mapa1.begin(); mapa1itr != mapa1.end(); mapa1itr++)
	{
		maxH++;
		if (mapa1itr->GetNumH() == hero.GetCuartoActual())
		{
			puertas = mapa1itr->Getpuertas();
		}
	}

	for (puertasitr = puertas.begin(); puertasitr != puertas.end(); puertasitr++)
	{
		if (puertasitr->GetID() == n)
		{
			aprove = true;
		}
	}

	if (aprove)
	{
		for (puertasitr = puertas.begin(); puertasitr != puertas.end(); puertasitr++)
		{
			if (puertasitr->GetID() == n && puertasitr->GetAbierta())
			{
				open = true;
				hero.move(n);
			}
		}

		if (open)
		{
			for (mapa1itr = mapa1.begin(); mapa1itr != mapa1.end(); mapa1itr++)
			{
				if (mapa1itr->GetNumH() == n)
				{
					mapa1itr->LeerHabitacion(main);
				}
			}
		}
		else
		{
			cout << "La puerta esta cerrada, busca la llave, o si la tienes, abre la puerta" << endl;
			main.addText("La puerta esta cerrada, busca la llave, o si la tienes, abre la puerta \n");
		}
	}

	else
	{
		if (n == hero.GetCuartoActual())
		{
			cout << "Estas en a habitacion " << n << endl;
			main.addText("Estas en a habitacion " + std::to_string(n) + '\n');
		}
		else if (n > maxH) {
			cout << "La habitacion " << n << " no existe\n" << endl;
			main.addText("la habitacion no existe ingresaste el num " + std::to_string(n) + '\n');
		}
		else {
			cout << "La habitacion " << n << " esta muy lejos para que llegues a ella" << endl;
			main.addText("la habitacion esta muy lejos para que llegues \n");
		}

	}
}

void DictionarySearch2(string text, multimap <int, string> Diccionario, Player &hero, list<Habitación> &mapa1, bool battle)
{
	bool foundTheWord = false;
	//cout << text << endl;
	StringToLower(text);
	//cout << "N of words is: " << countWords(text) << endl;
	//printFrequency(text);

	vector <string> StringList;
	string key;
	string::iterator it;
	it = key.begin();
	stringstream ss(text); // Used for breaking words 
	string Word; // To store individual words 

	while (ss >> Word)
		StringList.push_back(Word);
	//FW[Word]++;

	vector<string>::iterator i;
	multimap <int, string>::iterator j;
	key = key + " ";
	for (i = StringList.begin(); i != StringList.end(); i++)
	{
		for (j = Diccionario.begin(); j != Diccionario.end(); j++)
		{
			if (i->compare(j->second) == 0)
			{
				key = key + std::to_string(j->first) + " ";
			}
		}
	}
	key = key + " ";
	//cout << "Keywords in key are: " << key << endl;

	string keys; // To store individual words 

	std::size_t found = key.find(" 1 ");
	if (found != string::npos)
	{
		foundTheWord = true;
		if (!battle)
		{
			cout << "Cambiando de cuarto" << '\n';
			bool foundNumber = false;
			for (i = StringList.begin(); i != StringList.end(); i++)
			{
				if (i->find_first_of("0123456789") == 0)
				{
					foundNumber = true;
					//hero.move(std::stoi(*i));
					try
					{
						//cambiarcuarto(stoi(*i), hero, mapa1);
						nextRoom(mapa1, stoi(*i), hero);
					}
					catch (std::exception& e)
					{
						std::cout << "==========EXCEPTION: " << e.what() << '\n';
					}

				}
			}
			if (!foundNumber)
			{
				cout << "Por favor especifique un numero de habitacion con numero [ej(1) no(uno)]" << endl;
				main.addText("Por favor especifique un numero de habitacion con numero [ej(1) no(uno)]\n");
			}
		}
		else
		{
			cout << "No puedes cambiar de cuarto durante una batalla" << endl;
			main.addText("No puedes cambiar de cuarto durante una batalla\n");
		}
	}

	found = key.find(" 2 3 ");
	if (found != string::npos)
	{
		foundTheWord = true;
		if (!battle)
		{
			cout << "Abriendo puerta" << '\n';
			main.addText("Intentando abrir puerta\n");
			bool foundNumber = false;
			list<Habitación>::iterator mapa1itr;
			std::forward_list <Puerta> *puertas = NULL;
			std::forward_list <Puerta>::iterator puertasitr;
			std::vector <Llave> _llaves;
			std::vector <Llave>::iterator llavesitr;
			bool foundoor = false;
			bool truekey = false;

			std::vector <std::string>::iterator i = StringList.begin();

			for (i = StringList.begin(); i != StringList.end(); i++)
			{
				if (i->find_first_of("0123456789") == 0)
				{
					foundNumber = true;
					for (mapa1itr = mapa1.begin(); mapa1itr != mapa1.end(); mapa1itr++)
					{
						if (mapa1itr->GetNumH() == hero.GetCuartoActual())
						{
							puertas = &(mapa1itr->Getpuertas());
						}
					}

					_llaves = hero.GetKeys();

					for (puertasitr = puertas->begin(); puertasitr != puertas->end(); puertasitr++)
					{
						if (puertasitr->GetID() == stoi(*i))
						{
							foundoor = true;
							for (llavesitr = _llaves.begin(); llavesitr != _llaves.end(); llavesitr++)
							{
								if (puertasitr->GetKey() == llavesitr->GetID())
								{
									puertasitr->SetAbierta(true);
									truekey = true;
								}
							}

						}
					}
				}
			}
			if (!foundNumber)
			{
				cout << "Por favor especifique un numero de habitacion con numero [ej(1) no(uno)]" << endl;
				main.addText("Por favor especifique un numero de habitacion con numero [ej(1) no(uno)]\n");
			}
			if (!foundoor && foundNumber)
			{
				cout << "No esta la puerta que te lleva al cuarto que especificaste" << endl;
				main.addText("No esta la puerta que te lleva al cuarto que especificaste\n");
			}
			if (foundoor && !truekey)
			{
				cout << "No tienes la llave en tu inventario, buscala en el mapa" << endl;
				main.addText("No tienes la llave en tu inventario, buscala en el mapa\n");
			}
		}

	}

	found = key.find(" 5 ");
	if (found != string::npos)
	{
		foundTheWord = true;
		cout << "Atacar" << '\n';
		for (i = StringList.begin(); i != StringList.end(); i++)
		{
			if (i->find_first_of("0123456789") == 0)
			{
				list<Habitación>::iterator mapa1itr;
				list<Enemy> *enemigosActuales = NULL;

				for (mapa1itr = mapa1.begin(); mapa1itr != mapa1.end(); mapa1itr++)
				{
					if (mapa1itr->GetNumH() == hero.GetCuartoActual())
					{
						enemigosActuales = (&(mapa1itr->GetEnemies()));
					}
				}

				list<Enemy>::iterator enemigosActualesitr;
				for (enemigosActualesitr = (*enemigosActuales).begin(); enemigosActualesitr != (*enemigosActuales).end(); enemigosActualesitr++)
				{
					if (enemigosActualesitr->Getid() == stoi(*i))
					{
						int finalhealth = enemigosActualesitr->GetVida() - hero.makeDamage();
						enemigosActualesitr->SetVida(finalhealth);
						if (enemigosActualesitr->GetVida() <= 0)
						{
							enemigosActualesitr->setAlive(false);
						}
					}
				}
			}
		}
	}

	found = key.find(" 6 ");
	if (found != string::npos)
	{
		foundTheWord = true;
		bool foundTheNumber = false;
		cout << "Equipar" << '\n';
		for (i = StringList.begin(); i != StringList.end(); i++)
		{
			if (i->find_first_of("0123456789") == 0)
			{
				foundTheNumber = true;
				bool foundWeapon = false;
				list <DLLObjetos*> heroObjects = hero.GetObjects();
				list <DLLObjetos*>::iterator heroObjectsitr;
				list <Weapon*> weaponlist;
				list <Weapon*>::iterator weaponlistitr = weaponlist.begin();
				for (DLLObjetos* DLLObjetos : heroObjects)
				{
					if (DLLObjetos == dynamic_cast<Weapon*>(DLLObjetos))
					{
						weaponlist.insert(weaponlistitr, dynamic_cast<Weapon*>(DLLObjetos));
						if (weaponlistitr != weaponlist.end())
						{
							weaponlistitr++;
						}

						int weaponN = 0;
						for (weaponlistitr = weaponlist.begin(); weaponlistitr != weaponlist.end(); weaponlistitr++)
						{
							if (stoi(*i) == weaponN)
							{
								hero.SetWeapon(**weaponlistitr);
								foundWeapon = true;
								cout << "Equipaste el arma: " << endl;
								main.addText("Equipaste el arma: \n");
								(**weaponlistitr).showStats(main);
							}
							weaponN++;
						}
						if (!foundWeapon)
						{
							cout << "No encontre tu arma numero [" << *i << "] En tu inventario, puedes desplegar el inventario para averiguar qué tienes" << endl;
							main.addText("No encontre tu arma en tu inventario, porque no despliegas tu inventario para ver que tienes");
						}
					}
				}
			}
		}
		if (!foundTheNumber)
		{
			cout << "Por favor especifica un numero Ej. (Equipar 5)" << endl;
			main.addText("Por favor especifica un numero Ej. (Equipar 5)\n");
		}
	}

	found = key.find(" 7 ");
	if (found != string::npos)
	{
		foundTheWord = true;
		cout << "Mostrando inventario" << '\n';
		main.addText("Mostrando inventario \n");
		hero.showInventory(main);
	}

	found = key.find(" 8 9 ");
	if (found != string::npos)
	{
		foundTheWord = true;
		bool foundTheNumber = false;
		cout << "tomar" << '\n';
		for (i = StringList.begin(); i != StringList.end(); i++)
		{
			if (i->find_first_of("0123456789") == 0)
			{
				foundTheNumber = true;
				list<Habitación>::iterator mapa1itr;
				vector<Llave>::iterator LLaveitr;
				vector<Llave> *Llaves = NULL;
				int counter = 0;
				bool open = false;

				for (mapa1itr = mapa1.begin(); mapa1itr != mapa1.end(); mapa1itr++)
				{
					if (mapa1itr->GetNumH() == hero.GetCuartoActual())
					{
						Llaves = &(mapa1itr->GetLlaves());
					}
				}

				for (LLaveitr = Llaves->begin(); LLaveitr != Llaves->end(); LLaveitr++)
				{
					if (stoi(*i) == counter)
					{
						hero.takeKey(*LLaveitr);
						open = true;
					}
					counter++;
				}

				LLaveitr = Llaves->begin();
				try
				{
					if (open)
					{
						Llaves->erase(LLaveitr);
					}
				}
				catch (...)
				{

				}
			}
		}

		if (!foundTheNumber)
		{
			cout << "Por favor especifica un numero Ej. (Equipar 5)" << endl;
			main.addText("Por favor especifica un numero Ej. (Equipar 5) \n");
		}
	}

	found = key.find(" 8 10 ");
	if (found != string::npos)
	{
		foundTheWord = true;
		bool foundTheNumber = false;
		cout << "tomar" << '\n';
		for (i = StringList.begin(); i != StringList.end(); i++)
		{
			if (i->find_first_of("0123456789") == 0)
			{
				foundTheNumber = true;
			}
		}
	}

	found = key.find(" 8 11 ");
	if (found != string::npos)
	{
		foundTheWord = true;
		bool foundTheNumber = false;
		cout << "tomar" << '\n';
		for (i = StringList.begin(); i != StringList.end(); i++)
		{
			if (i->find_first_of("0123456789") == 0)
			{
				foundTheNumber = true;
				list<Habitación>::iterator mapa1itr;
				list<Habitación>::iterator mapa1itr2;
				list <Weapon*> weaponlist;
				list <DLLObjetos*> *Objetlist;
				for (mapa1itr = mapa1.begin(); mapa1itr != mapa1.end(); mapa1itr++)
				{
					if (mapa1itr->GetNumH() == hero.GetCuartoActual())
					{
						weaponlist = mapa1itr->GetWeapons();
						Objetlist = mapa1itr->GetDLLObjetos();
						mapa1itr2 = mapa1itr;
					}
				}

				list <Weapon*>::iterator weaponlistitr = weaponlist.begin();
				int weaponN = 0;
				for (weaponlistitr = weaponlist.begin(); weaponlistitr != weaponlist.end(); weaponlistitr++)
				{
					if (weaponN == stoi(*i))
					{
						if (hero.SetCargactual((*weaponlistitr)->GetPeso()))
						{
							hero.take(*weaponlistitr);
							try
							{
								mapa1itr2->Remove(*weaponlistitr);
							}
							catch (std::exception e)
							{
								std::cout << " a standard exception was caught, with message '" << e.what() << "\n";
							}
						}

						else
						{
							cout << "Tienes demasiados objetos, tira alguno si quieres obtener este, su peso es [" << (*weaponlistitr)->GetPeso() << "]" << endl;
							main.addText("Tienes demasiados objetos, tira alguno si quieres obtener este, su peso es [" + std::to_string((*weaponlistitr)->GetPeso()) + '\n');
						}

					}
					weaponN++;
				}



			}
		}
	}

	found = key.find(" 12 ");
	if (found != string::npos)
	{
		foundTheWord = true;
		list<Habitación>::iterator mapa1itr;
		for (mapa1itr = mapa1.begin(); mapa1itr != mapa1.end(); mapa1itr++)
		{
			if (mapa1itr->GetNumH() == hero.GetCuartoActual())
			{
				mapa1itr->setRead(false);
				mapa1itr->LeerHabitacion(main);
			}
		}
	}

	found = key.find(" 14 ");
	if (found != string::npos)
	{
		foundTheWord = true;		
		ofstream save;
		std::ofstream ofile("SaveFile.bin", std::ios::binary);		

		//Habitacion
		int num = 0;
		bool playerEnters = false;
		bool read = false;
		string descripcion;
		std::list <DLLObjetos*>* DLLObjetoslist;
		std::list <DLLObjetos*>::iterator DLLObjetositr;
		std::vector <Llave> llaves;
		std::vector <Llave>::iterator llavesitr;
		std::forward_list <Puerta> puertas;
		std::forward_list <Puerta>::iterator puertasitr;
		std::list <Enemy> enemigos;
		std::list <Enemy>::iterator enemigositr;

		list<Habitación>::iterator mapa1itr;
		for (mapa1itr = mapa1.begin(); mapa1itr != mapa1.end(); mapa1itr++)
		{
			DLLObjetoslist = mapa1itr->GetDLLObjetos();
			llaves = mapa1itr->GetLlaves();
			puertas = mapa1itr->Getpuertas();
			enemigos = mapa1itr->GetEnemies();

			for (DLLObjetositr = DLLObjetoslist->begin(); DLLObjetositr != DLLObjetoslist->end(); DLLObjetositr++)
			{
				ofile.write((char*)&DLLObjetositr, sizeof(DLLObjetos*));
			}

			for (llavesitr = llaves.begin(); llavesitr != llaves.end(); llavesitr++)
			{
				ofile.write((char*)&llavesitr, sizeof(Llave));
			}

			for (puertasitr = puertas.begin(); puertasitr != puertas.end(); puertasitr++)
			{
				ofile.write((char*)&puertasitr, sizeof(Puerta));
			}

			for (enemigositr = enemigos.begin(); enemigositr != enemigos.end(); enemigositr++)
			{
				ofile.write((char*)&enemigositr, sizeof(Enemy));
			}

			num = mapa1itr->GetNumH();
			ofile.write((char*)&num, sizeof(int));

			playerEnters = mapa1itr->GetplayerEnters();
			ofile.write((char*)&playerEnters, sizeof(bool));

			read = mapa1itr->Getread();
			ofile.write((char*)&read, sizeof(bool));

			descripcion = mapa1itr->Getdescripcion();
			ofile.write((char*)&descripcion, sizeof(string));
		}

		std::string name = hero.GetName();
		int cuartoActual = hero.GetCuartoActual();		
		int fuerzaCarga = hero.GetMaxCarga();
		int cargaActual = hero.GetCarga();
		float fuerza = hero.GetFuerza();
		int currentMana = hero.GetMana();
		int maxMana = hero.GetManaMax();
		int exp = hero.GetExp();
		int maxExp = hero.GetMaxExp();
		int vida = hero.getVida();
		int maxVida = hero.GetMaxVida();
		Weapon currentweapon = hero.GetCurrentWeapon();
		std::list <DLLObjetos *> DLLObjetosPlayer = hero.GetObjects();
		std::vector <Llave> _llaves = hero.GetKeys();

		ofile.write((char*)&name, sizeof(string));
		ofile.write((char*)&cuartoActual, sizeof(int));
		ofile.write((char*)&fuerzaCarga, sizeof(int));
		ofile.write((char*)&cargaActual, sizeof(int));
		ofile.write((char*)&fuerza, sizeof(float));
		ofile.write((char*)&currentMana, sizeof(int));
		ofile.write((char*)&maxMana, sizeof(int));
		ofile.write((char*)&exp, sizeof(int));
		ofile.write((char*)&maxExp, sizeof(int));
		ofile.write((char*)&vida, sizeof(int));
		ofile.write((char*)&maxVida, sizeof(int));
		ofile.write((char*)&currentweapon, sizeof(Weapon));

	}

	found = key.find(" 15 ");
	if (found != string::npos)
	{
		foundTheWord = true;
		ifstream savedFile;
		savedFile.open("SaveFile.dat", std::ios::in);
		if (!savedFile.fail()) 
		{
			
		}
	}

	found = key.find(" 16 17 18 ");
	if (found != string::npos)
	{
		foundTheWord = true;
		cout << "Atacar con hechizo" << '\n';
		main.addText("Atacando con hechizo \n");
		for (i = StringList.begin(); i != StringList.end(); i++)
		{
			if (i->find_first_of("0123456789") == 0)
			{
				list<Habitación>::iterator mapa1itr;
				list<Enemy>* enemigosActuales = NULL;

				for (mapa1itr = mapa1.begin(); mapa1itr != mapa1.end(); mapa1itr++)
				{
					if (mapa1itr->GetNumH() == hero.GetCuartoActual())
					{
						enemigosActuales = (&(mapa1itr->GetEnemies()));
					}
				}

				list<Enemy>::iterator enemigosActualesitr;
				for (enemigosActualesitr = (*enemigosActuales).begin(); enemigosActualesitr != (*enemigosActuales).end(); enemigosActualesitr++)
				{
					if (enemigosActualesitr->Getid() == stoi(*i))
					{
						int finalhealth = enemigosActualesitr->GetVida() - hero.makeDamageWhitSpell(main);
						enemigosActualesitr->SetVida(finalhealth);
						if (enemigosActualesitr->GetVida() <= 0)
						{
							enemigosActualesitr->setAlive(false);
						}
					}
				}
			}
		}
	}

	if (!foundTheWord)
	{
		cout << "No se encontro el comando, intenta de nuevo o ingresa Help para ver mas opciones" << '\n';
		main.addText("No se encontro el comando, intenta de nuevo o ingresa Help para ver mas opciones \n");
	}
}

bool CheckEnemy(list<Habitación> &mapa1, int n)
{
	std::list <Enemy> _enemigos;
	std::list <Enemy>::iterator enemigositr;
	list<Habitación>::iterator mapa1itr;
	for (mapa1itr = mapa1.begin(); mapa1itr != mapa1.end(); mapa1itr++)
	{
		if (mapa1itr->GetNumH() == n)
		{
			_enemigos = mapa1itr->GetEnemies();
			if (_enemigos.size() != 0)
			{
				for (enemigositr = _enemigos.begin(); enemigositr != _enemigos.end(); enemigositr++)
				{
					if (enemigositr->isAlive())
					{
						return true;
					}
				}
				return false;
			}
		}
	}
	return false;
}


BOOL GetGameBoardRect(HWND hWnd, RECT *pRect)
{
	RECT rc;
	if (GetClientRect(hWnd, &rc))
	{
		int width = rc.right - rc.left;
		int height = rc.bottom - rc.top;
		pRect->left = (width - CELL_SIZE * 3) / 2;
		pRect->top = (height - CELL_SIZE * 3) / 2;
		pRect->right = (pRect->left + CELL_SIZE * 3);
		pRect->bottom = (pRect->top + CELL_SIZE * 3);
	}
	return TRUE;
}

void DrawLine(HDC hdc, int x1, int y1, int x2, int y2)
{
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
}

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR   lpCmdLine,  _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.
	//MovePlayer
	Diccionario.insert(pair <int, string>(1, "cambiar"));
	Diccionario.insert(pair <int, string>(1, "cambiarme"));
	Diccionario.insert(pair <int, string>(1, "mover"));
	Diccionario.insert(pair <int, string>(1, "moverme"));
	Diccionario.insert(pair <int, string>(1, "ir"));
	Diccionario.insert(pair <int, string>(1, "caminar"));
	Diccionario.insert(pair <int, string>(1, "transladarse"));
	Diccionario.insert(pair <int, string>(1, "transladar"));
	Diccionario.insert(pair <int, string>(1, "transladarme"));
	Diccionario.insert(pair <int, string>(1, "pasar"));
	Diccionario.insert(pair <int, string>(1, "pasarme"));

	//Abrir
	Diccionario.insert(pair <int, string>(2, "abrir"));
	Diccionario.insert(pair <int, string>(3, "puerta"));
	Diccionario.insert(pair <int, string>(4, "cofre"));

	//Atacar
	Diccionario.insert(pair <int, string>(5, "atacar"));
	Diccionario.insert(pair <int, string>(5, "matar"));
	Diccionario.insert(pair <int, string>(5, "pegarle"));

	//Equipar
	Diccionario.insert(pair <int, string>(6, "equipar"));

	//Mostrar Inventario
	Diccionario.insert(pair <int, string>(7, "mostrar"));
	Diccionario.insert(pair <int, string>(7, "enseñar"));
	Diccionario.insert(pair <int, string>(7, "inventario"));
	Diccionario.insert(pair <int, string>(7, "DLLObjetos"));

	//Tomar
	Diccionario.insert(pair <int, string>(8, "tomar"));
	Diccionario.insert(pair <int, string>(8, "agarrar"));
	Diccionario.insert(pair <int, string>(8, "obtener"));
	Diccionario.insert(pair <int, string>(9, "llave"));
	Diccionario.insert(pair <int, string>(10, "DLLObjetos"));
	Diccionario.insert(pair <int, string>(11, "espada"));
	Diccionario.insert(pair <int, string>(11, "arma"));

	//Mapa
	Diccionario.insert(pair <int, string>(12, "leer"));

	//curarse	

	//Dropear
	Diccionario.insert(pair <int, string>(13, "Dropear"));

	//Hechizo
	Diccionario.insert(pair <int, string>(16, "lanzar"));
	Diccionario.insert(pair <int, string>(17, "hechizo"));
	Diccionario.insert(pair <int, string>(18, "ofensivo"));
	Diccionario.insert(pair <int, string>(18, "de ataque"));


	//Experiencia

	//Vida

	//Stats

	//Help



	//---------------------------------------------------------------------------

		//---------------------------------------------------------------------------
		//Referencias: 
		//https://cadiz.nueva-acropolis.es/cadiz-articulos/civilizaciones-antiguas/14779-el-increible-viaje-del-sol-el-libro-de-la-duat-3267
		//https://www.historiarum.es/news/el-egipcio-libro-de-los-muertos-por-talia-lizandra-sierra-/
		//https://es.wikipedia.org/wiki/Libro_del_Amduat
		//https://es.wikipedia.org/wiki/Libro_de_los_muertos
		//https://es.wikipedia.org/wiki/Libro_de_las_Puertas
		//https://es.wikipedia.org/wiki/Duat
		//---------------------------------------------------------------------------


	/*
	De ley:
	Funciones en la Clase Player
		1.- Cambiarse de Habitación
		1.1.- Abrir la puerta
		1.2.- Desbloquear la puerta (si está cerrada)
		2.- Recoger DLLObjetos
		2.1.- Recoger Escudo
		2.2.- Recoger Espada
		2.3.- Recoger Llave
		2.4.- Intercambio de Escudo
		2.5.- Intercambio de Espada
		2.6.- Intercambio de Llave
		3.- Atacar
		3.1.- Enemigo minion
		3.2.- Enemigo Chido
		3.3.- Enemigo Boss
		4.- Defensa automática
		5.- Consultar su Inventario
		6.- Tirar DLLObjetos
		7.- Información de la habitación
		8.- Lootear enemigos
		8.1.- Ver una lista de DLLObjetos que dropeó
		8.2.- Tomar los DLLObjetos que quiera
		8.3.- Agregar una lista en la clase enemigo que almacene una
		lista de strings, donde están especificados los elementos
		que dropea para craftear
		9.- Curarse (agregar el item de poti, la subclase, pues)
		10.- Craftear pociones y alimentos para curarse
		11.- Recetario de cosas que puede craftear, y qué necesita.
	Mecánicas:
	-Spells
	->Peso para cargar
	-Crear Personaje
	-Elegir mejoras
	Narrativa:
	-Viaje al inframundo Egipcio
	Enemigos:
	-Sirvientes de APAP (Dios Griego del caos y el desánimo)
	*/	

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_C8TICTACTOE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_C8TICTACTOE));

    MSG msg;

    // Main message loop (Update de cosas):
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW ;
	//wcex.style = (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX);
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON2));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW); //Cambiar el cursor
	//wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
	wcex.hbrBackground = (HBRUSH)(GetStockObject(GRAY_BRUSH));
	//wcex.hbrBackground  = (HBRUSH)(GetStockObject(GRADIENT_FILL_TRIANGLE));
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDI_ICON2);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON2));

	return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
   ::SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE)&~WS_SIZEBOX);
   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//

int GetCellNumberFromPoint(HWND hWnd, int x, int y)
{
	RECT rc;
	POINT pt = { x,y };
	if (GetGameBoardRect(hWnd, &rc))
	{
		if (PtInRect(&rc, pt))
		{
			x = pt.x - rc.left;
			y = pt.y - rc.top;
			int column = x / CELL_SIZE;
			int row = y / CELL_SIZE;
			return column + row * 3;
		}
	}
	return -1;
}

//BOOL GetCellRect(HWND hWnd, int index, RECT* pRect)
//{
//	RECT rcBoard;
//	SetRectEmpty(pRect);
//	if (index < 0 || index > 8) return false;
//	if (GetGameBoardRect(hWnd, &rcBoard))
//	{
//		int y = index / 3;
//		int x = index % 3;
//		pRect->left = rcBoard.left + x * CELL_SIZE;
//		pRect->top = rcBoard.top + y * CELL_SIZE;
//		pRect->right = pRect->left + CELL_SIZE;
//		pRect->bottom = pRect->top + CELL_SIZE;
//		return TRUE;
//	}
//	return FALSE;
//}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_CREATE: {

			hbrWhite = (HBRUSH)GetStockObject(WHITE_BRUSH);
			hbrGray = (HBRUSH)GetStockObject(GRAY_BRUSH);

			hIcon1 = LoadIcon(hInst, MAKEINTRESOURCE(IDI_SMALL));
			hIcon1 = LoadIcon(hInst, MAKEINTRESOURCE(IDI_C8TICTACTOE));
			//hIconEye = LoadIcon(hInst, MAKEINTRESOURCE(IDI_C8TICTACTOE));

			if (GetClientRect(hWnd, &rcClient))
			{
				TextBox = CreateWindowA("EDIT", "", WS_BORDER | WS_CHILD | WS_VISIBLE, (rcClient.right / 2) - 500, rcClient.bottom - 20, 1000, 20, hWnd, NULL, NULL, NULL);
			}
			Activar = CreateWindowA("BUTTON", "ACTIVAR", WS_VISIBLE | WS_CHILD | WS_BORDER, (rcClient.right / 2) + 510, rcClient.bottom - 20, 70, 20, hWnd, (HMENU)1, NULL, NULL);
			//HWND hWndExample = CreateWindowA("STATIC", "Text Goes Here \nText is still here", WS_VISIBLE | WS_CHILD | SS_LEFT, 100, 100, 500, 200, hWnd, NULL, NULL, NULL);
			//SetWindowText(hWndExample, TEXT("Control string"));
			TEXTCOUT2 MAIN("Bienvenido\n");
			main = MAIN;
			main.addText("Este juego se juega escribiendo lo que quieres hacer\n");
			main.addText("El mapa se encuentra en la parte superior izquierda\n");
			main.addText("Si quieres hacer Scroll al texto para ver tu progreso, puedes apretar las flechas Arriba o Abajo\n");
			main.addText("Ten mucho cuidado cuando estés en combate, la GUI va a cambiar para indicarte que estas en peligro\n");
			main.addText("Cuidado con lo que escribes cuando estes en combate, si te equivocas los enemigos se aprovecharan de ello!\n");
			main.addText("No dudes en Buscar Ayuda en las opciones\n");
			main.addText("Cualquier fallo o bug Favor de Reportarlo al correo [carlo.relion@saei.mx]\n");
			main.addText("Ahora sin mas que decir\n");
			main.addText("A disfrutar ¡La maldicion de APAP!\n");
			main.addText("Te despiertas, no entiendes que pasa\n");
			main.addText("Que habra pasado?\n");
			main.addText("a tu alrededor ves dos armas y una llave tirada en el piso\n");
			main.addText("todo esta sospechosamente impecable\n");
			main.addText("habias escuchado las historias\n");
			main.addText("pero no creias que fueran ciertas\n");
			main.addText("(no creo que haya pasado) piensas\n");
			main.addText("(no puede ser!)\n");
			main.addText("te levantas, te sientes muy ligero\n");
			main.addText("tratas de recordar lo que hiciste ayer pero no puedes\n");
			main.addText("vislumbras una puerta delante de ti, la intentas abrir pero esta cerrada con llave\n");
			main.addText("te asustas, crees que no vas a poder salir\n");
			main.addText("Que raro\n");
			main.addText("Me siento demasiado extrano\n");
			main.addText("en las paredes observas siimbolos, ya los habias visto antes\n");
			main.addText("(Scrollea hacia abajo) =============================\n");
			main.addText("te acercas para ver que dicen\n");
			main.addText("Alcanzas a leer: Aqui yacen todos aquellos que son puestos a prueba\n");
			main.addText("Despues de un momento decides hacer algo:\n");
			break;
		}

		case WM_COMMAND:
		{			
			int wmId = LOWORD(wParam);
			// Parse the menu selections:
			switch (wmId)
			{
				case 1:
				{
					if (start)
					{
						main.SetIndex(main.size() - 25);
					}
					start = true;
					int length = GetWindowTextLength(TextBox) + 1;
					GetWindowTextA(TextBox, textReadead, length);

					//-----------------------------Player----------------------------------
					//------------------------------GAME-----------------------------------
					list<Habitación>::iterator mapa1itr = mapa1.begin();
					
					string name, dummy;
					//cout << "Pon el nombre de tu heroe: " << endl;
					//cin >> name;
					//getline(cin, dummy);
					//cout << "Bienvenido " << name << endl;
					mapa1itr->LeerHabitacion(main);

					//string text;
					if (win == false)
					{
						combat = CheckEnemy(mapa1, hero.GetCuartoActual());

						if (combat == false && win == false && dead == false)
						{							
							//getline(std::cin, text);
							try
							{
								DictionarySearch2(textReadead, Diccionario, hero, mapa1, false);
								if (hero.GetCuartoActual() == 23)
								{
									cout << "GANASTE" << endl;
									main.addText("Lo logre! eh ganado la inmortalidad \n");
									main.addText("Podre al fin vivir con los faraones \n");
									main.addText("Podre al fin descansar \n");
									main.addText("En eso te empiezas a desvancer \n");
									main.addText("Lo logré te repites \n");
									main.addText("lo...lo....gre.... \n");
									main.addText("... \n");
									main.addText("... \n");
									main.addText("... \n");
									main.addText("... \n");
									main.addText("========================================FIN===============================================");
								}
								//UpdateWindow(hWnd);
								/*InvalidateRect(hWnd, NULL, TRUE);
								RedrawWindow(hWnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ERASENOW | RDW_UPDATENOW);
								UpdateWindow(hWnd);*/
								RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_ERASENOW | RDW_FRAME | RDW_ERASE);
								RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
							}
							catch (std::exception& e)
							{
								//std::cout << "==========EXCEPTION: " << e.what() << '\n';
							}

							combat = CheckEnemy(mapa1, hero.GetCuartoActual());
							//cout << "hero.GetCuartoActual(): " << hero.GetCuartoActual() << "\n";
						}

						else if (combat == true && dead == false)
						{
							bool atack = true;
							list<Enemy> enemigosActuales;
							list<Enemy>::iterator enemigosActualesitr;
							list<Habitación>::iterator mapa1itr;
							for (mapa1itr = mapa1.begin(); mapa1itr != mapa1.end(); mapa1itr++)
							{
								if (mapa1itr->GetNumH() == hero.GetCuartoActual())
								{
									enemigosActuales = mapa1itr->GetEnemies();
								}
							}

							//getline(std::cin, text);
							try
							{
								DictionarySearch2(textReadead, Diccionario, hero, mapa1, true);
								//InvalidateRect(hWnd, NULL, TRUE);
								RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_ERASENOW | RDW_FRAME | RDW_ERASE);
								RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
								//UpdateWindow(hWnd);
							}
							catch (std::exception& e)
							{
								std::cout << "==========EXCEPTION: " << e.what() << '\n';
							}

							for (enemigosActualesitr = enemigosActuales.begin(); enemigosActualesitr != enemigosActuales.end(); enemigosActualesitr++)
							{
								if (enemigosActualesitr->isAlive())
								{
									atack = true;
									hero.takeDamage(enemigosActualesitr->attack());
									if (hero.getVida() < 0)
									{
										dead = true;
									}
								}
								else
								{
									atack = false;
								}

								if (atack)
								{
									main.addText("Te Atacaron, tu vida es = " + std::to_string(hero.getVida()) + '\n');
									string message = "El " + enemigosActualesitr->GetName() + "(Enemigo [" + to_string(enemigosActualesitr->Getid()) + "], HP[" + to_string(enemigosActualesitr->GetVida()) + "])" + " te ataco tu vida es [" + to_string(hero.getVida()) + "]";
									strcpy_s(coutMessage, message.c_str());

									MessageBoxA(hWnd, coutMessage, textReadead, MB_OK);
								}
								
								cout << "Vida actual [" << hero.getVida() << "]" << endl;
							}

							combat = CheckEnemy(mapa1, hero.GetCuartoActual());
							if (!combat)
							{
								srand(time(0));
								int r = (rand() % 10) + 1;
								if (r == 3)
								{
									hero.SetExp(hero.GetExp() + 30);
								}
								else if (r == 4)
								{
									hero.SetExp(hero.GetExp() + 40);
								}
								else if (r == 5)
								{
									hero.SetExp(hero.GetExp() + 50);
								}
								else if (r == 6)
								{
									hero.SetExp(hero.GetExp() + 60);
								}
								else
								{
									hero.SetExp(hero.GetExp() + 20);
								}
								main.addText("Ganaste el Combate! tu exp = " + hero.GetExp() + '\n');
							}
						}
					}
					else
					{
					cout << "GANASTEEEEEEEEEEEEEEE" << endl;
					}


					//MessageBeep(MB_ICONASTERISK);
					MessageBoxA(hWnd, textReadead, "Input", NULL);
					break;
				}
				case ID_Menu:
				{
					MessageBoxA(hWnd, "Estás Sure", "Really", MB_YESNO | MB_ICONQUESTION);
					break;
				}
				case IDM_ABOUT:
					DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About); //Para crear cuadros de dialogo, usar otra funcion diferente a "About"
					break;
				case IDM_EXIT:
					DestroyWindow(hWnd);
					break;
				default:
					return DefWindowProc(hWnd, message, wParam, lParam);
			}
		}
	break;
	
		case WM_LBUTTONDOWN: 
		{
			//int xPos = GET_X_LPARAM(lParam);
			//int yPos = GET_Y_LPARAM(lParam);
			//int index = GetCellNumberFromPoint(hWnd, xPos, yPos);
			//HDC hdc = GetDC(hWnd);
			//if (hdc)
			//{
			//	//WCHAR temp[100];
			//	//wsprintf(temp, L"Index = %d", index); // L"" la L convierte el char en WCHAR
			//	//TextOut(hdc, xPos, yPos, temp, lstrlen(temp));
			//	////ReleaseDC(hWnd, hdc); // Sirve para liberar y dar muchos clicks
			//	if (index != -1)
			//	{
			//		RECT rcCell;
			//		if (GetCellRect(hWnd, index, &rcCell))
			//		{
			//			//DrawIcon(hdc, rcCell.left + (CELL_SIZE / 2) - 16, rcCell.top + (CELL_SIZE / 2) - 16, hIcon1);
			//			//DrawIcon(hdc, rcCell.left + (CELL_SIZE / 2) - 16, rcCell.top + (CELL_SIZE / 2) - 16, hIcon2);
			//			//FillRect(hdc, &rcCell, GetStockBrush(BLACK_BRUSH));
			//		}
			//	}
			//}
			break;
		}

		//case WM_SIZE:
		//{
		//	scrollinfo.cbSize = sizeof(scrollinfo);
		//	scrollinfo.fMask = SIF_RANGE | SIF_PAGE;
		//	scrollinfo.nMin = 0;
		//	scrollinfo.nMax = LINES - 1;
		//	scrollinfo.nPage = yClient / yChar;
		//	SetScrollInfo(main.GetWindow(), SB_VERT, &scrollinfo, TRUE);
		//	break;
		//}

		case WM_GETMINMAXINFO:
		{		
			try
			{

			}
			catch (std::exception &e)
			{

			}
			break;
		}
	
		case WM_HSCROLL:
		{
			break;
		}

		case WM_VSCROLL:
		{		
			//main.scroll(0, -5);
			/*scrollinfo.cbSize = sizeof(scrollinfo);
			scrollinfo.fMask = SIF_ALL;
			GetScrollInfo(main.GetWindow(), SB_VERT, &scrollinfo);*/
			//main.scroll(0, 5);
			//switch (LOWORD(wParam))
			//{
			//case SB_LINEUP:
			//	scrollinfo.nPos -= 1;
			//	main.scroll(0, 5);
			//	break;
			//case SB_LINEDOWN:
			//	scrollinfo.nPos += 1;
			//	break;
			//	// User dragged the scroll box.
			//case SB_THUMBTRACK:
			//	scrollinfo.nPos = scrollinfo.nTrackPos;
			//	break;

			//default:
			//	break;
			//}
			break;
		}

		case WM_KEYUP:
		{
			switch (wParam)
			{
			case VK_UP:
			{
				up = false;
				//InvalidateRect(main.GetWindow(), NULL, TRUE);
				//main.scroll(0, -5);
				//InvalidateRect(main.GetWindow(), NULL, TRUE);
				//InvalidateRect(main.GetWindow(), NULL, TRUE);
				break;
			}

			case VK_DOWN:
			{
				down = false;
				//InvalidateRect(main.GetWindow(), NULL, TRUE);
				//main.scroll(0, 5);
				//InvalidateRect(main.GetWindow(), NULL, TRUE);
				//InvalidateRect(main.GetWindow(), NULL, TRUE);
				break;
			}

			}
			break;
		}

		case WM_KEYDOWN:
		{
			switch (wParam)
			{
			case VK_UP:
			{
				up = true;
				//main.scroll(0, -5);
				main.SetIndex(main.GetIndex() - 1);
				RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_ERASENOW | RDW_FRAME | RDW_ERASE);
				RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
				break;
			}

			case VK_DOWN:
			{
				down = true;
				main.SetIndex(main.GetIndex() + 1);
				RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_ERASENOW | RDW_FRAME | RDW_ERASE);
				RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
				break;
			}
			}
			break;
		}

		case WM_ERASEBKGND:
		{
			//RedrawWindow(hWnd, NULL, NULL, RDW_ERASENOW);
			if (combat)
			{
				RECT rc;
				PAINTSTRUCT ps;
				HDC hdc = BeginPaint(hWnd, &ps);
				GetClientRect(hWnd, &rc);
				SetMapMode(hdc, MM_ANISOTROPIC);
				SetWindowExtEx(hdc, 100, 100, NULL);
				SetViewportExtEx(hdc, rc.right, rc.bottom, NULL);
				FillRect(hdc, &rc, hbrWhite);

				for (int i = -5; i < 100; i += 5)
				{
					for (int j = -5; j < 100; j += 5)
					{
						int x = j;
						int y = i;
						POINT vertices[] = { {x + 5, y - 10}, {x, y}, {x + 10, y} };

						HBRUSH hBrush = CreateSolidBrush(RGB(10 + x * 2, 0, 0));
						HBRUSH hOldBrush = SelectBrush(hdc, hBrush);

						SetDCBrushColor(hdc, 0xd91fe5);
						Polygon(hdc, vertices, sizeof(vertices) / sizeof(vertices[0]));

						SelectBrush(hdc, hOldBrush);
						DeleteObject(hBrush);
					}
				}
				EndPaint(hWnd, &ps);
			}
			else
			{
				RECT rc;
				PAINTSTRUCT ps;
				HDC hdc = BeginPaint(hWnd, &ps);
				GetClientRect(hWnd, &rc);
				SetMapMode(hdc, MM_ANISOTROPIC);
				SetWindowExtEx(hdc, 100, 100, NULL);
				SetViewportExtEx(hdc, rc.right, rc.bottom, NULL);
				FillRect(hdc, &rc, hbrWhite);
				
				for (int i = -5; i < 100; i += 5)
				{
					for (int j = -5; j < 100; j += 5)
					{
						int x = j;
						int y = i;
						POINT vertices[] = { {x + 5, y - 10}, {x, y}, {x + 10, y} };

						HBRUSH hBrush = CreateSolidBrush(RGB(0, x + 50, y + 50));
						HBRUSH hOldBrush = SelectBrush(hdc, hBrush);

						SetDCBrushColor(hdc, 0xd91fe5);
						Polygon(hdc, vertices, sizeof(vertices) / sizeof(vertices[0]));

						SelectBrush(hdc, hOldBrush);
						DeleteObject(hBrush);
					}
				}
				EndPaint(hWnd, &ps);
			}			
		}

		case WM_PAINT:
			{
			
			//RedrawWindow(hWnd, NULL, NULL, RDW_UPDATENOW);

			if (GetClientRect(hWnd, &rcClient))
			{
				MoveWindow(TextBox, (rcClient.right / 2) - 500, rcClient.bottom - 30, 1000, 20, true);
				MoveWindow(Activar, (rcClient.right / 2) + 510, rcClient.bottom - 30, 70, 20, true);
				main.Move((rcClient.right / 2) - 500, rcClient.top + 20, 1000, rcClient.bottom - 60);
				//TEXTCOUT MAIN(hWnd, 100, 100, 1000, 500);
			}
				PAINTSTRUCT ps;
				HDC hdc = BeginPaint(hWnd, &ps);
				RECT rc;

				if (GetGameBoardRect(hWnd, &rc))
				{
					RECT rcClient;
					if (GetClientRect(hWnd, &rcClient))
					{
					
						//main.addText("sdsdsds");
						main.display(hdc, rc);


						int numberH = 0;
						RECT mapaGraph;
						if (GetClientRect(hWnd, &mapaGraph))
						{

						}

						//main.display(hdc, rc);

						for (int i = 0; i <= 8; i++)
						{
							mapaGraph.bottom = 0 + (40 * i);
							for (int j = 0; j <= 8; j++)
							{
								mapaGraph.right = 0 + (40 * j);


								mapaGraph.top = mapaGraph.bottom - 40;
								mapaGraph.left = mapaGraph.right - 40;

								FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(WHITE_BRUSH));
								if (i == 8 && j == 3)
								{
									numberH = 1;
									SetDCBrushColor(hdc, 0x00bb);
									FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
									if (hero.GetCuartoActual() == numberH)
									{
										SetDCBrushColor(hdc, 0xd91fe5);
										FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
									}
									const WCHAR szText[] = L"1";
									SetTextColor(hdc, RGB(0, 0, 0));
									SetBkMode(hdc, TRANSPARENT);
									TextOut(hdc, mapaGraph.left + 15, mapaGraph.top + 15, szText, ARRAYSIZE(szText)); //Imprime cosas en la pantalla			
									EndPath(hdc);
									SelectClipPath(hdc, RGN_AND);
									FillRect(hdc, &rc, (HBRUSH)GetStockObject(GRAY_BRUSH));
								}

								if (i == 7)
								{
									if (j == 2)
									{
										numberH = 3;
										SetDCBrushColor(hdc, 0x00bb);
										FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										if (hero.GetCuartoActual() == numberH)
										{
											SetDCBrushColor(hdc, 0xd91fe5);
											FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										}
										const WCHAR szText[] = L"3";
										SetTextColor(hdc, RGB(0, 0, 0));
										SetBkMode(hdc, TRANSPARENT);
										TextOut(hdc, mapaGraph.left + 15, mapaGraph.top + 15, szText, ARRAYSIZE(szText)); //Imprime cosas en la pantalla			
										EndPath(hdc);
										SelectClipPath(hdc, RGN_AND);
										FillRect(hdc, &rc, (HBRUSH)GetStockObject(GRAY_BRUSH));
									}

									if (j == 3)
									{

										numberH = 2;
										SetDCBrushColor(hdc, 0x00bb);
										FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										if (hero.GetCuartoActual() == numberH)
										{
											SetDCBrushColor(hdc, 0xd91fe5);
											FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										}
										const WCHAR szText[] = L"2";
										SetTextColor(hdc, RGB(0, 0, 0));
										SetBkMode(hdc, TRANSPARENT);
										TextOut(hdc, mapaGraph.left + 15, mapaGraph.top + 15, szText, ARRAYSIZE(szText)); //Imprime cosas en la pantalla			
										EndPath(hdc);
										SelectClipPath(hdc, RGN_AND);
										FillRect(hdc, &rc, (HBRUSH)GetStockObject(GRAY_BRUSH));
									}

									if (j == 4)
									{
										numberH = 4;
										SetDCBrushColor(hdc, 0x00bb);
										FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										if (hero.GetCuartoActual() == numberH)
										{
											SetDCBrushColor(hdc, 0xd91fe5);
											FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										}
										const WCHAR szText[] = L"4";
										SetTextColor(hdc, RGB(0, 0, 0));
										SetBkMode(hdc, TRANSPARENT);
										TextOut(hdc, mapaGraph.left + 15, mapaGraph.top + 15, szText, ARRAYSIZE(szText)); //Imprime cosas en la pantalla			
										EndPath(hdc);
										SelectClipPath(hdc, RGN_AND);
										FillRect(hdc, &rc, (HBRUSH)GetStockObject(GRAY_BRUSH));
									}

									if (j == 5)
									{
										numberH = 7;
										SetDCBrushColor(hdc, 0x00bb);
										FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										if (hero.GetCuartoActual() == numberH)
										{
											SetDCBrushColor(hdc, 0xd91fe5);
											FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										}
										const WCHAR szText[] = L"7";
										SetTextColor(hdc, RGB(0, 0, 0));
										SetBkMode(hdc, TRANSPARENT);
										TextOut(hdc, mapaGraph.left + 15, mapaGraph.top + 15, szText, ARRAYSIZE(szText)); //Imprime cosas en la pantalla			
										EndPath(hdc);
										SelectClipPath(hdc, RGN_AND);
										FillRect(hdc, &rc, (HBRUSH)GetStockObject(GRAY_BRUSH));
									}

									if (j == 6)
									{
										numberH = 10;
										SetDCBrushColor(hdc, 0x00bb);
										FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										if (hero.GetCuartoActual() == numberH)
										{
											SetDCBrushColor(hdc, 0xd91fe5);
											FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										}
										const WCHAR szText[] = L"10";
										SetTextColor(hdc, RGB(0, 0, 0));
										SetBkMode(hdc, TRANSPARENT);
										TextOut(hdc, mapaGraph.left + 15, mapaGraph.top + 15, szText, ARRAYSIZE(szText)); //Imprime cosas en la pantalla			
										EndPath(hdc);
										SelectClipPath(hdc, RGN_AND);
										FillRect(hdc, &rc, (HBRUSH)GetStockObject(GRAY_BRUSH));
									}

								}

								if (i == 6)
								{

									if (j == 2)
									{
										numberH = 5;
										SetDCBrushColor(hdc, 0x00bb);
										FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										if (hero.GetCuartoActual() == numberH)
										{
											SetDCBrushColor(hdc, 0xd91fe5);
											FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										}
										const WCHAR szText[] = L"5";
										SetTextColor(hdc, RGB(0, 0, 0));
										SetBkMode(hdc, TRANSPARENT);
										TextOut(hdc, mapaGraph.left + 15, mapaGraph.top + 15, szText, ARRAYSIZE(szText)); //Imprime cosas en la pantalla			
										EndPath(hdc);
										SelectClipPath(hdc, RGN_AND);
										FillRect(hdc, &rc, (HBRUSH)GetStockObject(GRAY_BRUSH));
									}

									if (j == 4)
									{
										numberH = 6;
										SetDCBrushColor(hdc, 0x00bb);
										FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										if (hero.GetCuartoActual() == numberH)
										{
											SetDCBrushColor(hdc, 0xd91fe5);
											FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										}
										const WCHAR szText[] = L"6";
										SetTextColor(hdc, RGB(0, 0, 0));
										SetBkMode(hdc, TRANSPARENT);
										TextOut(hdc, mapaGraph.left + 15, mapaGraph.top + 15, szText, ARRAYSIZE(szText)); //Imprime cosas en la pantalla			
										EndPath(hdc);
										SelectClipPath(hdc, RGN_AND);
										FillRect(hdc, &rc, (HBRUSH)GetStockObject(GRAY_BRUSH));
									}

									if (j == 6)
									{
										numberH = 13;
										SetDCBrushColor(hdc, 0x00bb);
										FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										if (hero.GetCuartoActual() == numberH)
										{
											SetDCBrushColor(hdc, 0xd91fe5);
											FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										}
										const WCHAR szText[] = L"13";
										SetTextColor(hdc, RGB(0, 0, 0));
										SetBkMode(hdc, TRANSPARENT);
										TextOut(hdc, mapaGraph.left + 15, mapaGraph.top + 15, szText, ARRAYSIZE(szText)); //Imprime cosas en la pantalla			
										EndPath(hdc);
										SelectClipPath(hdc, RGN_AND);
										FillRect(hdc, &rc, (HBRUSH)GetStockObject(GRAY_BRUSH));
									}
								}

								if (i == 5)
								{
									if (j == 1)
									{
										numberH = 11;
										SetDCBrushColor(hdc, 0x00bb);
										FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										if (hero.GetCuartoActual() == numberH)
										{
											SetDCBrushColor(hdc, 0xd91fe5);
											FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										}
										const WCHAR szText[] = L"11";
										SetTextColor(hdc, RGB(0, 0, 0));
										SetBkMode(hdc, TRANSPARENT);
										TextOut(hdc, mapaGraph.left + 15, mapaGraph.top + 15, szText, ARRAYSIZE(szText)); //Imprime cosas en la pantalla			
										EndPath(hdc);
										SelectClipPath(hdc, RGN_AND);
										FillRect(hdc, &rc, (HBRUSH)GetStockObject(GRAY_BRUSH));
									}

									if (j == 2)
									{
										numberH = 8;
										SetDCBrushColor(hdc, 0x00bb);
										FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										if (hero.GetCuartoActual() == numberH)
										{
											SetDCBrushColor(hdc, 0xd91fe5);
											FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										}
										const WCHAR szText[] = L"8";
										SetTextColor(hdc, RGB(0, 0, 0));
										SetBkMode(hdc, TRANSPARENT);
										TextOut(hdc, mapaGraph.left + 15, mapaGraph.top + 15, szText, ARRAYSIZE(szText)); //Imprime cosas en la pantalla			
										EndPath(hdc);
										SelectClipPath(hdc, RGN_AND);
										FillRect(hdc, &rc, (HBRUSH)GetStockObject(GRAY_BRUSH));
									}

									if (j == 4)
									{
										numberH = 9;
										SetDCBrushColor(hdc, 0x00bb);
										FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										if (hero.GetCuartoActual() == numberH)
										{
											SetDCBrushColor(hdc, 0xd91fe5);
											FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										}
										const WCHAR szText[] = L"9";
										SetTextColor(hdc, RGB(0, 0, 0));
										SetBkMode(hdc, TRANSPARENT);
										TextOut(hdc, mapaGraph.left + 15, mapaGraph.top + 15, szText, ARRAYSIZE(szText)); //Imprime cosas en la pantalla			
										EndPath(hdc);
										SelectClipPath(hdc, RGN_AND);
										FillRect(hdc, &rc, (HBRUSH)GetStockObject(GRAY_BRUSH));
									}

									if (j == 6)
									{
										numberH = 14;
										SetDCBrushColor(hdc, 0x00bb);
										FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										if (hero.GetCuartoActual() == numberH)
										{
											SetDCBrushColor(hdc, 0xd91fe5);
											FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										}
										const WCHAR szText[] = L"14";
										SetTextColor(hdc, RGB(0, 0, 0));
										SetBkMode(hdc, TRANSPARENT);
										TextOut(hdc, mapaGraph.left + 15, mapaGraph.top + 15, szText, ARRAYSIZE(szText)); //Imprime cosas en la pantalla			
										EndPath(hdc);
										SelectClipPath(hdc, RGN_AND);
										FillRect(hdc, &rc, (HBRUSH)GetStockObject(GRAY_BRUSH));
									}
								}

								if (i == 4){if (j == 2){
										numberH = 12;
										SetDCBrushColor(hdc, 0x00bb);
										FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										if (hero.GetCuartoActual() == numberH)
										{
											SetDCBrushColor(hdc, 0xd91fe5);
											FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										}
										const WCHAR szText[] = L"12";
										SetTextColor(hdc, RGB(0, 0, 0));
										SetBkMode(hdc, TRANSPARENT);
										TextOut(hdc, mapaGraph.left + 15, mapaGraph.top + 15, szText, ARRAYSIZE(szText)); //Imprime cosas en la pantalla			
										EndPath(hdc);
										SelectClipPath(hdc, RGN_AND);
										FillRect(hdc, &rc, (HBRUSH)GetStockObject(GRAY_BRUSH));
								}

									if (j == 4)
									{
										numberH = 17;
										SetDCBrushColor(hdc, 0x00bb);
										FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										if (hero.GetCuartoActual() == numberH)
										{
											SetDCBrushColor(hdc, 0xd91fe5);
											FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										}
										const WCHAR szText[] = L"17";
										SetTextColor(hdc, RGB(0, 0, 0));
										SetBkMode(hdc, TRANSPARENT);
										TextOut(hdc, mapaGraph.left + 15, mapaGraph.top + 15, szText, ARRAYSIZE(szText)); //Imprime cosas en la pantalla			
										EndPath(hdc);
										SelectClipPath(hdc, RGN_AND);
										FillRect(hdc, &rc, (HBRUSH)GetStockObject(GRAY_BRUSH));
									}

									if (j == 5)
									{
										numberH = 16;
										SetDCBrushColor(hdc, 0x00bb);
										FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										if (hero.GetCuartoActual() == numberH)
										{
											SetDCBrushColor(hdc, 0xd91fe5);
											FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										}
										const WCHAR szText[] = L"16";
										SetTextColor(hdc, RGB(0, 0, 0));
										SetBkMode(hdc, TRANSPARENT);
										TextOut(hdc, mapaGraph.left + 15, mapaGraph.top + 15, szText, ARRAYSIZE(szText)); //Imprime cosas en la pantalla			
										EndPath(hdc);
										SelectClipPath(hdc, RGN_AND);
										FillRect(hdc, &rc, (HBRUSH)GetStockObject(GRAY_BRUSH));
									}

									if (j == 6)
									{
										numberH = 15;
										SetDCBrushColor(hdc, 0x00bb);
										FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										if (hero.GetCuartoActual() == numberH)
										{
											SetDCBrushColor(hdc, 0xd91fe5);
											FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										}
										const WCHAR szText[] = L"15";
										SetTextColor(hdc, RGB(0, 0, 0));
										SetBkMode(hdc, TRANSPARENT);
										TextOut(hdc, mapaGraph.left + 15, mapaGraph.top + 15, szText, ARRAYSIZE(szText)); //Imprime cosas en la pantalla			
										EndPath(hdc);
										SelectClipPath(hdc, RGN_AND);
										FillRect(hdc, &rc, (HBRUSH)GetStockObject(GRAY_BRUSH));
									}

								}

								if (i == 3)
								{
									if (j == 4)
									{
										numberH = 18;
										SetDCBrushColor(hdc, 0x00bb);
										FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										if (hero.GetCuartoActual() == numberH)
										{
											SetDCBrushColor(hdc, 0xd91fe5);
											FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										}
										const WCHAR szText[] = L"18";
										SetTextColor(hdc, RGB(0, 0, 0));
										SetBkMode(hdc, TRANSPARENT);
										TextOut(hdc, mapaGraph.left + 15, mapaGraph.top + 15, szText, ARRAYSIZE(szText)); //Imprime cosas en la pantalla			
										EndPath(hdc);
										SelectClipPath(hdc, RGN_AND);
										FillRect(hdc, &rc, (HBRUSH)GetStockObject(GRAY_BRUSH));
									}

									if (j == 6)
									{
										numberH = 19;
										SetDCBrushColor(hdc, 0x00bb);
										FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										if (hero.GetCuartoActual() == numberH)
										{
											SetDCBrushColor(hdc, 0xd91fe5);
											FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										}	
										const WCHAR szText[] = L"19";
										SetTextColor(hdc, RGB(0, 0, 0));
										SetBkMode(hdc, TRANSPARENT);
										TextOut(hdc, mapaGraph.left + 15, mapaGraph.top + 15, szText, ARRAYSIZE(szText)); //Imprime cosas en la pantalla			
										EndPath(hdc);
										SelectClipPath(hdc, RGN_AND);
										FillRect(hdc, &rc, (HBRUSH)GetStockObject(GRAY_BRUSH));
									}
								}

								if (i == 2)
								{
									if (j == 4)
									{
										numberH = 20;
										SetDCBrushColor(hdc, 0x00bb);
										FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										if (hero.GetCuartoActual() == numberH)
										{
											SetDCBrushColor(hdc, 0xd91fe5);
											FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										}
										const WCHAR szText[] = L"20";
										SetTextColor(hdc, RGB(0, 0, 0));
										SetBkMode(hdc, TRANSPARENT);
										TextOut(hdc, mapaGraph.left + 15, mapaGraph.top + 15, szText, ARRAYSIZE(szText)); //Imprime cosas en la pantalla			
										EndPath(hdc);
										SelectClipPath(hdc, RGN_AND);
										FillRect(hdc, &rc, (HBRUSH)GetStockObject(GRAY_BRUSH));
									}

									if (j == 5)
									{
										numberH = 22;
										SetDCBrushColor(hdc, 0x00bb);
										FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										if (hero.GetCuartoActual() == numberH)
										{
											SetDCBrushColor(hdc, 0xd91fe5);
											FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										}
										const WCHAR szText[] = L"22";
										SetTextColor(hdc, RGB(0, 0, 0));
										SetBkMode(hdc, TRANSPARENT);
										TextOut(hdc, mapaGraph.left + 15, mapaGraph.top + 15, szText, ARRAYSIZE(szText)); //Imprime cosas en la pantalla			
										EndPath(hdc);
										SelectClipPath(hdc, RGN_AND);
										FillRect(hdc, &rc, (HBRUSH)GetStockObject(GRAY_BRUSH));
									}

									if (j == 6)
									{
										numberH = 21;
										SetDCBrushColor(hdc, 0x00bb);
										FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										if (hero.GetCuartoActual() == numberH)
										{
											SetDCBrushColor(hdc, 0xd91fe5);
											FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
										}
										const WCHAR szText[] = L"21";
										SetTextColor(hdc, RGB(0, 0, 0));
										SetBkMode(hdc, TRANSPARENT);
										TextOut(hdc, mapaGraph.left + 15, mapaGraph.top + 15, szText, ARRAYSIZE(szText)); //Imprime cosas en la pantalla			
										EndPath(hdc);
										SelectClipPath(hdc, RGN_AND);
										FillRect(hdc, &rc, (HBRUSH)GetStockObject(GRAY_BRUSH));
									}
								}


								if (i == 1 && j == 5)
								{
									numberH = 23;
									SetDCBrushColor(hdc, 0xfaaf);
									FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
									if (hero.GetCuartoActual() == numberH)
									{
										SetDCBrushColor(hdc, 0xd91fe5);
										FillRect(hdc, &mapaGraph, (HBRUSH)GetStockObject(DC_BRUSH));
									}
									const WCHAR szText[] = L"23";
									SetTextColor(hdc, RGB(0, 0, 0));
									SetBkMode(hdc, TRANSPARENT);
									TextOut(hdc, mapaGraph.left + 15, mapaGraph.top + 15, szText, ARRAYSIZE(szText)); //Imprime cosas en la pantalla			
									EndPath(hdc);
									SelectClipPath(hdc, RGN_AND);
									FillRect(hdc, &rc, (HBRUSH)GetStockObject(GRAY_BRUSH));
								}
							}
						}

						for (int i = 0; i < 9; i++)
						{
							DrawLine(hdc, (i * 40), 0, 0 + (i * 40), 40 * (8));
							DrawLine(hdc, 0, (i * 40), 40 * (8), (i * 40));
						}
						
						RECT Background;
						Background.left = rcClient.left + 480;
						Background.top = rcClient.top + 20;
						Background.right = 1300;
						Background.bottom = 650;
						FillRect(hdc, &Background, (HBRUSH)GetStockObject(WHITE_BRUSH));
						main.display(hdc, rc);
						EndPath(hdc);

						// Derive a region from that path 


					}
				}
				// TODO: Add any drawing code that uses hdc here...
				EndPaint(hWnd, &ps);
			}
			break;

		case WM_DESTROY:
			DestroyIcon(hIcon1);
			DestroyIcon(hIcon2);
			PostQuitMessage(0);
			break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}