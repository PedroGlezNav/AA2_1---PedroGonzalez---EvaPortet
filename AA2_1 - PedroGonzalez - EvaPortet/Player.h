#pragma once
#include "Character.h"
#include "Sword.h"
#include "Lance.h"
#include "Drop.h"

class Player : public Character {
public:
		
	Weapon currentWeapon;
	int potions;
	int coins;
	bool isDead;

	Player() : Character() {
		currentWeapon = Sword();
		potions = 1;
		coins = 0;
		isDead = false;
		x = ROWS/2;
		y = COLS/2;
		icon = 'J';
	}

	void Attack() override {

	}

	void DrawInventory(ConsoleControl& consoleControl) {
		consoleControl.SetPosition(0, COLS + 3);
		std::cout << "Coins: " << coins << " - ";
		std::cout << "Lifes: " << lives << " - ";
		std::cout << "Potions: " << potions << " - ";
		std::cout << "Weapon: " << currentWeapon.name << " - ";
		std::cout << "X: " << x << " - ";
		std::cout << "Y: " << y;
		consoleControl.SetPosition(0, COLS + 4);
		std::cout << "Press Esc to exit the game.";
	}

	void Die() override {
		isDead = true;
	}

	void GetItem(Drop gotDrop){
		switch (gotDrop.type){
		case Drop::Type::Coin: {
			coins++;
		}
		break;
		case Drop::Type::Lance: {
			currentWeapon = Lance();
		}
		break;
		case Drop::Type::Potion: {
			potions++;
		}
		break;
		}
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