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
		consoleControl.SetColor(ConsoleControl::ConsoleColor::LIGHTGREY, ConsoleControl::ConsoleColor::BLACK);
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

	void Draw(ConsoleControl& consoleControl) override {
		consoleControl.SetColor(ConsoleControl::ConsoleColor::WHITE, ConsoleControl::ConsoleColor::BLACK);
		consoleControl.SetPosition(lastX, lastY);
		std::cout << ' ';
		consoleControl.SetColor(ConsoleControl::ConsoleColor::DARKYELLOW, ConsoleControl::ConsoleColor::BLACK);
		consoleControl.SetPosition(x, y);
		std::cout << icon;
	}

	static Player* Parse(Json::Value jsonValue) {
		Player* newPlayer = new Player();
		try {
			newPlayer->lives = jsonValue["lives"].asInt();
			newPlayer->x = jsonValue["x"].asInt();
			newPlayer->y = jsonValue["y"].asInt();
			newPlayer->coins = jsonValue["coins"].asInt();
			newPlayer->potions = jsonValue["potions"].asInt();
			if (jsonValue["currentWeapon"].asString() == "Sword") {
				newPlayer->currentWeapon = Sword();
			}
			else if (jsonValue["currentWeapon"].asString() == "Lance") {
				newPlayer->currentWeapon = Lance();
			}
		}

		catch (const std::exception&)
		{
			delete newPlayer;
			return nullptr;
		}

		return newPlayer;
	}

	Json::Value ToJsonValue() {
		Json::Value jsonValue;
		jsonValue["lives"] = this->lives;
		jsonValue["x"] = this->x;
		jsonValue["y"] = this->y;
		jsonValue["coins"] = this->coins;
		jsonValue["potions"] = this->potions;
		jsonValue["currentWeapon"] = this->currentWeapon.name;
		return jsonValue;
	}
};