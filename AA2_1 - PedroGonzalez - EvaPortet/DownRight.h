#pragma once
#include "Includes.h"

#include "Map.h"
#include "Portal.h"

class DownRight :public Map {
public:
	DownRight() {
		name = "Down Right";

		Portal* upper = new Portal();
		upper->x = 4;
		upper->y = 0;
		upper->nextMap = 5; //The Middle Right Map set in Main.
		portals.push_back(upper);
		map[4][0]->icon = ' ';

		Portal* left = new Portal();
		left->x = 0;
		left->y = 4;
		left->nextMap = 7; //The Down Center Map set in Main.
		portals.push_back(left);
		map[0][4]->icon = ' ';
	}
};