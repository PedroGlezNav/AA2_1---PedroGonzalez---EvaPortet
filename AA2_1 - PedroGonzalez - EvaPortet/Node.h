#pragma once
#include "Includes.h"

#include "ConsoleControl.h"

class Node {
public:
	char icon;
	int x, y;

	void Draw(ConsoleControl& consoleControl) {
		consoleControl.SetColor(ConsoleControl::ConsoleColor::DARKGREY, ConsoleControl::ConsoleColor::BLACK);
		consoleControl.SetPosition(x, y);
		std::cout << icon;
	}
};