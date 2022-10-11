#pragma once
#include "Includes.h"

class Drop {
public:
	enum Type { Unknown = 0, Lance = 1, Coin = 2, Potion = 3 };
	Type type = Unknown;

	int x, y;
	char icon = 0;

	Drop() {
		x = 0;
		y = 0;
	}

	void Draw(ConsoleControl& consoleControl) {
		consoleControl.SetPosition(x, y);
		std::cout << icon;
	}
};