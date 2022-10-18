#pragma once
#include "Includes.h"

class Drop {
public:
	enum Type {  Potion = 0, Lance = 1, Coin = 2, Unknown = 3 };
	Type type;

	int x, y;
	char icon;

	Drop() {
		x = 0;
		y = 0;
		icon = 0;
		type = Type::Unknown;
	}

	void DefineIcon() {
		switch (type) {
		case Type::Coin: {
			icon = 'C';
		}
		break;
		case Type::Lance: {
			icon = 'L';
		}
		break;
		case Type::Potion: {
			icon = 'P';
		}
		break;
		}
	}

	void Draw(ConsoleControl& consoleControl) {
		switch (type) {
		case Type::Coin:
			consoleControl.SetColor(ConsoleControl::ConsoleColor::YELLOW, ConsoleControl::ConsoleColor::BLACK);
			break;
		case Type::Lance:
			consoleControl.SetColor(ConsoleControl::ConsoleColor::LIGHTGREY, ConsoleControl::ConsoleColor::BLACK);
			break;
		case Type::Potion:
			consoleControl.SetColor(ConsoleControl::ConsoleColor::GREEN, ConsoleControl::ConsoleColor::BLACK);
			break;
		}
		consoleControl.SetPosition(x, y);
		std::cout << icon;
	}

	bool PlayerIsOnDrop(int x, int y) {
		if (this->x == x && this->y == y) {
			return true;
		}
		else {
			return false;
		}
	}
};