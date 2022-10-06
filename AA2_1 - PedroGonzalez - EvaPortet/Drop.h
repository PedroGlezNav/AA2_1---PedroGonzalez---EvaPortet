#pragma once
#include "Includes.h"

class Drop {
public:
	enum Type { Unknown = 0, Lance = 1, Coin = 2, Potion = 3 };
	Type type = Unknown;
};