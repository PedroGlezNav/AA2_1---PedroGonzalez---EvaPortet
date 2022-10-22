#pragma once
#include "Includes.h"

#include "Character.h"
#include "Weapon.h"
#include "Drop.h"
#include "Map.h"

class Enemy : public Character {
public:
	Drop drop;

	std::mutex* newDirectionMutex = new std::mutex();

	Enemy() : Character() {
		drop.type = Drop::Type::Unknown;
		icon = 'E';
	}

	void Draw(ConsoleControl& consoleControl) override {
		consoleControl.SetColor(ConsoleControl::ConsoleColor::WHITE, ConsoleControl::ConsoleColor::BLACK);
		consoleControl.SetPosition(lastX, lastY);
		std::cout << ' ';
		consoleControl.SetColor(ConsoleControl::ConsoleColor::RED, ConsoleControl::ConsoleColor::BLACK);
		consoleControl.SetPosition(x, y);
		std::cout << icon;
	}

	void ArtfIntel(Player& player, std::vector<Portal*>& mapPortals, std::vector<Enemy*>& mapEnemies, 
		std::vector<Chest*>& mapChest, std::vector<Drop*>& mapDrops/*, std::vector<std::vector<Node*>> mapNodes*/) {

		int newdirection = (Directions)(rand() % ((3) - (0) + 1) + (0));
		
		int newY, newX;
		switch (newdirection) {
		case Directions::UP: {
			newX = this->x;
			newY = this->y - 1;
			break;
		}
		case Directions::DOWN: {
			newX = this->x;
			newY = this->y + 1;
			break;
		}
		case Directions::LEFT: {
			newX = this->x;
			newY = this->y - 1;
			break;
		}
		case Directions::RIGHT: {
			newX = this->x;
			newY = this->y + 1;
			break;
		}
		}

		//Test if the temporary newX an newY collide with any of the elements of the game:
		bool collidedWithPortal = false, collidedWithEnemy = false, 
			collidedWithChest = false, collidedWithDrop = false/*, collidedWithWall = false*/;

		if (newX == player.x && newY == player.y) {
				Attack(player);
		}

		for (int iter = 0; iter < mapPortals.size(); iter++) {
			if (newX == mapPortals[iter]->x && newY == mapPortals[iter]->y) {
				collidedWithPortal = true;
				break;
			}
		}

		for (int iter = 0; iter < mapEnemies.size(); iter++) {
			if (newX == mapEnemies[iter]->x && newY == mapEnemies[iter]->y) {
				collidedWithEnemy = true;
				break;
			}
		}

		for (int iter = 0; iter < mapChest.size(); iter++) {
			if (newX == mapChest[iter]->x && newY == mapChest[iter]->y) {
				collidedWithChest = true;
				break;
			}
		}
		
		for (int iter = 0; iter < mapDrops.size(); iter++) {
			if (newX == mapDrops[iter]->x && newY == mapDrops[iter]->y) {
				collidedWithDrop = true;
				break;
			}
		}

		/*if (mapNodes[newX][newY].icon == '#') {
			collidedWithWall = true;
		}*/

		if (!collidedWithPortal && !collidedWithEnemy && !collidedWithChest && !collidedWithDrop /* && !collidedWithWall*/) {
			newDirectionMutex->lock();
			Move((Directions)newdirection);
			newDirectionMutex->unlock();
		}
	}

	void Drop() {
		drop.type = (Drop::Type)(rand() % ((2) - (0) + 1) + (0)); //rng->((max)-(min)+1)+(min)
		drop.DefineIcon();
		drop.x = this->x;
		drop.y = this->y;
	}
};