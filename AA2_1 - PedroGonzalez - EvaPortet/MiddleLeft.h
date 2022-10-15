#pragma once
#include "Includes.h"

#include "Map.h"
#include "Portal.h"

class MiddleLeft :public Map {
public:
	MiddleLeft() {
		name = "Middle Left";

		Portal* upper = new Portal();
		upper->x = ROWS/2;
		upper->y = 0;
		upper->xPlayerSpawn = ROWS/2;
		upper->yPlayerSpawn = COLS-1;
		upper->nextMap = TOP_LEFT;
		portals.push_back(upper);
		map[4][0]->icon = ' ';

		Portal* right = new Portal();
		right->x = ROWS;
		right->y = COLS/2;
		right->xPlayerSpawn = 1;
		right->yPlayerSpawn = COLS/2;
		right->nextMap = MIDDLE_CENTER;
		portals.push_back(right);
		map[8][4]->icon = ' ';

		Portal* down = new Portal();
		down->x = ROWS/2;
		down->y = COLS;
		down->xPlayerSpawn = ROWS/2;
		down->yPlayerSpawn = 1;
		down->nextMap = DOWN_LEFT;
		portals.push_back(down);
		map[4][8]->icon = ' ';

		Chest* newChest = new Chest();
		newChest->x = 1;
		newChest->y = 7;
		chests.push_back(newChest);
	}
};