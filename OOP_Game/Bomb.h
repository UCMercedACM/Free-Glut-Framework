//
//  Bomb.h
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 ___UCMerced___. All rights reserved.
//

#ifndef __OOP_Game__Bomb__
#define __OOP_Game__Bomb__

#include <iostream>
#include "Actor.h"

class Bomb : Actor{
    int type;
    Bomb(): Actor(0,0,0,1,100){}
public:
    Bomb(float x, float y, float z, int type = 0);
    virtual void draw();
    virtual void Update();
};

#endif /* defined(__OOP_Game__Bomb__) */
