#pragma once
#include "Includes.h"

#include "Map.h"
#include "InputManager.h"

class GameManager {
public:
	std::vector<Map*> maps;
	InputManager* inputManager = new InputManager();
	std::thread* keyListenerThread = new std::thread(&InputManager::startListening, inputManager);

	int currentMap;
	int lastMap;

	void End() {

	}

	void Update(Player& player) {

		//Update for the Player:
		keyListenerThread->join();
		if (player.actionTime + 200 == time(NULL)) {
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
			}

			//Update for the Enemies:

			//Update for the Chests:
			
			//Update for the Drops:
		}
	}

	void Draw() {

		//Draw for the Map:
		if (currentMap != lastMap) {
			lastMap = currentMap;
			maps[currentMap]->Draw(true);
		}
		maps[currentMap]->Draw(false);

		//Draw for the Player:
		
		//Draw for the Enemies:
		
		//Draw for the Chests:
		
		//Draw for the Drops:
	}

	void Start(Map currentMap, bool isPlaying) {

	}
};