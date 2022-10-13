#pragma once
#include "Includes.h"

#include "Map.h"
#include "Portal.h"

class DownCenter :public Map {
public:
	DownCenter() {
		name = "Down Center";

		Portal* upper = new Portal();
		upper->x = ROWS / 2;
		upper->y = 0;
		upper->xPlayerSpawn = ROWS / 2;
		upper->yPlayerSpawn = COLS - 1;
		upper->nextMap = MIDDLE_CENTER;
		portals.push_back(upper);
		map[4][0]->icon = ' ';

		Portal* left = new Portal();
		left->x = 0;
		left->y = COLS / 2;
		left->xPlayerSpawn = ROWS - 1;
		left->yPlayerSpawn = COLS / 2;
		left->nextMap = DOWN_LEFT;
		portals.push_back(left);
		map[0][4]->icon = ' ';

		Portal* right = new Portal();
		right->x = ROWS;
		right->y = COLS / 2;
		right->xPlayerSpawn = 1;
		right->yPlayerSpawn = COLS / 2;
		right->nextMap = DOWN_RIGHT;
		portals.push_back(right);
		map[8][4]->icon = ' ';
	}
};