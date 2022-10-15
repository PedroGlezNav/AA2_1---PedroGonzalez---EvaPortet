#pragma once
#include "Includes.h"

#include "Map.h"
#include "Portal.h"

class DownRight :public Map {
public:
	DownRight() {
		name = "Down Right";

		Portal* upper = new Portal();
		upper->x = ROWS / 2;
		upper->y = 0;
		upper->xPlayerSpawn = ROWS / 2;
		upper->yPlayerSpawn = COLS - 1;
		upper->nextMap = MIDDLE_RIGHT;
		portals.push_back(upper);
		map[4][0]->icon = ' ';

		Portal* left = new Portal();
		left->x = 0;
		left->y = COLS / 2;
		left->xPlayerSpawn = ROWS - 1;
		left->yPlayerSpawn = COLS / 2;
		left->nextMap = DOWN_CENTER;
		portals.push_back(left);
		map[0][4]->icon = ' ';

		Chest* newChest = new Chest();
		newChest->x = 1;
		newChest->y = 1;
		chests.push_back(newChest);
	}
};