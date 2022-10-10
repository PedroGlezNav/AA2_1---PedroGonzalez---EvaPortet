#pragma once
#include "Includes.h"

#include "Drop.h"

class Chest {
public:
	int x, y;
	Drop::Type drop;
	char icon;

	Chest() {
		x = 0;
		y = 0;
		drop = Drop::Type::Unknown;
		icon = 'C';
	}

	void Drop() {

	}
};