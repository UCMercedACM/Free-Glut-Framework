//
//  Engine.cpp
//  OOP_Game
//
//  Created by Deathstar on 5/7/14.
//  Copyright (c) 2014 ___UCMerced___. All rights reserved.
//

#include "Engine.h"


static Engine* Singleton;      // we make it statice so that this pointer is hidden from other source files

void Engine::initFreeglut(const char* label,int x, int y, int w, int h) {
    
    // First store this instance in our singleton pointer
    Singleton = this;
    
    // Set window position (from top corner), and size (width and height)
    glutInitWindowPosition ( x, y );
    glutInitWindowSize ( w, h );
    glutCreateWindow ( label );
    
    // Initialize OpenGL settings as we want
    glEnable ( GL_DEPTH_TEST );
    glEnable ( GL_POINT_SMOOTH );
    glEnable ( GL_LINE_SMOOTH );
    glHint ( GL_LINE_SMOOTH_HINT, GL_NICEST );
    glHint ( GL_POINT_SMOOTH_HINT, GL_NICEST );
    glPointSize ( 4 );
    glLineWidth ( 2 );
    
}

Engine::Engine() {
    
    initFreeglut("OOP Game", 300, 300, 640, 480);
    // Set up idle callback for background processing if needed:
    ::glutIdleFunc (glutIdleCB);
    
    // Set up GLUT callback function for resizing window:
    ::glutReshapeFunc (glutReshapeCB);
    
    // Set up GLUT callback for drawing the scene:
    ::glutDisplayFunc (glutDisplayCB);
    
    Singleton->run();
}

void Engine::glutIdleCB ()
{
    Singleton->update();
}

void Engine::glutReshapeCB ( int w, int h )
{
    Singleton->resize ( w, h );
}

void Engine::glutDisplayCB ()
{
    Singleton->draw();
}