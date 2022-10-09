#pragma once
#include "Character.h"
#include "Weapon.h"
#include "Drop.h"

class Enemy : public Character {
public:
	Drop drop;

	Enemy() : Character() {
		drop.type = Drop::Type::Unknown;
	}

	void Attack() override {

	}

	void Die() override {

	}

	void Damage() override {

	}
};