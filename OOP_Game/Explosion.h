//
//  Explosion.h
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 ___UCMerced___. All rights reserved.
//

#ifndef __OOP_Game__Explosion__
#define __OOP_Game__Explosion__

#include <iostream>
#include "Actor.h"

class Explosion : Actor{
    int type;
    float size;
    Explosion(): Actor(0,0,0,1,100){}
public:
    Explosion(float x, float y, float z, int type = 0);
    virtual void draw();
    virtual void Update();
};

#endif /* defined(__OOP_Game__Explosion__) */
