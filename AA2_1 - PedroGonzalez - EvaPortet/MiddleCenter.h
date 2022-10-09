#pragma once
#include "Includes.h"

#include "Map.h"
#include "Portal.h"

class MiddleCenter :public Map {
public:
	MiddleCenter(){
		Portal *upper = new Portal();
		upper->x = 3;
		upper->y = 0;
		upper->nextMap = 2; //The Top Center Map set in Main.
		portals.push_back(upper);

		Portal *left = new Portal();
		left->x = 0;
		left->y = 3;
		left->nextMap = 4; //The Middle Left Map set in Main.
		portals.push_back(left);

		Portal* right = new Portal();
		right->x = 6;
		right->y = 3;
		right->nextMap = 5; //The Middle Right Map set in Main.
		portals.push_back(right);

		Portal* down = new Portal();
		down->x = 3;
		down->y = 6;
		down->nextMap = 7; //The Down Center Map set in Main.
		portals.push_back(down);
	}
};