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
		potions = 1;
		coins = 0;
		isDead = false;
		x = 3;
		y = 3;
		icon = 'J';
	}

	void Attack() override {

	}

	void Die() override {

	}

	void Damage() override {

	}

	void GetItem(Drop &gotDrop){

	}

	void Heal() {
		if (potions > 0) {
			potions--;
			lives++;
		}
		else {
			return;
		}
	}
};