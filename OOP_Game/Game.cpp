//
//  Game.cpp
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 Matthew Bucci. All rights reserved.
//

# include <iostream>
# include "Game.h"


Game::Game() {
    Singleton->run();
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
   // Define that OpenGL should use the whole window for rendering
     glViewport(0, 0, w, h);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glFrustum(-0.1, 0.1, -float(h)/(10.0*float(w)), float(h)/(10.0*float(w)), 0.5, 1000.0);
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
   _w=w; _h=h;
 }

// here we will redraw the scene according to the current state of the application.
void Game::draw ()
 {
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glLoadIdentity();
     
     glBegin(GL_TRIANGLES);
     glVertex3f(0.0, 0.0, -10.0);
     glVertex3f(1.0, 0.0, -10.0);
     glVertex3f(0.0, 1.0, -10.0);
     glEnd();
     
     glutSwapBuffers();
}

void Game::update() {
    
    
}
