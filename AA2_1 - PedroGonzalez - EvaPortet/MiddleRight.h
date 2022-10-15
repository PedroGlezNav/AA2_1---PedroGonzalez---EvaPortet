#pragma once
#include "Includes.h"

#include "Map.h"
#include "Portal.h"

class MiddleRight :public Map {
public:
	MiddleRight() {
		name = "Middle Right";

		Portal* upper = new Portal();
		upper->x = ROWS / 2;
		upper->y = 0;
		upper->xPlayerSpawn = ROWS / 2;
		upper->yPlayerSpawn = COLS - 1;
		upper->nextMap = TOP_RIGHT;
		portals.push_back(upper);
		map[4][0]->icon = ' ';

		Portal* left = new Portal();
		left->x = 0;
		left->y = COLS / 2;
		left->xPlayerSpawn = ROWS - 1;
		left->yPlayerSpawn = COLS / 2;
		left->nextMap = MIDDLE_CENTER;
		portals.push_back(left);
		map[0][4]->icon = ' ';

		Portal* down = new Portal();
		down->x = ROWS / 2;
		down->y = COLS;
		down->xPlayerSpawn = ROWS / 2;
		down->yPlayerSpawn = 1;
		down->nextMap = DOWN_RIGHT;
		portals.push_back(down);
		map[4][8]->icon = ' ';

		Chest* newChest = new Chest();
		newChest->x = 7;
		newChest->y = 7;
		chests.push_back(newChest);
	}
};