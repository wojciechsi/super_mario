//
// Created by wojciech on 21.03.2022.
//

#ifndef SUPER_MARIO_MOVINGITEM_H
#define SUPER_MARIO_MOVINGITEM_H

#include "Object.h"

class MovingItem : virtual public Object{
public:
    MovingItem(int, int);
private:
    int vertitalSpeed, horizontalSpeed;
};


#endif //SUPER_MARIO_MOVINGITEM_H
