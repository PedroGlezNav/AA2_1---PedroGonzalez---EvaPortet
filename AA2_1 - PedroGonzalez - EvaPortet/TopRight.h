#pragma once
#include "Includes.h"

#include "Map.h"
#include "Portal.h"

class TopRight :public Map {
public:
	TopRight() {
		Portal* left = new Portal();
		left->x = 0;
		left->y = 4;
		left->nextMap = 4; //The Middle Left Map set in Main.
		portals.push_back(left);

		Portal* down = new Portal();
		down->x = 4;
		down->y = 8;
		down->nextMap = 7; //The Down Center Map set in Main.
		portals.push_back(down);
	}
};