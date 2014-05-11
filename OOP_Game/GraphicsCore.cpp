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
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClearDepth(1.0f);                   // Set background depth to farthest
    glutSetCursor(GLUT_CURSOR_NONE);      // Hide the Cursor
    glHint ( GL_LINE_SMOOTH_HINT, GL_NICEST );
    glHint ( GL_POINT_SMOOTH_HINT, GL_NICEST );
    glPointSize ( 4 );
    glLineWidth ( 2 );
    
    int swap_interval = 1;
    CGLContextObj cgl_context = CGLGetCurrentContext();
    CGLSetParameter(cgl_context, kCGLCPSwapInterval, &swap_interval);
}

void Graphics::draw(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Clear the trasnformation stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //
    //glTranslatef(-.5, -0.5, -0.5);
    //glRotatef(20, 1, 0, 1);
    //glTranslatef(-5, -5, -5);
    //First three coordinates are the camera position
    //second three coordinates are the position of what you're looking at
    //final three is the up vector (should be normalized)
    gluLookAt(0, 3, 1, 0, 0, 0, 0, 0, 1);
    //render drawable objects
    for(int i = 0; i < drawable.size(); i++) {
        drawable[i]->draw();
    }
    //cout << "drawing" << endl;
    glPopMatrix();
    glutSwapBuffers();
}

void Graphics::resize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,(float)w/h, 1,1000);
    /*
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-0.1, 0.1, -float(h)/(10.0*float(w)), float(h)/(10.0*float(w)), 0.5, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    */
}

void Graphics::Register(GraphicsObject* newObject) {
    drawable.push_back(newObject);
}

void Graphics::UnRegister(unsigned int uid) {
    
    for(int i = 0; i < drawable.size(); i++) {
        if(drawable[i]->uid == uid) {
            delete drawable[i];
            drawable.erase(drawable.begin()+i);
        }
    }


}