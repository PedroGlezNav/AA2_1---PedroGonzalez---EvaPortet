#pragma once
#include "Includes.h"

#include "Map.h"
#include "Portal.h"

class MiddleLeft :public Map {
public:
	MiddleLeft() {
		Portal* upper = new Portal();
		upper->x = 4;
		upper->y = 0;
		upper->nextMap = 2; //The Top Center Map set in Main.
		portals.push_back(upper);

		Portal* right = new Portal();
		right->x = 8;
		right->y = 4;
		right->nextMap = 5; //The Middle Right Map set in Main.
		portals.push_back(right);

		Portal* down = new Portal();
		down->x = 4;
		down->y = 8;
		down->nextMap = 7; //The Down Center Map set in Main.
		portals.push_back(down);
	}
};