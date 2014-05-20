//
//  Player.h
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 Matthew Bucci. All rights reserved.
//

#ifndef __OOP_Game__Player__
#define __OOP_Game__Player__

#include <iostream>
#include "Actor.h"

class Player : public Actor {
    float pos_delta;
    GraphicsObject * reticle;
public:
    Player();
    virtual void draw();
    virtual void Update();
};
#endif /* defined(__OOP_Game__Player__) */
