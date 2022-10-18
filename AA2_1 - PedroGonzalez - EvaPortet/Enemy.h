#pragma once
#include "Character.h"
#include "Weapon.h"
#include "Drop.h"

class Enemy : public Character {
public:
	Drop::Type drop;

	Enemy() : Character() {
		drop = Drop::Type::Unknown;
		icon = 'E';
	}

	void Draw(ConsoleControl& consoleControl) override {
		consoleControl.SetColor(ConsoleControl::ConsoleColor::WHITE, ConsoleControl::ConsoleColor::BLACK);
		consoleControl.SetPosition(lastX, lastY);
		std::cout << ' ';
		consoleControl.SetColor(ConsoleControl::ConsoleColor::RED, ConsoleControl::ConsoleColor::BLACK);
		consoleControl.SetPosition(x, y);
		std::cout << icon;
	}

	void Attack() override {

	}

	void Die() override {

	}
};