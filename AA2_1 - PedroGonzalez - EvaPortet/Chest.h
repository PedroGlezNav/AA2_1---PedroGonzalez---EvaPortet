#pragma once
#include "Includes.h"

#include "Drop.h"

class Chest {
	int x, y;
	Drop drop;

	Chest() {
		x = 0;
		y = 0;
		drop.type = Drop::Type::Unknown;
	}

	void Drop() {

	}
};