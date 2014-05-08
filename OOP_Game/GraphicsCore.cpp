//
//  GraphicsCore.cpp
//  OOP_Game
//
//  Created by Deathstar on 5/7/14.
//  Copyright (c) 2014 ___UCMerced___. All rights reserved.
//

#include "GraphicsCore.h"
static vector<GraphicsObject*> drawable;

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
    glHint ( GL_LINE_SMOOTH_HINT, GL_NICEST );
    glHint ( GL_POINT_SMOOTH_HINT, GL_NICEST );
    glPointSize ( 4 );
    glLineWidth ( 2 );
}

void Graphics::draw(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Clear the trasnformation stack
    //glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glPushMatrix();
    //
    //glTranslatef(-.5, -0.5, -0.5);
    //glRotatef(20, 1, 0, 1);
    //glTranslatef(-5, -5, -5);
    
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

void Graphics::UnRegister(GraphicsObject* newObject) {
    
    for(int i = 0; i < drawable.size(); i++) {
        if(drawable[i]->uid == newObject->uid)
            drawable.erase(drawable.begin()+i);
    }


}