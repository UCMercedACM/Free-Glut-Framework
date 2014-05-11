//
//  Explosion.cpp
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 ___UCMerced___. All rights reserved.
//

#include "Explosion.h"

#include "Game.h"

Explosion::Explosion(float x, float y, float z, int type): Actor(x,y,z,1,100){
    this->type = 0;
    size = .01;
}

void Explosion::draw(){
    glPushMatrix();
    glTranslatef(x,y-.05,z);
    if(type == 0) {
        
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex3f( size, size,-size);    // Top Right Of The Quad (Top)
        glVertex3f(-size, size,-size);    // Top Left Of The Quad (Top)
        glVertex3f(-size, size, size);    // Bottom Left Of The Quad (Top)
        glVertex3f( size, size, size);    // Bottom Right Of The Quad (Top)
        glVertex3f( size,-size, size);    // Top Right Of The Quad (Bottom)
        glVertex3f(-size,-size, size);    // Top Left Of The Quad (Bottom)
        glVertex3f(-size,-size,-size);    // Bottom Left Of The Quad (Bottom)
        glVertex3f( size,-size,-size);    // Bottom Right Of The Quad (Bottom)
        glVertex3f( size, size, size);    // Top Right Of The Quad (Front)
        glVertex3f(-size, size, size);    // Top Left Of The Quad (Front)
        glVertex3f(-size,-size, size);    // Bottom Left Of The Quad (Front)
        glVertex3f( size,-size, size);    // Bottom Right Of The Quad (Front)
        glVertex3f( size,-size,-size);    // Top Right Of The Quad (Back)
        glVertex3f(-size,-size,-size);    // Top Left Of The Quad (Back)
        glVertex3f(-size, size,-size);    // Bottom Left Of The Quad (Back)
        glVertex3f( size, size,-size);    // Bottom Right Of The Quad (Back)
        glVertex3f(-size, size, size);    // Top Right Of The Quad (Left)
        glVertex3f(-size, size,-size);    // Top Left Of The Quad (Left)
        glVertex3f(-size,-size,-size);    // Bottom Left Of The Quad (Left)
        glVertex3f(-size,-size, size);    // Bottom Right Of The Quad (Left)
        glVertex3f( size, size,-size);    // Top Right Of The Quad (Right)
        glVertex3f( size, size, size);    // Top Left Of The Quad (Right)
        glVertex3f( size,-size, size);    // Bottom Left Of The Quad (Right)
        glVertex3f( size,-size,-size);    // Bottom Right Of The Quad (Right)
        glEnd();
    }
    glPopMatrix();
}

void Explosion::Update(){
    size+=.005;
    y+=.02;
    if(size > .5) {
        theGame->UnRegister(this);
    }
}