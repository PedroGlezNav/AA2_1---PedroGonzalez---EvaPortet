#pragma once
#include "Includes.h"

#include "Portal.h"
#include "Chest.h"
#include "Player.h"
#include "Enemy.h"
#include "Node.h"
#include "ConsoleControl.h"

#define ROWS 8
#define COLS 8

class Map
{
public:
	std::vector<Portal*> portals; //(2 to 4)
	std::vector<Enemy*> enemies; //(0 to 5)
	std::vector<Chest*> chests; //(0 to 3)
	std::vector<Drop*> drops; //(When chests open or eemies Die)

	std::vector<std::vector<Node>> map;

	int collidedPortal;
	int enemySpawnTime;
	int chestSpawnTime;

	/*Map() {
		//PENSAR MÁS EN ELLO:
		for (int iterRows = 0; iterRows < ROWS; iterRows++) {
			Node newNodeVector;
			for (int iterCols = 0; iterCols < COLS; iterCols++) {
				
			}
			map[ROWS].push_back(newNodeVector);
		}
	}*/

	void DrawMap(bool changedMap, ConsoleControl& consoleControl) {
		if (changedMap) {
			for (auto row : map) {
				for (auto col : row) {
					col.Draw(consoleControl);
				}
				std::cout << "\n";
			}
		}
	}

	void DrawDynamics(ConsoleControl& consoleControl) {
		if (!enemies.empty()) {
			for (auto iter : enemies) {
				iter->Draw(consoleControl);
			}
		}

		if (!chests.empty()) {
			for (auto iter : chests) {
				iter->Draw(consoleControl);
			}
		}

		if (!portals.empty()) {
			for (auto iter : portals) {
				iter->Draw(consoleControl);
			}
		}

		if (!drops.empty()) {
			for (auto iter : drops) {
				iter->Draw(consoleControl);
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

	void AddNewChest(Player& player) {
		if (chestSpawnTime + 100 == time(NULL) && chests.size() < 3) {
			Chest newChest;
			newChest.drop = (Drop::Type)(rand() % 3 + 0);

			switch (rand() % 2 + 1) {
			case 1: //Spawn to the left of Player:
				newChest.x = rand() % (player.x - 1) + 1;
				break;
			case 2: //Spawn to the right of Player:
				newChest.x = rand() % ROWS + (player.x + 1);
				break;
			}

			switch (rand() % 2 + 1) {
			case 1: //Spawn over Player:
				newChest.y = rand() % (player.y - 1) + 1;
				break;
			case 2: //Spawn under Player:
				newChest.y = rand() % COLS + (player.y + 1);
				break;
			}
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