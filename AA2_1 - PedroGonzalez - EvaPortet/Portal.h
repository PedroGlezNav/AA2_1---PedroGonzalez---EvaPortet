#pragma once
#include "Map.h"
#include "Player.h"

class Portal
{
public:
	int x, y;
	int xPlayerSpawn, yPlayerSpawn;
	int nextMap;
	char icon = 'P';

	bool checkPlayer(Player player) {
		if (player.x == this->x && player.y == this->y) {
			return true;
		}
		return false;
	}

	void Draw(ConsoleControl& consoleControl) {
		consoleControl.SetColor(ConsoleControl::ConsoleColor::BLUE, ConsoleControl::ConsoleColor::BLACK);
		consoleControl.SetPosition(x, y);
		std::cout << icon;
	}
};