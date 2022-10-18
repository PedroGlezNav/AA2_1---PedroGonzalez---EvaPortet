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
	srand(time(NULL));

	//SETTING GAME OBJECTS:
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

	gameManager.currentMap = MIDDLE_CENTER;
	gameManager.lastMap = TOP_CENTER;
	gameManager.timeToSave = time(NULL);

	Player player;
	player.actionTime = time(NULL);


	//IMPOTING SAVINGS (IN CASE THEY EXIST):
	std::ifstream* jsonPlayerReadFile = new std::ifstream("PlayerSave.json", std::ifstream::binary);
	if (!jsonPlayerReadFile->fail())
	{
		Json::Value jsonValue;
		*jsonPlayerReadFile >> jsonValue;
		jsonPlayerReadFile->close();

		Player* recoverPlayer = Player::Parse(jsonValue["PlayerSave"]);
		player = *recoverPlayer;
	}

	std::ifstream* jsonMapReadFile = new std::ifstream("CurrentMapSave.json", std::ifstream::binary);
	if (!jsonMapReadFile->fail())
	{
		Json::Value jsonValue;
		*jsonMapReadFile >> jsonValue;
		jsonMapReadFile->close();

		gameManager.Parse(jsonValue["CurrentMapSave"]);
	}


	//GAME LOOP:
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