#include "pch.h"
#include "Map.h"


GameMap::GameMap()
{
}

void GameMap::Add(Habitaci�n habitaci�n)
{
	_habitaciones++;
	_mapa.insert(std::pair<int, Habitaci�n>(_habitaciones, habitaci�n));
}

void GameMap::Remove(Habitaci�n habitaci�n)
{

}

void GameMap::SetPlayerPos(int pos)
{
	_playerpos = &pos;
}

int GameMap::GetPlayerPos()
{
	return *_playerpos;
}



GameMap::~GameMap()
{
}
