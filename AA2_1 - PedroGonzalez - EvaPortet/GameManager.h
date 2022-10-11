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

	void End() {

	}

	void Update(Player& player) {

		//Update for the Player:
		std::thread* keyListenerThread = new std::thread(&InputManager::startListening, inputManager);
		
		if (player.actionTime + 1 == time(NULL)) {
			switch (inputManager->lastInput()) {
			case KB_UP:
			{
				player.Move(Character::Directions::UP);
				break;
			}
			case KB_LEFT:
			{
				player.Move(Character::Directions::LEFT);
				break;
			}
			case KB_RIGHT:
			{
				player.Move(Character::Directions::RIGHT);
				break;
			}
			case KB_DOWN:
			{
				player.Move(Character::Directions::DOWN);
				break;
			}
			case KB_SPACE:
			{
				player.Heal();
				break;
			}
			}

			//Update for the Enemies:

			//Update for the Chests:
			
			//Update for the Drops:

			//El detach va al final burro:
			keyListenerThread->detach();
		}
	}

	void Draw(Player& player, ConsoleControl& consoleControl) {

		//Draw for the Map:
		if (currentMap != lastMap) {
			lastMap = currentMap;
			maps[currentMap]->DrawMap(true, consoleControl);
		}
		maps[currentMap]->DrawMap(false, consoleControl);

		//Draw for the Player:
		player.Draw(consoleControl);

		//Draw for the Enemies, Chests, Drops & Portals:
		maps[currentMap]->DrawDynamics(consoleControl);

		//Draw for the UI:
		player.DrawInventory();
	}

	void Start() {
		currentMap = maps[currentMap]->MapToChange();
		maps[currentMap]->enemySpawnTime = time(NULL);
		maps[currentMap]->chestSpawnTime = time(NULL);
	}
};