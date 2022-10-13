#pragma once
#include "Includes.h"

#include "Map.h"
#include "Portal.h"

class DownLeft :public Map {
public:
	DownLeft() {
		name = "Down Left";

		Portal* upper = new Portal();
		upper->x = ROWS / 2;
		upper->y = 0;
		upper->xPlayerSpawn = ROWS / 2;
		upper->yPlayerSpawn = COLS - 1;
		upper->nextMap = MIDDLE_LEFT;
		portals.push_back(upper);
		map[4][0]->icon = ' ';

		Portal* right = new Portal();
		right->x = ROWS;
		right->y = COLS / 2;
		right->xPlayerSpawn = 1;
		right->yPlayerSpawn = COLS / 2;
		right->nextMap = DOWN_CENTER;
		portals.push_back(right);
		map[8][4]->icon = ' ';
	}
};