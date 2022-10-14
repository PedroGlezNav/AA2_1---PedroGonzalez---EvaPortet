#include "Includes.h"

#include "GameManager.h"
#include "Map.h"
#include "TopLeft.h"
#include "TopCenter.h"
#include "TopRight.h"
#include "MiddleLeft.h"
#include "MiddleCenter.h"
#include "MiddleRight.h"
#include "DownLeft.h"
#include "DownCenter.h"
#include "DownRight.h"
#include "Player.h"
#include "Enemy.h"
#include "Portal.h"
#include "Chest.h"
#include "ConsoleControl.h"

void main() {
	GameManager gameManager;
	ConsoleControl consoleControl;

	TopLeft topLeft;
	TopCenter topCenter;
	TopRight topRight;
	MiddleLeft middleLeft;
	MiddleCenter middleCenter;
	MiddleRight middleRight;
	DownLeft downLeft;
	DownCenter downCenter;
	DownRight downRight;

	gameManager.maps.push_back(&topLeft);
	gameManager.maps.push_back(&topCenter);
	gameManager.maps.push_back(&topRight);
	gameManager.maps.push_back(&middleLeft);
	gameManager.maps.push_back(&middleCenter);
	gameManager.maps.push_back(&middleRight);
	gameManager.maps.push_back(&downLeft);
	gameManager.maps.push_back(&downCenter);
	gameManager.maps.push_back(&downRight);

	gameManager.currentMap = 4;
	gameManager.lastMap = 1;

	Player player;
	srand(time(NULL));
	player.actionTime = time(NULL);

	while (!player.isDead && !gameManager.endGame) {

		if (!gameManager.maps.empty()) {

			//Change scene?
			if (gameManager.maps[gameManager.currentMap]->PlayerEnteredPortal(player)) {
				gameManager.Start();
			}
			
			//Update scene:
			gameManager.Update(player);

			//Draw:
			gameManager.Draw(player, consoleControl);
		}

		else {
			std::cout << "Not menus available :(\n";
			return;
		}
	}

	gameManager.End();
}