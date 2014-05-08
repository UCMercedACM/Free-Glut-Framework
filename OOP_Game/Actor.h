//
//  Actor.h
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 ___UCMerced___. All rights reserved.
//

#ifndef __OOP_Game__Actor__
#define __OOP_Game__Actor__

#include <iostream>
#include "GraphicsCore.h"
#include "stdafx.h"

class Actor : public GraphicsObject {
private:
    int health;
    Actor() : GraphicsObject(0,0,0){};
public:
    Actor(float x, float y, float scale, int health);
    virtual void draw() = 0;
};
#endif /* defined(__OOP_Game__Actor__) */
