//
//  aiming.h
//  OOP_Game
//
//  Created by Matthew Bucci on 5/11/14.
//  Copyright (c) 2014 ___UCMerced___. All rights reserved.
//

#ifndef __OOP_Game__aiming__
#define __OOP_Game__aiming__

#include <iostream>
#include "GraphicsObject.h"

class Aiming : public GraphicsObject{
    int offset;
public:
    Aiming(): GraphicsObject(0,0,0,1) {}
    virtual void draw();
};

#endif /* defined(__OOP_Game__aiming__) */
