#pragma once
#include "Character.h"
#include "Weapon.h"
#include "Drop.h"

class Player : public Character {
public:
		
	Weapon currentWeapon;
	int potions;
	int coins;
	bool isDead;

	Player() : Character() {
		potions = 0;
		coins = 0;
		isDead = false;
		x = 3;
		y = 3;
	}

	void Attack() override {

	}

	void Die() override {

	}

	void Damage() override {

	}

	void GetItem(Drop &gotDrop){

	}

	void Heal(int &lives) {

	}
};