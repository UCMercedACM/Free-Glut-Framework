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

// mouse events are in window coordinates, but your scene is in [0,1]x[0,1],
// so make here the conversion when needed
void Game::windowToScene ( float& x, float &y )
 {
   x = (2.0f*(x/float(_w))) - 1.0f;
   y = 1.0f - (2.0f*(y/float(_h)));
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
}


