#pragma once
#include "Includes.h"

#include "Map.h"
#include "Portal.h"

class TopCenter :public Map {
public:
	TopCenter() {
		name = "Top Center";

		Portal* left = new Portal();
		left->x = 0;
		left->y = COLS/2;
		left->xPlayerSpawn = ROWS-1;
		left->yPlayerSpawn = COLS/2;
		left->nextMap = 0; //The Top Left Map set in Main.
		portals.push_back(left);
		map[0][4]->icon = ' ';

		Portal* right = new Portal();
		right->x = ROWS;
		right->y = COLS/2;
		right->xPlayerSpawn = 1;
		right->yPlayerSpawn = COLS/2;
		right->nextMap = 2; //The Top Right Map set in Main.
		portals.push_back(right);
		map[8][4]->icon = ' ';

		Portal* down = new Portal();
		down->x = ROWS/2;
		down->y = COLS;
		down->xPlayerSpawn = ROWS/4;
		down->yPlayerSpawn = 1;
		down->nextMap = 4; //The Middle Center Map set in Main.
		portals.push_back(down);
		map[4][8]->icon = ' ';
	}
};