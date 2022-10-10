#pragma once
#include "Includes.h"

#include "Map.h"
#include "InputManager.h"

class GameManager {
public:
	std::vector<Map*> maps;
	InputManager* inputManager = new InputManager();
	std::thread* keyListenerThread = new std::thread(&InputManager::startListening, inputManager);
	ConsoleControl consoleControl;

	int currentMap;
	int lastMap;

	void End() {

	}

	void Update(Player& player) {

		//Update for the Player:
		//keyListenerThread->join();
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
		}
	}

	void Draw(Player& player) {

		//Draw for the Map:
		if (currentMap != lastMap) {
			lastMap = currentMap;
			//system("CLS");
			maps[currentMap]->Draw(true);
		}
		maps[currentMap]->Draw(false);

		//ACTUALIZAR PANTALLA POR LOS OBJETOS DINAMICOS
		
		//Usar consoleControl.SetPosition(); para dibujar solo una casilla.

		//Draw for the UI: METER TODO EN UNA FUNCIÓN
		/*system("CLS");
		std::cout << "Coins: " << player.coins << " - ";
		std::cout << "Lifes: " << player.lives << " - ";
		std::cout << "Potions: " << player.potions << " - ";
		std::cout << "Weapon: " << player.currentWeapon.name;
		std::cout << "X: " << player.x;
		std::cout << "Y: " << player.y;*/

		//Draw for the Player:
		
		//Draw for the Enemies:
		
		//Draw for the Chests:
		
		//Draw for the Drops:
	}

	void Start() {
		currentMap = maps[currentMap]->MapToChange();
		maps[currentMap]->enemySpawnTime = time(NULL);
		maps[currentMap]->chestSpawnTime = time(NULL);
	}
};