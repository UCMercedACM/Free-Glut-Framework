//
//  GraphicsObject.h
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 ___UCMerced___. All rights reserved.
//

#ifndef __OOP_Game__GraphicsObject__
#define __OOP_Game__GraphicsObject__

#include <iostream>
#include "stdafx.h"
#include <string>

using namespace std;

class GraphicsObject {
    
private:
    float x, y, scale;
    GraphicsObject(){};
    
public:
    unsigned int uid;
    GraphicsObject(int x, int y, float scale);
    virtual void draw() = 0;
};

#endif /* defined(__OOP_Game__GraphicsObject__) */
