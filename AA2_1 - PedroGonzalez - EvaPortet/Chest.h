#pragma once
#include "Includes.h"

#include "Drop.h"

class Chest {
public:
	int x, y;
	Drop drop;
	char icon;

	Chest() {
		x = 0;
		y = 0;
		icon = 'C';
	}

	bool PlayerAtacksChest(int x, int y) {
		if (this->x == x && this->y == y) {
			return true;
		}
		else {
			return false;
		}
	}

	void Draw(ConsoleControl& consoleControl) {
		consoleControl.SetPosition(x, y);
		std::cout << icon;
	}
	
	void Drop() {
		drop.type = (Drop::Type)(rand() % 3 + 0);
		drop.DefineIcon();
		drop.x = this->x;
		drop.y = this->y;
	}
};