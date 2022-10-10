#pragma once
#include "Weapon.h"

class Lance : public Weapon {
public:
    Lance() {
        damage = 1;
        range = 2;
        name = "Lance";
    }
};