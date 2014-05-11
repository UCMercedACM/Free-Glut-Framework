//
//  Missile.cpp
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 ___UCMerced___. All rights reserved.
//

#include "Missile.h"

#include "Game.h"
#include "Explosion.h"

const float movement_speed = .1;

Missle::Missle(float x, float y, float z, int type): Actor(x,y,z,1,100){
    this->type = 0;
    //establish a movement vector
    

    
}

void Missle::draw(){
    glPushMatrix();
    glTranslatef(x,y-.05,z);
    if(type == 0) {
        
        glColor3f(1,1,1);
        float size = .05;
        glBegin(GL_QUADS);
        glColor3f(0.0f,1.0f,0.0f);    // Color Blue
        glVertex3f( size, size,-size);    // Top Right Of The Quad (Top)
        glVertex3f(-size, size,-size);    // Top Left Of The Quad (Top)
        glVertex3f(-size, size, size);    // Bottom Left Of The Quad (Top)
        glVertex3f( size, size, size);    // Bottom Right Of The Quad (Top)
        glColor3f(1.0f,0.5f,0.0f);    // Color Orange
        glVertex3f( size,-size, size);    // Top Right Of The Quad (Bottom)
        glVertex3f(-size,-size, size);    // Top Left Of The Quad (Bottom)
        glVertex3f(-size,-size,-size);    // Bottom Left Of The Quad (Bottom)
        glVertex3f( size,-size,-size);    // Bottom Right Of The Quad (Bottom)
        glColor3f(1.0f,0.0f,0.0f);    // Color Red
        glVertex3f( size, size, size);    // Top Right Of The Quad (Front)
        glVertex3f(-size, size, size);    // Top Left Of The Quad (Front)
        glVertex3f(-size,-size, size);    // Bottom Left Of The Quad (Front)
        glVertex3f( size,-size, size);    // Bottom Right Of The Quad (Front)
        glColor3f(1.0f,1.0f,0.0f);    // Color Yellow
        glVertex3f( size,-size,-size);    // Top Right Of The Quad (Back)
        glVertex3f(-size,-size,-size);    // Top Left Of The Quad (Back)
        glVertex3f(-size, size,-size);    // Bottom Left Of The Quad (Back)
        glVertex3f( size, size,-size);    // Bottom Right Of The Quad (Back)
        glColor3f(0.0f,0.0f,1.0f);    // Color Blue
        glVertex3f(-size, size, size);    // Top Right Of The Quad (Left)
        glVertex3f(-size, size,-size);    // Top Left Of The Quad (Left)
        glVertex3f(-size,-size,-size);    // Bottom Left Of The Quad (Left)
        glVertex3f(-size,-size, size);    // Bottom Right Of The Quad (Left)
        glColor3f(1.0f,0.0f,1.0f);    // Color Violet
        glVertex3f( size, size,-size);    // Top Right Of The Quad (Right)
        glVertex3f( size, size, size);    // Top Left Of The Quad (Right)
        glVertex3f( size,-size, size);    // Bottom Left Of The Quad (Right)
        glVertex3f( size,-size,-size);    // Bottom Right Of The Quad (Right)
        glEnd();
    }
    glPopMatrix();
}

void Missle::Update(){

    total_distance = sqrt(
                          pow(theGame->logic.player->x - x,2)
                          +pow(theGame->logic.player->y - y,2)
                          +pow(theGame->logic.player->z - z,2)
                          );
    
    delta_x = movement_speed * (theGame->logic.player->x - x)/total_distance;
    delta_y = movement_speed * (theGame->logic.player->y - y)/total_distance;
    delta_z = movement_speed * (theGame->logic.player->z - z)/total_distance;
    
    x+=delta_x;
    y+=delta_y;
    z+=movement_speed/2;
    
    if(z>theGame->logic.player->z) {
        Explosion * boom = new Explosion(x,y,z);
        theGame->UnRegister(this);
    }
}