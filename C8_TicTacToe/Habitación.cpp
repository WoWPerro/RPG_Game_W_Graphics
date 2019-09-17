#include "stdafx.h"
#include "pch.h"
#include "Habitaci�n.h"

Habitaci�n::Habitaci�n()
{
}

int Habitaci�n::GetNumH()
{
	return num;
}

std::forward_list <Puerta> &Habitaci�n::Getpuertas()
{
	return _puertas;
}

void Habitaci�n::LeerHabitacion()
{
	if (!_read)
	{
		int counter = 0;
		std::cout << "============================================================================" << std::endl;		
		std::cout << _descripcion << std::endl;
		if (_objetos) {
			std::list <Objeto*>::iterator objetosit;
			for (objetosit = _objetos->begin(); objetosit != _objetos->end(); objetosit++)
			{
				std::cout << "Ves: " << (*objetosit)->GetName() << " ["<< counter << "]"<< std::endl;
				counter++;
			}
		}

		std::vector <Llave>::iterator llavesit;
		int counterLlaves = 0;
		for (llavesit = _llaves.begin(); llavesit != _llaves.end(); llavesit++)
		{
			counterLlaves++;
			std::cout << "Ves: " << counterLlaves << " LLaves" << std::endl;
		}

		std::forward_list <Puerta>::iterator puertasit;
		int counterPuertasA = 0;
		int counterPuertasC = 0;
		for (puertasit = _puertas.begin(); puertasit != _puertas.end(); puertasit++)
		{
			if (puertasit->GetAbierta())
			{
				std::cout << "Puerta [Que lleva al cuarto " << puertasit->GetID() << "] abierta" << std::endl;
			}
			else if (!puertasit->GetAbierta())
			{
				std::cout << "Puerta [Que lleva al cuarto (" << puertasit->GetID() << ")] cerrada" << std::endl;
			}			
		}

		std::list <Enemy>::iterator enemigosit;
		std::cout << "Ves Enemigos" << std::endl;
		for (enemigosit = _enemigos.begin(); enemigosit != _enemigos.end(); enemigosit++)
		{		
			std::cout << "El " << enemigosit->GetName() << "(Enemigo [" << enemigosit->Getid() << "], HP[" << enemigosit->GetVida() << "])" << std::endl;
		}
		_read = true;
		std::cout << "============================================================================" << std::endl;
	}
}

void Habitaci�n::SetDescription(std::string descripcion)
{
	_descripcion = descripcion;
}

void Habitaci�n::Add(Puerta puerta)
{
	_puertas.push_front(puerta);
}

void Habitaci�n::Add(Objeto *obj)
{
	_objetos->push_back(obj);
}

void Habitaci�n::Add(Llave llave)
{
	//_llaves.insert(llave);
}

void Habitaci�n::Add(Enemy enemy)
{
	_enemigos.push_back(enemy);
}

void Habitaci�n::Remove(Puerta puerta)
{

}

void Habitaci�n::Remove(Objeto *obj)
{
	_objetos->remove(obj);
}

void Habitaci�n::Remove(Llave llave)
{

}

void Habitaci�n::Remove(Enemy enemy)
{

}

list <Enemy> &Habitaci�n::GetEnemies()
{
	return _enemigos;
}

vector <Llave> &Habitaci�n::GetLlaves()
{
	return _llaves;
}

std::list <Objeto*> *Habitaci�n::GetObjetos()
{
	return _objetos;
}

std::list <Weapon*> Habitaci�n::GetWeapons()
{
	list <Objeto*>::iterator Objectsitr;
	list <Weapon*> weaponlist;
	list <Weapon*>::iterator weaponlistitr = weaponlist.begin();
	for (Objeto* objeto : *_objetos)
	{
		if (objeto == dynamic_cast<Weapon*>(objeto))
		{
			weaponlist.insert(weaponlistitr, dynamic_cast<Weapon*>(objeto));
			if (weaponlistitr != weaponlist.end())
			{
				weaponlistitr++;
			}
		}
	}
	return weaponlist;
}

void Habitaci�n::setRead(bool read)
{
	_read = read;
}

Habitaci�n::~Habitaci�n()
{
}
