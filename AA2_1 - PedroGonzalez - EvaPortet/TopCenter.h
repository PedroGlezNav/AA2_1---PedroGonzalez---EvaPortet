#pragma once
#include "Includes.h"

#include "Map.h"
#include "Portal.h"

class TopCenter :public Map {
public:
	TopCenter() {
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

		Portal* down = new Portal();
		down->x = 4;
		down->y = 8;
		down->nextMap = 7; //The Down Center Map set in Main.
		portals.push_back(down);
	}
};