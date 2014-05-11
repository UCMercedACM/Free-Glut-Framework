//
//  GameControl.cpp
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 Matthew Bucci. All rights reserved.
//

#include "GameControl.h"
#include "Game.h"
#include "Math.h"

//Object Types
#include "Player.h"
#include "Grid.h"
#include "City.h"


GameControl::GameControl() {
    intensity = .02;

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
    
    int chance = int(10/intensity);
    double rateofchange = .000000001;
    
    cout << chance << endl;
    if(rand()%chance == 0)
        theGame->logic.city = new City(double((rand()%10 - 2.5))/2.5, -10, -1.98);
    intensity+= rateofchange*pow(chance/20,3);
}