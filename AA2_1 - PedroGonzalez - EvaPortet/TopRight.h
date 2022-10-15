#pragma once
#include "Includes.h"

#include "Map.h"
#include "Portal.h"

class TopRight :public Map {
public:
	TopRight() {
		name = "Top Right";

		Portal* left = new Portal();
		left->x = 0;
		left->y = COLS/2;
		left->xPlayerSpawn = ROWS-1;
		left->yPlayerSpawn = COLS/2;
		left->nextMap = TOP_CENTER;
		portals.push_back(left);
		map[0][4]->icon = ' ';

		Portal* down = new Portal();
		down->x = ROWS/2;
		down->y = COLS;
		down->xPlayerSpawn = ROWS/2;
		down->yPlayerSpawn = 1;
		down->nextMap = MIDDLE_RIGHT;
		portals.push_back(down);
		map[4][8]->icon = ' ';

		Chest* newChest = new Chest();
		newChest->x = 1;
		newChest->y = 7;
		chests.push_back(newChest);
	}
};