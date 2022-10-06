#pragma once
#include "Includes.h"

class Character {
public:
	int x, y;
	int lives;

	Character() {
		x = 0;
		y = 0;

		lives = 1;
	}

	virtual void Attack() = 0;
	virtual void Die() = 0;
	virtual void Move() = 0;
	virtual void Damage() = 0;
};