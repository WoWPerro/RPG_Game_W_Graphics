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
		if (_DLLObjetos) {
			std::list <DLLObjetos*>::iterator DLLObjetosit;
			for (DLLObjetosit = _DLLObjetos->begin(); DLLObjetosit != _DLLObjetos->end(); DLLObjetosit++)
			{
				std::cout << "Ves: " << (*DLLObjetosit)->GetName() << " ["<< counter << "]"<< std::endl;
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

void Habitaci�n::Add(DLLObjetos *obj)
{
	_DLLObjetos->push_back(obj);
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

void Habitaci�n::Remove(DLLObjetos *obj)
{
	_DLLObjetos->remove(obj);
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

std::list <DLLObjetos*> *Habitaci�n::GetDLLObjetos()
{
	return _DLLObjetos;
}

std::list <Weapon*> Habitaci�n::GetWeapons()
{
	list <DLLObjetos*>::iterator Objectsitr;
	list <Weapon*> weaponlist;
	list <Weapon*>::iterator weaponlistitr = weaponlist.begin();
	for (DLLObjetos* DLLObjetos : *_DLLObjetos)
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
	return weaponlist;
}

void Habitaci�n::setRead(bool read)
{
	_read = read;
}

bool Habitaci�n::GetplayerEnters()
{
	return _playerEnters;
}

bool Habitaci�n::Getread()
{
	return _read;
}

string Habitaci�n::Getdescripcion()
{
	return _descripcion;
}

Habitaci�n::~Habitaci�n()
{
}
