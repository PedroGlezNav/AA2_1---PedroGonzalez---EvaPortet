#pragma once
#include "Includes.h"

#include "Map.h"
#include "Portal.h"

class DownLeft :public Map {
public:
	DownLeft() {
		name = "Down Left";

		Portal* upper = new Portal();
		upper->x = 4;
		upper->y = 0;
		upper->nextMap = 3; //The Middle Left Map set in Main.
		portals.push_back(upper);
		map[4][0]->icon = ' ';

		Portal* right = new Portal();
		right->x = 8;
		right->y = 4;
		right->nextMap = 7; //The Down Center Map set in Main.
		portals.push_back(right);
		map[8][4]->icon = ' ';
	}
};