#pragma once
#include "Map.h"
#include "Player.h"

class Portal
{
public:
	int x, y;
	Map *nextMap;

	void checkPlayer(Player& player);
};