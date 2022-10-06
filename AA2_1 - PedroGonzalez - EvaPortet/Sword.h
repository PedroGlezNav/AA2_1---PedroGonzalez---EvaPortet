#pragma once
#include "Weapon.h"

class Sword : public Weapon {
public:
    Sword() {
        damage = 1;
        range = 1;
    }
};