//
//  HostileCity.h
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 ___UCMerced___. All rights reserved.
//

#ifndef __OOP_Game__HostileCity__
#define __OOP_Game__HostileCity__

#include <iostream>
#include "Actor.h"

class HostileCity : public Actor {
    int type = 0;
public:
    HostileCity(float x, float y, float z, int type = 0);
    virtual void draw();
    virtual void Update();
};

#endif /* defined(__OOP_Game__HostileCity__) */
