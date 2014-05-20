//
//  GameControl.h
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 Matthew Bucci. All rights reserved.
//

#ifndef __OOP_Game__GameControl__
#define __OOP_Game__GameControl__

#include <iostream>
#include "stdafx.h"
#include "Actor.h"
#include "Player.h"
#include "City.h"

class GameControl {
public:
    double intensity;
    int current_level;
    int enemies_killed;
    int friendlies_killed;
    vector<Actor*> Actors;
    Player* player;
    GameControl();
    void Register(Actor* newActor);
    void UnRegister(unsigned int uid);
    void Update();
};
#endif /* defined(__OOP_Game__GameControl__) */
