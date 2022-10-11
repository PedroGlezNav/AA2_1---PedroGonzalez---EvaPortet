#pragma once
#include "Includes.h"

#include "Map.h"
#include "Portal.h"

class DownCenter :public Map {
public:
	DownCenter() {
		Portal* upper = new Portal();
		upper->x = 4;
		upper->y = 0;
		upper->nextMap = 2; //The Top Center Map set in Main.
		portals.push_back(upper);

		Portal* left = new Portal();
		left->x = 0;
		left->y = 4;
		left->nextMap = 4; //The Middle Left Map set in Main.
		portals.push_back(left);

		Portal* right = new Portal();
		right->x = 8;
		right->y = 4;
		right->nextMap = 5; //The Middle Right Map set in Main.
		portals.push_back(right);
	}
};