//
//  GameControl.cpp
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 Matthew Bucci. All rights reserved.
//

#include "GameControl.h"
#include "Game.h"


//Object Types
#include "Player.h"
#include "Grid.h"
#include "City.h"
#include "HostileCity.h"

GameControl::GameControl() {
    intensity = .02;
    current_level = 0;
    enemies_killed = 0;
    friendlies_killed = 0;
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
    
    if (intensity > .9) intensity = .9;
    if (intensity < .05) intensity = .05;
    cout << intensity << endl;
    int chance = int(10/intensity);
    
    //in the future these should depend on level condition
    double rateofchange = .000000001;
    float hostiletofriendly = 3;
    int leveltarget = 200;
    
    //hostile cities
    if(rand()%int((1-intensity)*300) == 0)
        HostileCity * newhostile = new HostileCity(double((rand()%10 - 5))/2.5, -10, -1.98);
    
    //friendly cities
    if(rand()%int((intensity)*300) == 0)
        City * newcity = new City(double((rand()%10 - 5))/2.5, -10, -1.98);
    
    intensity+= rateofchange*pow(chance/20,3);
    
    float levelprogress = 1 - double(-(leveltarget - chance)) / 300 ;
    //cout << "Level Progress:" << double(-(200 - chance)) / 300 << endl;
    
    

}