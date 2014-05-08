//
//  Grid.h
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 ___UCMerced___. All rights reserved.
//

#ifndef __OOP_Game__Grid__
#define __OOP_Game__Grid__

#include <iostream>
#include "GraphicsObject.h"

class Grid : public GraphicsObject{
    int offset;
public:
    Grid(): GraphicsObject(0,0,1) {}
    virtual void draw();
};

#endif /* defined(__OOP_Game__Grid__) */
