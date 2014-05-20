//
//  Missile.h
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 ___UCMerced___. All rights reserved.
//

#ifndef __OOP_Game__Missile__
#define __OOP_Game__Missile__

#include <iostream>
#include "Actor.h"

class Missle : Actor{
    int type;
    Missle(): Actor(0,0,0,1,100){}
    
    //movement
    float delta_x;
    float delta_y;
    float delta_z;
    
    double total_distance;
    
public:
    Missle(float x, float y, float z, int type = 0);
    virtual void draw();
    virtual void Update();
};

#endif /* defined(__OOP_Game__Missile__) */
