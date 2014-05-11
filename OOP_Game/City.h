//
//  City.h
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 ___UCMerced___. All rights reserved.
//

#ifndef __OOP_Game__City__
#define __OOP_Game__City__

#include <iostream>
#include "Actor.h"

class City : public Actor {

public:
    City();
    virtual void draw();
    virtual void Update();
};

#endif /* defined(__OOP_Game__City__) */
