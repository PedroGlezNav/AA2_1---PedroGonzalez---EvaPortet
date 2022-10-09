#pragma once
#include "Includes.h"

class Character {
public:
	enum Directions { UP, DOWN, LEFT, RIGHT };
	int x, y;
	int lives;
	int actionTime;
	char icon;

	Character() {
		x = 0;
		y = 0;

		lives = 1;
		actionTime = 0;
	}

	virtual void Attack() = 0;

	virtual void Die() = 0;

	void Move(Character::Directions direction) {
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

	void Draw() {

	}

	virtual void Damage() = 0;
};