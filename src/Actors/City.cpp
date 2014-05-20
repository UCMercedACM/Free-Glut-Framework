//
//  City.cpp
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 ___UCMerced___. All rights reserved.
//

#include "City.h"

#include "Game.h"


City::City(float x, float y, float z, int type): Actor(x,y,z,1,100){
    this->type = type;
}


void City::draw() {
    
    if(type == 0 ) {
        glPushMatrix();
        glTranslatef(0, 0, .2);
        glTranslatef(x, y, z);
        
        //glColor3f(1, 1, 0);
        glColor3f(0.91, 0.76, 0.65);
        glScaled(.2,.2,.2);
        
        //glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f( SIZE, SIZE, -SIZE*2);    // Top Right Of The Quad (Top)
        glVertex3f(-SIZE, SIZE, -SIZE*2);    // Top Left Of The Quad (Top)
        glVertex3f(-SIZE, SIZE, -SIZE);    // Bottom Left Of The Quad (Top)
        glVertex3f( SIZE, SIZE, -SIZE);    // Bottom Right Of The Quad (Top)
        glEnd();
        
        glBegin(GL_QUADS);
        glVertex3f( SIZE,-SIZE, -SIZE);    // Top Right Of The Quad (Bottom)
        glVertex3f(-SIZE,-SIZE, -SIZE);    // Top Left Of The Quad (Bottom)
        glVertex3f(-SIZE,-SIZE,-SIZE*2);    // Bottom Left Of The Quad (Bottom)
        glVertex3f( SIZE,-SIZE,-SIZE*2);    // Bottom Right Of The Quad (Bottom)
        glEnd();

        glColor3f(0.91, 0.76, 0.65);
        glBegin(GL_QUADS);
        glVertex3f( SIZE, SIZE, -SIZE);    // Top Right Of The Quad (Front)
        glVertex3f(-SIZE, SIZE, -SIZE);    // Top Left Of The Quad (Front)
        glVertex3f(-SIZE,-SIZE, -SIZE);    // Bottom Left Of The Quad (Front)
        glVertex3f( SIZE,-SIZE, -SIZE);    // Bottom Right Of The Quad (Front)
        glEnd();

        glBegin(GL_QUADS);
        glVertex3f( SIZE,-SIZE,-SIZE*2);    // Top Right Of The Quad (Back)
        glVertex3f(-SIZE,-SIZE,-SIZE*2);    // Top Left Of The Quad (Back)
        glVertex3f(-SIZE, SIZE,-SIZE*2);    // Bottom Left Of The Quad (Back)
        glVertex3f( SIZE, SIZE,-SIZE*2);    // Bottom Right Of The Quad (Back)
        glEnd();

        glBegin(GL_QUADS);
        glVertex3f(-SIZE, SIZE, -SIZE);    // Top Right Of The Quad (Left)
        glVertex3f(-SIZE, SIZE,-SIZE*2);    // Top Left Of The Quad (Left)
        glVertex3f(-SIZE,-SIZE,-SIZE*2);    // Bottom Left Of The Quad (Left)
        glVertex3f(-SIZE,-SIZE, -SIZE);    // Bottom Right Of The Quad (Left)
        glEnd();

        glBegin(GL_QUADS);
        glVertex3f( SIZE, SIZE,-SIZE*2);    // Top Right Of The Quad (Right)
        glVertex3f( SIZE, SIZE, -SIZE);    // Top Left Of The Quad (Right)
        glVertex3f( SIZE,-SIZE, -SIZE);    // Bottom Left Of The Quad (Right)
        glVertex3f( SIZE,-SIZE,-SIZE*2);    // Bottom Right Of The Quad (Right)
        glEnd();
        
        //
        //sub houses
        glColor3f(0.91, 0.76, 0.65);          //lightwood
        glBegin(GL_QUADS);
        glVertex3f( SIZE*3, -SIZE*2, -SIZE*1.5);    // Top Right Of The Quad (Bottom)
        glVertex3f( SIZE*2, -SIZE*2, -SIZE*1.5);    // Top Left Of The Quad (Bottom)
        glVertex3f( SIZE*2, -SIZE*2,-SIZE*2);    // Bottom Left Of The Quad (Bottom)
        glVertex3f( SIZE*3, -SIZE*2,-SIZE*2);    // Bottom Right Of The Quad (Bottom)
        glEnd();
        
        glBegin(GL_QUADS);
        glVertex3f( SIZE*3, -SIZE*3, -SIZE*1.5);    // Top Right Of The Quad (Front)
        glVertex3f(SIZE*2, -SIZE*3, -SIZE*1.5);    // Top Left Of The Quad (Front)
        glVertex3f(SIZE*2,-SIZE*2, -SIZE*1.5);    // Bottom Left Of The Quad (Front)
        glVertex3f( SIZE*3,-SIZE*2, -SIZE*1.5);    // Bottom Right Of The Quad (Front)
        glEnd();
        
        glBegin(GL_QUADS);
        glVertex3f( SIZE*3,-SIZE*2,-SIZE*2);    // Top Right Of The Quad (Back)
        glVertex3f(SIZE*2,-SIZE*2,-SIZE*2);    // Top Left Of The Quad (Back)
        glVertex3f(SIZE*2, -SIZE*3,-SIZE*2);    // Bottom Left Of The Quad (Back)
        glVertex3f( SIZE*3, -SIZE*3,-SIZE*2);    // Bottom Right Of The Quad (Back)
        glEnd();
        
        glBegin(GL_QUADS);
        glVertex3f(SIZE*2, -SIZE*3, -SIZE*1.5);    // Top Right Of The Quad (Left)
        glVertex3f(SIZE*2, -SIZE*3,-SIZE*2);    // Top Left Of The Quad (Left)
        glVertex3f(SIZE*2,-SIZE*2,-SIZE*2);    // Bottom Left Of The Quad (Left)
        glVertex3f(SIZE*2,-SIZE*2, -SIZE*1.5);    // Bottom Right Of The Quad (Left)
        glEnd();
        
        glBegin(GL_QUADS);
        glVertex3f( SIZE*3, -SIZE*3,-SIZE*2);    // Top Right Of The Quad (Right)
        glVertex3f( SIZE*3, -SIZE*3, -SIZE*1.5);    // Top Left Of The Quad (Right)
        glVertex3f( SIZE*3,-SIZE*2, -SIZE*1.5);    // Bottom Left Of The Quad (Right)
        glVertex3f( SIZE*3,-SIZE*2,-SIZE*2);    // Bottom Right Of The Quad (Right)
        glEnd();
        
        //subhouse2
        glBegin(GL_QUADS);
        glVertex3f( -SIZE*3, -SIZE*2, -SIZE*1.5);    // Top Right Of The Quad (Bottom)
        glVertex3f( -SIZE*2, -SIZE*2, -SIZE*1.5);    // Top Left Of The Quad (Bottom)
        glVertex3f( -SIZE*2, -SIZE*2,-SIZE*2);    // Bottom Left Of The Quad (Bottom)
        glVertex3f( -SIZE*3, -SIZE*2,-SIZE*2);    // Bottom Right Of The Quad (Bottom)
        glEnd();
        
        glBegin(GL_QUADS);
        glVertex3f( -SIZE*3, -SIZE*3, -SIZE*1.5);    // Top Right Of The Quad (Front)
        glVertex3f(-SIZE*2, -SIZE*3, -SIZE*1.5);    // Top Left Of The Quad (Front)
        glVertex3f(-SIZE*2,-SIZE*2, -SIZE*1.5);    // Bottom Left Of The Quad (Front)
        glVertex3f( -SIZE*3,-SIZE*2, -SIZE*1.5);    // Bottom Right Of The Quad (Front)
        glEnd();
        
        glBegin(GL_QUADS);
        glVertex3f( -SIZE*3,-SIZE*2,-SIZE*2);    // Top Right Of The Quad (Back)
        glVertex3f(-SIZE*2,-SIZE*2,-SIZE*2);    // Top Left Of The Quad (Back)
        glVertex3f(-SIZE*2, -SIZE*3,-SIZE*2);    // Bottom Left Of The Quad (Back)
        glVertex3f( -SIZE*3, -SIZE*3,-SIZE*2);    // Bottom Right Of The Quad (Back)
        glEnd();
        
        glBegin(GL_QUADS);
        glVertex3f(-SIZE*2, -SIZE*3, -SIZE*1.5);    // Top Right Of The Quad (Left)
        glVertex3f(-SIZE*2, -SIZE*3,-SIZE*2);    // Top Left Of The Quad (Left)
        glVertex3f(-SIZE*2,-SIZE*2,-SIZE*2);    // Bottom Left Of The Quad (Left)
        glVertex3f(-SIZE*2,-SIZE*2, -SIZE*1.5);    // Bottom Right Of The Quad (Left)
        glEnd();
        
        glBegin(GL_QUADS);
        glVertex3f( -SIZE*3, -SIZE*3,-SIZE*2);    // Top Right Of The Quad (Right)
        glVertex3f( -SIZE*3, -SIZE*3, -SIZE*1.5);    // Top Left Of The Quad (Right)
        glVertex3f( -SIZE*3,-SIZE*2, -SIZE*1.5);    // Bottom Left Of The Quad (Right)
        glVertex3f( -SIZE*3,-SIZE*2,-SIZE*2);    // Bottom Right Of The Quad (Right)
        glEnd();
        
        glPopMatrix();
    }
}


void City::Update() {
    y+=.02;
    if (y>0.7) {
        theGame->UnRegister(this);
    }
    
}

void City::die() {
    theGame->logic.intensity+=.1;
    theGame->logic.friendlies_killed+=25;
    theGame->UnRegister(this);
}