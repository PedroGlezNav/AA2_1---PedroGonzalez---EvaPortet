#pragma once
#pragma once
#include "Includes.h"

#include "Map.h"
#include "Portal.h"

class InexistingMap :public Map {
public:
	InexistingMap() {
		name = "Inexisting Map";
	}
};