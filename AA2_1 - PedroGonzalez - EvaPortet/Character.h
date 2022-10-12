#pragma once
#include "Includes.h"

#include "ConsoleControl.h"

class Character {
public:
	enum Directions { UP, DOWN, LEFT, RIGHT };
	int x, y;
	int lastX, lastY;
	int lives;
	int actionTime;
	char icon = 0;

	Character() {
		x = 0;
		y = 0;
		lastX = 0;
		lastY = 0;

		lives = 1;
		actionTime = 0;
	}

	virtual void Attack() = 0;

	virtual void Die() = 0;

	void Move(Character::Directions direction) {
		lastX = x;
		lastY = y;

		if (direction == Character::Directions::UP) {
			y--;
		}
		if (direction == Character::Directions::DOWN) {
			y++;
		}
		if (direction == Character::Directions::LEFT) {
			x--;
		}
		if (direction == Character::Directions::RIGHT) {
			x++;
		}
	}

	void Draw(ConsoleControl& consoleControl) {
		consoleControl.SetPosition(lastX, lastY);
		std::cout << ' ';
		consoleControl.SetPosition(x, y);
		std::cout << icon;
	}

	virtual void Damage() = 0;
};