#pragma once
#include "Character.h"
#include "Weapon.h"
#include "Drop.h"

class Enemy : public Character {
public:
	Drop::Type drop;

	Enemy() : Character() {
		drop = Drop::Type::Unknown;
		icon = 'E';
	}

	void Attack() override {

	}

	void Die() override {

	}
};