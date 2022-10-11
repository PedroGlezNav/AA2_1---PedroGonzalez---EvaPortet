#include "Includes.h"

#include "GameManager.h"
#include "Map.h"
#include "MiddleCenter.h"
#include "Player.h"
#include "Enemy.h"
#include "Portal.h"
#include "Chest.h"
#include "ConsoleControl.h"

void main() {
	GameManager gameManager;
	ConsoleControl consoleControl;

	MiddleCenter middleCenter;
	//TopLeft topLeft
	//TopCenter topCenter
	//TopRight topRight
	//MiddleLeft middleLeft
	//MiddleRight middleRight
	//DownLeft downLeft
	//DownCenter downCenter
	//DownRight downRight

	gameManager.maps.push_back(&middleCenter);
	//gameManager.maps.(&topLeft);
	//gameManager.maps.(&topCenter);
	//gameManager.maps.(&topRight);
	//gameManager.maps.(&middleLeft);
	//gameManager.maps.(&middleRight);
	//gameManager.maps.(&downLeft);
	//gameManager.maps.(&downCenter);
	//gameManager.maps.(&downRight);

	gameManager.currentMap = 0;
	gameManager.lastMap = 1;

	Player player;
	player.actionTime = time(NULL);

	while (!player.isDead) {
		
		if (!gameManager.maps.empty()) {

			//Change scene?
			if (gameManager.maps[gameManager.currentMap]->PlayerEnteredPortal(player)) {

				gameManager.Start();
			}

			//Draw:
			gameManager.Draw(player, consoleControl);

			//Update scene:
			gameManager.Update(player);
		}

		else {
			std::cout << "Not menus available :(\n";
			return;
		}
	}
}