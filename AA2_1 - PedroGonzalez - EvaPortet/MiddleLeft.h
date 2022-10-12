#pragma once
#include "Includes.h"

#include "Map.h"
#include "Portal.h"

class MiddleLeft :public Map {
public:
	MiddleLeft() {
		name = "Middle Left";

		Portal* upper = new Portal();
		upper->x = 4;
		upper->y = 0;
		upper->nextMap = 0; //The Top Left Map set in Main.
		portals.push_back(upper);
		map[4][0]->icon = ' ';

		Portal* right = new Portal();
		right->x = 8;
		right->y = 4;
		right->nextMap = 4; //The Middle Center Map set in Main.
		portals.push_back(right);
		map[8][4]->icon = ' ';

		Portal* down = new Portal();
		down->x = 4;
		down->y = 8;
		down->nextMap = 6; //The Down Left Map set in Main.
		portals.push_back(down);
		map[4][8]->icon = ' ';
	}
};