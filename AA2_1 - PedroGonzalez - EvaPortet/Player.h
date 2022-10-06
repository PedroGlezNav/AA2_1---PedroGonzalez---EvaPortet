#pragma once
#include "Character.h"
#include "Weapon.h"
#include "Drop.h"

class Player : public Character {
public:

	Weapon currentWeapon;
	int potions;
	int coins;

	Player() : Character() {
		potions = 0;
		coins = 0;
	}

	void Attack() override {

	}

	void Die() override {

	}

	void Move() override {
		
	}

	void Damage() override {

	}

	void GetItem(Drop &gotDrop){

	}

	void Heal(int &lives) {

	}
};