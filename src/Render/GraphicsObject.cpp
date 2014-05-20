//
//  GraphicsObject.cpp
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 ___UCMerced___. All rights reserved.
//

#include "GraphicsObject.h"
#include "Game.h"

//Object Types
void RenderGrid();
void RenderShip();
void RenderCity();

GraphicsObject::GraphicsObject(float x, float y, float z, float scale) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->scale = scale;
    theGame->Register(this);
}