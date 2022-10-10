#pragma once
#include "Includes.h"

#include "Portal.h"
#include "Chest.h"
#include "Player.h"
#include "Enemy.h"

#define ROWS 8
#define COLS 8

class Map
{
public:
	std::vector<Portal*> portals; //(2-4)
	std::vector<Chest*> chests; //(x)
	std::vector<Enemy*> enemies; //(x)
	std::vector<Drop*> drops; //(x)
	std::vector<std::vector<char>> map{ { '#', '#', '#', '#', ' ', '#', '#', '#', '#'},
										{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
										{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
										{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
										{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
										{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
										{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
										{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
										{ '#', '#', '#', '#', ' ', '#', '#', '#', '#'} };

	int collidedPortal;
	int enemySpawnTime;
	int chestSpawnTime;

	void Draw(bool changedMap) {
		if (changedMap) {
			for (auto row : map) {
				for (auto col : row) {
					std::cout << col;
				}
				std::cout << "\n";
			}
		}
	}

	void AddNewEnemies(Player &player) {
		if (enemySpawnTime + 100 == time(NULL) && enemies.size() < 5) {

			Enemy newEnemy;
			newEnemy.drop = (Drop::Type)(rand() % 3 + 0);
			newEnemy.actionTime = time(NULL);

			switch (rand() % 2 + 1) {
			case 1: //Spawn to the left of Player:
				newEnemy.x = rand() % (player.x - 1) + 1;
				break;
			case 2: //Spawn to the right of Player:
				newEnemy.x = rand() % ROWS + (player.x + 1);
				break;
			}

			switch (rand() % 2 + 1) {
			case 1: //Spawn over Player:
				newEnemy.y = rand() % (player.y - 1) + 1;
				break;
			case 2: //Spawn under Player:
				newEnemy.y = rand() % COLS + (player.y + 1);
				break;
			}
		}
	}

	void AddNewChest() {
		if (chestSpawnTime + 100 == time(NULL) && chests.size() < 3) {
			Chest newChest;
			newChest.drop = (Drop::Type)(rand() % 3 + 0);
			//newChest.x
			//newChest.y
		}
	}

	bool PlayerEnteredPortal(Player player) {
		for (int iter = 0; iter < portals.size(); iter++) {
			if (portals[iter]->checkPlayer(player)) {
				collidedPortal = iter;
				return true;
			}
		}
		return false;
	}

	int MapToChange() {
		return portals[collidedPortal]->nextMap;
	}
};