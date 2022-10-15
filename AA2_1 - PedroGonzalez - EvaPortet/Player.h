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

	void Parse(Json::Value jsonValue) {
		this->lives = jsonValue["lives"].asInt();
		this->x = jsonValue["x"].asInt();
		this->y = jsonValue["y"].asInt();
		this->coins = jsonValue["coins"].asInt();
		this->potions = jsonValue["potions"].asInt();

		switch (jsonValue["currentWeapon"].asString()) {

		}


	}

	Json::Value ToJsonValue() {

	}
};