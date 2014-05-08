//
//  Actor.cpp
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 ___UCMerced___. All rights reserved.
//

#include "Actor.h"

Actor::Actor(float x, float y, float scale, int health)
: GraphicsObject(x,y,scale) {
    this->health = health;
}