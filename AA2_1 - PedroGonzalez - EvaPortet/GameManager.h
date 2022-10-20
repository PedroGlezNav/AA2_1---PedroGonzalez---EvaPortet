#pragma once
#include "Includes.h"

#include "Map.h"
#include "InputManager.h"

class GameManager {
public:
	std::vector<Map*> maps;
	InputManager* inputManager = new InputManager();
	
	int currentMap;
	int lastMap;
	int timeToSave;
	bool endGame = false;
	bool playerCollidedChest = false;

	void End() {}

	void Start() {
		currentMap = maps[currentMap]->MapToChange();
		maps[currentMap]->enemySpawnTime = time(NULL);
		maps[currentMap]->chestSpawnTime = time(NULL);
	}

	void Update(Player& player) {

		//Update for the Player:
		std::thread* keyListenerThread = new std::thread(&InputManager::startListening, inputManager);
		
		if (player.actionTime + 1 <= time(NULL)) {
			switch (inputManager->lastMovementInput()) {
			case KB_UP: {
				if (maps[currentMap]->PlayerCollidedChest(player.x, player.y - player.currentWeapon.range) || 
					maps[currentMap]->PlayerCollidedChest(player.x, player.y - player.currentWeapon.range + 1)) {
					playerCollidedChest = true;
				}
				else if (maps[currentMap]->map[player.x][player.y - 1]->icon != '#') {
					player.Move(Character::Directions::UP);
				}
				break;
			}
			case KB_LEFT: {
				if (maps[currentMap]->PlayerCollidedChest(player.x - player.currentWeapon.range, player.y) ||
					maps[currentMap]->PlayerCollidedChest(player.x - player.currentWeapon.range + 1, player.y)) {
					playerCollidedChest = true;
				}
				else if (maps[currentMap]->map[player.x - 1][player.y]->icon != '#') {
					player.Move(Character::Directions::LEFT);
				}
				break;
			}
			case KB_RIGHT: {
				if (maps[currentMap]->PlayerCollidedChest(player.x + player.currentWeapon.range, player.y) ||
					maps[currentMap]->PlayerCollidedChest(player.x + player.currentWeapon.range - 1, player.y)) {
					playerCollidedChest = true;
				}
				if (maps[currentMap]->map[player.x + 1][player.y]->icon != '#') {
					player.Move(Character::Directions::RIGHT);
				}
				break;
			}
			case KB_DOWN: {
				if (maps[currentMap]->PlayerCollidedChest(player.x, player.y + player.currentWeapon.range) ||
					maps[currentMap]->PlayerCollidedChest(player.x, player.y + player.currentWeapon.range - 1)) {
					playerCollidedChest = true;
				}
				else if (maps[currentMap]->map[player.x][player.y + 1]->icon != '#') {
					player.Move(Character::Directions::DOWN);
				}
				break;
			}
			}

			player.actionTime = time(NULL);
		}

		switch (inputManager->lastActionInput()) {
		case KB_SPACE: {
			player.Heal();
			break;
		}
		case KB_ESCAPE: {
			endGame = true;
			break;
		}
		}
		keyListenerThread->detach();

		if (timeToSave + 4 <= time(NULL)) {
			Json::Value newPlayerJsonValue;
			newPlayerJsonValue["PlayerSave"] = player.ToJsonValue();

			std::ofstream* jsonWritePlayerFile = new std::ofstream("PlayerSave.json", std::ifstream::binary);

			if (!jsonWritePlayerFile->fail())
			{
				*jsonWritePlayerFile << newPlayerJsonValue;
				jsonWritePlayerFile->close();
			}

			Json::Value newMapJsonValue;
			newMapJsonValue["CurrentMapSave"] = this->ToJsonValue();

			std::ofstream* jsonWriteMapFile = new std::ofstream("CurrentMapSave.json", std::ifstream::binary);

			if (!jsonWriteMapFile->fail())
			{
				*jsonWriteMapFile << newMapJsonValue;
				jsonWriteMapFile->close();
			}
		}

		//Update for the Enemies:
		maps[currentMap]->UpdateEnemies(player);

		//Update for the Chests:
		if (playerCollidedChest) {
			maps[currentMap]->chests[maps[currentMap]->collidedChest]->Drop();
			maps[currentMap]->drops.push_back(&maps[currentMap]->chests[maps[currentMap]->collidedChest]->drop);
			maps[currentMap]->chests.erase(maps[currentMap]->chests.begin() + maps[currentMap]->collidedChest);
			playerCollidedChest = false;
		}
		maps[currentMap]->AddNewChest(player);

		//Update for the Drops:
		if (maps[currentMap]->PlayerIsOnAnyDrop(player.x, player.y)) {
			player.GetItem(*maps[currentMap]->drops[maps[currentMap]->collidedDrop]);
			maps[currentMap]->drops.erase(maps[currentMap]->drops.begin() + maps[currentMap]->collidedDrop);
		}
	}

	void Draw(Player& player, ConsoleControl& consoleControl) {

		//Draw for the Map:
		if (currentMap != lastMap) {
			lastMap = currentMap;
			maps[currentMap]->DrawMap(consoleControl);
		}

		//Draw for the Player:
		player.Draw(consoleControl);

		//Draw for the Enemies, Chests, Drops & Portals:
		maps[currentMap]->DrawDynamics(consoleControl);

		//Draw for the UI:
		player.DrawInventory(consoleControl);
	}

	void Parse(Json::Value jsonValue) {
		try {
			currentMap = jsonValue["currentMap"].asInt();
		}

		catch (const std::exception&)
		{
			currentMap = MIDDLE_CENTER;
		}
	}

	Json::Value ToJsonValue() {
		Json::Value jsonValue;
		jsonValue["currentMap"] = this->currentMap;
		return jsonValue;
	}
};