#pragma once
#include "Includes.h"

#include "Map.h"
#include "Portal.h"

class DownCenter :public Map {
public:
	DownCenter() {
		name = "Down Center";

		Portal* upper = new Portal();
		upper->x = 4;
		upper->y = 0;
		upper->nextMap = 4; //The Middle Center Map set in Main.
		portals.push_back(upper);
		map[4][0]->icon = ' ';

		Portal* left = new Portal();
		left->x = 0;
		left->y = 4;
		left->nextMap = 6; //The Down Left Map set in Main.
		portals.push_back(left);
		map[0][4]->icon = ' ';

		Portal* right = new Portal();
		right->x = 8;
		right->y = 4;
		right->nextMap = 8; //The Down Right Map set in Main.
		portals.push_back(right);
		map[8][4]->icon = ' ';
	}
};