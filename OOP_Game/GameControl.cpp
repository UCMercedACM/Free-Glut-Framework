//
//  GameControl.cpp
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 Matthew Bucci. All rights reserved.
//

#include "GameControl.h"
#include "Engine.h"

//Object Types
#include "Player.h"
#include "Grid.h"


GameControl::GameControl() {


}

void GameControl::Register(Actor* newActor) {
    Actors.push_back(newActor);
}

void GameControl::UnRegister(unsigned int uid) {
    for(int i = 0; i < Actors.size(); i++) {
        if(Actors[i]->uid == uid) {
            //graphics core will handle freeing memory
            Actors.erase(Actors.begin()+i);
        }
    }
}


void GameControl::Update() {
    for(int i = 0; i < Actors.size(); i++) {
        Actors[i]->Update();
    }
}