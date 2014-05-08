//
//  GraphicsCore.cpp
//  OOP_Game
//
//  Created by Deathstar on 5/7/14.
//  Copyright (c) 2014 ___UCMerced___. All rights reserved.
//

#include "GraphicsCore.h"


Graphics::Graphics() {
    
    // Set window position (from top corner), and size (width and height)
    glutInitWindowPosition ( WINDOW_START_X, WINDOW_START_Y );
    glutInitWindowSize ( WINDOW_WIDTH,  WINDOW_HEIGHT );
    glutCreateWindow ( GAME_TITLE );
    
    // Initialize OpenGL settings as we want
    glEnable ( GL_DEPTH_TEST );
    glEnable ( GL_POINT_SMOOTH );
    glEnable ( GL_LINE_SMOOTH );
    glHint ( GL_LINE_SMOOTH_HINT, GL_NICEST );
    glHint ( GL_POINT_SMOOTH_HINT, GL_NICEST );
    glPointSize ( 4 );
    glLineWidth ( 2 );
    
}

void Graphics::draw(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    //glPushMatrix();
    
    //render drawable objects
    for(int i = 0; i < drawable.size(); i++) {
        drawable[i]->draw();
    }
    
    //glPopMatrix();
    glutSwapBuffers();
}

void Graphics::resize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-0.1, 0.1, -float(h)/(10.0*float(w)), float(h)/(10.0*float(w)), 0.5, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

