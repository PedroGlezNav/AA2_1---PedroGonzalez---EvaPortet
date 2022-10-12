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

	void DrawInventory(ConsoleControl& consoleControl) {
		consoleControl.SetPosition(0, ROWS + 2);
		std::cout << "Coins: " << coins << " - ";
		std::cout << "Lifes: " << lives << " - ";
		std::cout << "Potions: " << potions << " - ";
		std::cout << "Weapon: " << currentWeapon.name << " - ";
		std::cout << "X: " << x << " - ";
		std::cout << "Y: " << y << " - ";
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