#pragma once
#include "Includes.h"

#include "Map.h"

class MiddleCenter :public Map {
public:
	MiddleCenter(){
		name = "Middle Center";

		Portal *upper = new Portal();
		upper->x = ROWS/2;
		upper->y = 0;
		upper->xPlayerSpawn = ROWS/2;
		upper->yPlayerSpawn = COLS-1;
		upper->nextMap = TOP_CENTER;
		portals.push_back(upper);
		map[4][0]->icon = ' ';

		Portal *left = new Portal();
		left->x = 0;
		left->y = COLS/2;
		left->xPlayerSpawn = ROWS-1;
		left->yPlayerSpawn = COLS/2;
		left->nextMap = MIDDLE_LEFT;
		portals.push_back(left);
		map[0][4]->icon = ' ';

		Portal* right = new Portal();
		right->x = ROWS;
		right->y = COLS / 2;
		right->xPlayerSpawn = 1;
		right->yPlayerSpawn = COLS / 2;
		right->nextMap = MIDDLE_RIGHT;
		portals.push_back(right);
		map[8][4]->icon = ' ';

		Portal* down = new Portal();
		down->x = ROWS / 2;
		down->y = COLS;
		down->xPlayerSpawn = ROWS / 2;
		down->yPlayerSpawn = 1;
		down->nextMap = DOWN_CENTER;
		portals.push_back(down);
		map[4][8]->icon = ' ';

		Chest* newChest = new Chest();
		newChest->x = 1;
		newChest->y = 1;
		chests.push_back(newChest);

		Chest* newChest2 = new Chest();
		newChest2->x = 4;
		newChest2->y = 1;
		chests.push_back(newChest2);

		Chest* newChest3 = new Chest();
		newChest3->x = 7;
		newChest3->y = 1;
		chests.push_back(newChest3);
	}
};