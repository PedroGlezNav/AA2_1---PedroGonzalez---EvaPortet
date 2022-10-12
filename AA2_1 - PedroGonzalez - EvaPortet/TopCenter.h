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
		left->y = 4;
		left->xPlayerSpawn = 8;
		left->yPlayerSpawn = 4;
		left->nextMap = 0; //The Top Left Map set in Main.
		portals.push_back(left);
		map[0][4]->icon = ' ';

		Portal* right = new Portal();
		right->x = 8;
		right->y = 4;
		right->xPlayerSpawn = 1;
		right->yPlayerSpawn = 4;
		right->nextMap = 2; //The Top Right Map set in Main.
		portals.push_back(right);
		map[8][4]->icon = ' ';

		Portal* down = new Portal();
		down->x = 4;
		down->y = 8;
		down->nextMap = 4; //The Middle Center Map set in Main.
		portals.push_back(down);
		map[4][8]->icon = ' ';
	}
};