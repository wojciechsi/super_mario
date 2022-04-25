//
// Created by wojciech on 21.03.2022.
//

#include "headers/Gumba.h"

Gumba::Gumba() : Enemy(0, 0) {
    velocity = -0.8;
}

Gumba::Gumba(int iX, int iY) : Gumba() {
    move(iX, iY);
}