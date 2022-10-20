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
	bool isDead;

	Character() {
		x = 0;
		y = 0;
		lastX = 0;
		lastY = 0;

		lives = 1;
		actionTime = 0;
		isDead = false;
	}

	void Attack(Character& characterToAttack) {
		characterToAttack.GetDamage();
	}

	virtual void Die() {
		isDead = true;
	}

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

	virtual void Draw(ConsoleControl& consoleControl) = 0;

	void GetDamage() {
		if (lives > 1) {
			lives--;
		}
		else {
			lives = 0;
			Die();
		}
	}
};