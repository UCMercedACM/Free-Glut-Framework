//
//  Actor.cpp
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 ___UCMerced___. All rights reserved.
//

#include "Actor.h"
#include "Game.h"

Actor::Actor(float x, float y,float z, float scale, int health)
: GraphicsObject(x,y,z,scale) {
    this->health = health;
    theGame->logic.Register(this);
}

void Actor::Update(){
    if(isfiring==true) {
        cout << "BOOM";
        isfiring = false;
    }
}

void Actor::die() {
    
    
}