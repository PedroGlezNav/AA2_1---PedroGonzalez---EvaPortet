#pragma once
#include "Includes.h"

#include "Map.h"
#include "Portal.h"

class TopLeft :public Map {
public:
	TopLeft() {
		name = "Top Left";

		Portal* right = new Portal();
		right->x = ROWS;
		right->y = COLS/2;
		right->xPlayerSpawn = 1;
		right->yPlayerSpawn = COLS/2;
		right->nextMap = 1; //The Top Center Map set in Main.
		portals.push_back(right);
		map[8][4]->icon = ' ';

		Portal* down = new Portal();
		down->x = ROWS/2;
		down->y = COLS;
		down->xPlayerSpawn = ROWS/2;
		down->yPlayerSpawn = 1;
		down->nextMap = 3; //The Middle Left Map set in Main.
		portals.push_back(down);
		map[4][8]->icon = ' ';
	}
};