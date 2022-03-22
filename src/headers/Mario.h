//
// Created by wojciech on 21.03.2022.
//

#ifndef SUPER_MARIO_MARIO_H
#define SUPER_MARIO_MARIO_H

#include "defs.h"
#include "MovingItem.h"

class Mario : virtual public MovingItem{
public:
    Mario();

private:
    bool isBig = false;
};


#endif //SUPER_MARIO_MARIO_H
