#pragma once
#include "Includes.h"

#include "Map.h"
#include "Portal.h"

class TopLeft :public Map {
public:
	TopLeft() {
		name = "Top Left";

		Portal* right = new Portal();
		right->x = 8;
		right->y = 4;
		right->xPlayerSpawn = 1;
		right->yPlayerSpawn = 4;
		right->nextMap = 1; //The Top Center Map set in Main.
		portals.push_back(right);
		map[8][4]->icon = ' ';

		Portal* down = new Portal();
		down->x = 4;
		down->y = 8;
		down->xPlayerSpawn = 4;
		down->yPlayerSpawn = 1;
		down->nextMap = 3; //The Middle Left Map set in Main.
		portals.push_back(down);
		map[4][8]->icon = ' ';
	}
};