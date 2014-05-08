//
//  GameControl.cpp
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 Matthew Bucci. All rights reserved.
//

#include "GameControl.h"

GameControl::GameControl() {
    
    //Create The Player
    Player * player = new Player;
    
    Actors.push_back(player);
    
}