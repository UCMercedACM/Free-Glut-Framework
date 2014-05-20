//
//  Game.cpp
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 Matthew Bucci. All rights reserved.
//

# include <iostream>
# include "Game.h"
# include "Grid.h"

Game::Game() {
 
}

void Game::setup() {
    theGame->logic.player = new Player();
    Grid * surface = new Grid();
}


void Game::resize ( int w, int h )
{
     renderer.resize(w,h);
}

// here we will redraw the scene according to the current state of the application.
void Game::draw ()
{
     renderer.draw();
}

void Game::update() {
    logic.Update();
}


