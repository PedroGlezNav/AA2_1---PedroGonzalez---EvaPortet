#pragma once
#include "Includes.h"

#include "Map.h"
#include "Portal.h"

class MiddleCenter :public Map {
public:
	MiddleCenter(){
		name = "Middle Center";

		Portal *upper = new Portal();
		upper->x = 4;
		upper->y = 0;
		upper->nextMap = 1; //The Top Center Map set in Main.
		portals.push_back(upper);
		map[4][0]->icon = ' ';

		Portal *left = new Portal();
		left->x = 0;
		left->y = 4;
		left->nextMap = 3; //The Middle Left Map set in Main.
		portals.push_back(left);
		map[0][4]->icon = ' ';

		Portal* right = new Portal();
		right->x = 8;
		right->y = 4;
		right->nextMap = 5; //The Middle Right Map set in Main.
		portals.push_back(right);
		map[8][4]->icon = ' ';

		Portal* down = new Portal();
		down->x = 4;
		down->y = 8;
		down->nextMap = 7; //The Down Center Map set in Main.
		portals.push_back(down);
		map[4][8]->icon = ' ';
	}
};