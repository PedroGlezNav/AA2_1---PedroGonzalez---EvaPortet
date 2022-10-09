#pragma once
#include "Includes.h"

#include "Portal.h"
#include "Chest.h"
#include "Player.h"

class Map
{
public:
	std::vector<Portal*> portals; //(2-4)
	std::vector<Chest*> chests; //(x)
	std::vector<Enemy*> enemies; //(x)
	std::vector<Drop*> drops; //(x)
	std::vector<std::vector<char>> map{ { '#', '#', '#', ' ', '#', '#', '#'},
										{ '#', ' ', ' ', ' ', ' ', ' ', '#'},
										{ '#', ' ', ' ', ' ', ' ', ' ', '#'},
										{ ' ', ' ', ' ', ' ', ' ', ' ', ' '},
										{ '#', ' ', ' ', ' ', ' ', ' ', '#'},
										{ '#', ' ', ' ', ' ', ' ', ' ', '#'},
										{ '#', '#', '#', ' ', '#', '#', '#'} };

	int collidedPortal;

	void Draw(bool changedMap) {
		if (changedMap) {
			for (auto row : map) {
				for (auto col : row) {
					std::cout << col;
				}
				std::cout << "\n";
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