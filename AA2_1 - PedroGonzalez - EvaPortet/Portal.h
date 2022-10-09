#pragma once
#include "Map.h"
#include "Player.h"

class Portal
{
public:
	int x, y;
	int nextMap;

	bool checkPlayer(Player player) {
		if (player.x == this->x && player.y == this->y) {
			return true;
		}
		return false;
	}
};