#pragma once
#include "Includes.h"

#include "Portal.h"
#include "Chest.h"
#include "Player.h"
#include "Enemy.h"
#include "Node.h"
#include "ConsoleControl.h"

class Map
{
public:
	std::string name;

	std::vector<Portal*> portals; //(2 to 4)
	std::vector<Enemy*> enemies; //(0 to 5)
	std::vector<Chest*> chests; //(0 to 3)
	std::vector<Drop*> drops; //(When chests open or eemies Die)

	std::vector<std::vector<Node*>> map;

	int collidedPortal;
	int enemySpawnTime;
	int chestSpawnTime;

	Map() {
		for (int iR = 0; iR < ROWS + 1; iR++) {

			std::vector<Node*> newNodeVector;

			for (int iC = 0; iC < COLS + 1; iC++) {

				Node* newNode = new Node();

				if (iR == 0 || iC == 0 || iR == ROWS || iC == COLS) {
					newNode->x = iR;
					newNode->y = iC;
					newNode->icon = '#';
				}
				else {
					newNode->x = iR;
					newNode->y = iC;
					newNode->icon = ' ';
				}
				
				newNodeVector.push_back(newNode);
			}

			map.push_back(newNodeVector);
		}
	}

	void DrawMap(ConsoleControl& consoleControl) {
		system("CLS");
		for (int iR = 0; iR < ROWS + 1; iR++) {
			for (int iC = 0; iC < COLS + 1; iC++) {
				map[iR][iC]->Draw(consoleControl);
			}
		}
		consoleControl.SetPosition(0, COLS + 2);
		std::cout << name;
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

	bool PlayerEnteredPortal(Player& player) {
		for (int iter = 0; iter < portals.size(); iter++) {
			if (portals[iter]->checkPlayer(player)) {
				player.x = portals[iter]->xPlayerSpawn;
				player.y = portals[iter]->yPlayerSpawn;
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