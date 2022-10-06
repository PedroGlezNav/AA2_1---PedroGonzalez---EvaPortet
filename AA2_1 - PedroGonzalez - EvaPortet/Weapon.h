#pragma once
#include "Includes.h"

class Weapon {
public:
	enum Type { Unknown = 0, Sword = 1, Lance = 2 };
	Type type = Unknown;

	int damage;
	int range;
};