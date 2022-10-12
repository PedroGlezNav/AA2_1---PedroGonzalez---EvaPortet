#pragma once
#include "Includes.h"

#include "Map.h"
#include "Portal.h"

class TopRight :public Map {
public:
	TopRight() {
		name = "Top Right";

		Portal* left = new Portal();
		left->x = 0;
		left->y = 4;
		left->nextMap = 1; //The Top Center Map set in Main.
		portals.push_back(left);
		map[0][4]->icon = ' ';

		Portal* down = new Portal();
		down->x = 4;
		down->y = 8;
		down->nextMap = 5; //The Middle Rigth Map set in Main.
		portals.push_back(down);
		map[4][8]->icon = ' ';
	}
};