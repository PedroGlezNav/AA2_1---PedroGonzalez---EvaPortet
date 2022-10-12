#pragma once
#include "Includes.h"

#include "Map.h"
#include "Portal.h"

class MiddleRight :public Map {
public:
	MiddleRight() {
		name = "Middle Right";

		Portal* upper = new Portal();
		upper->x = 4;
		upper->y = 0;
		upper->nextMap = 2; //The Top Right Map set in Main.
		portals.push_back(upper);
		map[4][0]->icon = ' ';

		Portal* left = new Portal();
		left->x = 0;
		left->y = 4;
		left->nextMap = 4; //The Middle Center Map set in Main.
		portals.push_back(left);
		map[0][4]->icon = ' ';

		Portal* down = new Portal();
		down->x = 4;
		down->y = 8;
		down->nextMap = 8; //The Down Right Map set in Main.
		portals.push_back(down);
		map[4][8]->icon = ' ';
	}
};