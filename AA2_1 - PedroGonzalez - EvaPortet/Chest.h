#pragma once
#include "Includes.h"

#include "Drop.h"

class Chest {
public:
	int x, y;
	Drop::Type drop;
	char icon;

	Chest() {
		x = 0;
		y = 0;
		drop = Drop::Type::Unknown;
		icon = 'C';
	}

	void Draw(ConsoleControl& consoleControl) {
		consoleControl.SetPosition(x, y);
		std::cout << icon;
	}
	
	void Drop() {
		drop = (Drop::Type)(rand() % 3 + 0);
	}
};