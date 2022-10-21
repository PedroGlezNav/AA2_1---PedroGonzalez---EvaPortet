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
	int collidedDrop;
	int collidedChest;
	int collidedEnemy;

	int enemySpawnTime;
	int chestSpawnTime;

	Map() {

		//Create the basic Node template:
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

	void UpdateEnemies(Player &player) {
		if (!enemies.empty()) {
			for (int iter = 0; iter < enemies.size(); iter++) {

				if (enemies[iter]->actionTime + 2 <= time(NULL)) {
					std::thread* updateEnemiesThread = new std::thread(&Enemy::ArtfIntel, std::ref(player), 
						std::ref(this->portals), std::ref(this->enemies), std::ref(this->chests), 
						std::ref(this->drops), std::ref(this->map), enemies[iter]);
					enemies[iter]->actionTime = time(NULL);
					updateEnemiesThread->detach();
				}
				if (enemies[iter]->isDead) {
					enemies[iter]->Drop();
					drops.push_back(&enemies[iter]->drop);
					enemies.erase(enemies.begin() + iter);
				}
			}
		}
	}

	void AddNewEnemies(Player &player) {
		if (enemySpawnTime + 12 <= time(NULL) && enemies.size() < 5) {

			Enemy* newEnemy = new Enemy();

			switch (rand() % 2 + 1) {
			case 1: //Spawn to the left of Player:
				if (player.x == 1) {
					delete newEnemy;
					newEnemy = nullptr;
					return;
				}
				else {
					newEnemy->x = rand() % ((player.x - 1) - (1) + 1) + (1); //rng->((max)-(min)+1)+(min)
				}
				break;
			case 2: //Spawn to the right of Player:
				if (player.x == ROWS - 1) {
					delete newEnemy;
					newEnemy = nullptr;
					return;
				}
				else {
					newEnemy->x = rand() % ((ROWS - 1) - (player.x + 1) + 1) + (player.x + 1);
				}
				break;
			}

			switch (rand() % 2 + 1) {
			case 1: //Spawn over Player:
				if (player.y == 1) {
					delete newEnemy;
					newEnemy = nullptr;
					return;
				}
				else {
					newEnemy->y = rand() % ((player.y - 1) - (1) + 1) + (1);
				}
				break;
			case 2: //Spawn under Player:
				if (player.y == COLS - 1) {
					delete newEnemy;
					newEnemy = nullptr;
					return;
				}
				else {
					newEnemy->y = rand() % ((COLS - 1) - (player.y + 1) + 1) + (player.y + 1);
				}
				break;
			}

			enemies.push_back(newEnemy);
			newEnemy->actionTime = time(NULL);
		}
	}

	void AddNewChest(Player& player) {
		if (chestSpawnTime + 5 <= time(NULL) && chests.size() < 3) {
			Chest* newChest = new Chest();

			switch (rand() % 2 + 1) {
			case 1: //Spawn to the left of Player:
			{
				if (player.x == 1) {
					delete newChest;
					newChest = nullptr;
					return;
				}
				else {
					newChest->x = rand() % ((player.x - 1) - (1) + 1) + (1); //rng->((max)-(min)+1)+(min)
				}
			}
			break;
			case 2: //Spawn to the right of Player:
			{
				if (player.x == ROWS - 1) {
					delete newChest;
					newChest = nullptr;
					return;
				}
				else {
					newChest->x = rand() % ((ROWS - 1) - (player.x + 1) + 1) + (player.x + 1);
				}
			}
			break;
			}

			switch (rand() % 2 + 1) {
			case 1: //Spawn over Player:
			{
				if (player.y == 1) {
					delete newChest;
					newChest = nullptr;
					return;
				}
				else {
					newChest->y = rand() % ((player.y - 1) - (1) + 1) + (1);
				}
			}
			break;
				
			case 2: //Spawn under Player:
			{
				if (player.y == COLS - 1) {
					delete newChest;
					newChest = nullptr;
					return;
				}
				else {
					newChest->y = rand() % ((COLS - 1) - (player.y + 1) + 1) + (player.y + 1);
				}
			}
			break;
			}

			chests.push_back(newChest);
			chestSpawnTime = time(NULL);
		}
	}

	bool PlayerEnteredPortal(Player& player) {
		if (!portals.empty()) {
			for (int iter = 0; iter < portals.size(); iter++) {
				if (portals[iter]->checkPlayer(player)) {
					player.x = portals[iter]->xPlayerSpawn;
					player.y = portals[iter]->yPlayerSpawn;
					collidedPortal = iter;
					return true;
				}
			}
		}
		return false;
	}

	bool PlayerIsOnAnyDrop(int x, int y) {
		if (!drops.empty()) {
			for (int iter = 0; iter < drops.size(); iter++) {
				if (drops[iter]->PlayerIsOnDrop(x,y)) {
					collidedDrop = iter;
					return true;
				}
			}
		}
		return false;
	}

	bool PlayerCollidedChest(int x, int y) {
		if (!chests.empty()) {
			for (int iter = 0; iter < chests.size(); iter++) {
				if (chests[iter]->PlayerAtacksChest(x, y)) {
					collidedChest = iter;
					return true;
				}
			}
		}
		return false;
	}

	int MapToChange() {
		return portals[collidedPortal]->nextMap;
	}
};