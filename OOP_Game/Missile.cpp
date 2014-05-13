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
    
    total_distance = sqrt(
                          pow(theGame->logic.player->x - x,2)
                          +pow(theGame->logic.player->y - y,2)
                          +pow(theGame->logic.player->z - z,2)
                          );
    
    delta_x = movement_speed * (theGame->logic.player->x - x)/total_distance;
    delta_y = movement_speed * (theGame->logic.player->y - y)/total_distance;
    delta_z = movement_speed * (theGame->logic.player->z - z)/total_distance;
    
    
}

void Missle::draw(){
    glPushMatrix();
    glTranslatef(x,y-.05,z);
    if(type == 0) {
        
        //glColor3f(1,1,1);
        glColor3f( 0.65 , 0.50 , 0.39);        //mediumwood
        float size = .05;
        float angle = M_PI/16;
//        glBegin(GL_QUADS);
//        glColor3f(0.0f,1.0f,0.0f);    // Color Blue
//        glVertex3f( size, size,-size);    // Top Right Of The Quad (Top)
//        glVertex3f(-size, size,-size);    // Top Left Of The Quad (Top)
//        glVertex3f(-size, size, size);    // Bottom Left Of The Quad (Top)
//        glVertex3f( size, size, size);    // Bottom Right Of The Quad (Top)
//        glColor3f(1.0f,0.5f,0.0f);    // Color Orange
//        glVertex3f( size,-size, size);    // Top Right Of The Quad (Bottom)
//        glVertex3f(-size,-size, size);    // Top Left Of The Quad (Bottom)
//        glVertex3f(-size,-size,-size);    // Bottom Left Of The Quad (Bottom)
//        glVertex3f( size,-size,-size);    // Bottom Right Of The Quad (Bottom)
//        glColor3f(1.0f,0.0f,0.0f);    // Color Red
//        glVertex3f( size, size, size);    // Top Right Of The Quad (Front)
//        glVertex3f(-size, size, size);    // Top Left Of The Quad (Front)
//        glVertex3f(-size,-size, size);    // Bottom Left Of The Quad (Front)
//        glVertex3f( size,-size, size);    // Bottom Right Of The Quad (Front)
//        glColor3f(1.0f,1.0f,0.0f);    // Color Yellow
//        glVertex3f( size,-size,-size);    // Top Right Of The Quad (Back)
//        glVertex3f(-size,-size,-size);    // Top Left Of The Quad (Back)
//        glVertex3f(-size, size,-size);    // Bottom Left Of The Quad (Back)
//        glVertex3f( size, size,-size);    // Bottom Right Of The Quad (Back)
//        glColor3f(0.0f,0.0f,1.0f);    // Color Blue
//        glVertex3f(-size, size, size);    // Top Right Of The Quad (Left)
//        glVertex3f(-size, size,-size);    // Top Left Of The Quad (Left)
//        glVertex3f(-size,-size,-size);    // Bottom Left Of The Quad (Left)
//        glVertex3f(-size,-size, size);    // Bottom Right Of The Quad (Left)
//        glColor3f(1.0f,0.0f,1.0f);    // Color Violet
//        glVertex3f( size, size,-size);    // Top Right Of The Quad (Right)
//        glVertex3f( size, size, size);    // Top Left Of The Quad (Right)
//        glVertex3f( size,-size, size);    // Bottom Left Of The Quad (Right)
//        glVertex3f( size,-size,-size);    // Bottom Right Of The Quad (Right)
//        glEnd();
        
        glBegin(GL_TRIANGLES);
        for (float phi=(-M_PI/2); phi < M_PI; phi+=angle )
        {
            for(float theta = 0.0; theta<(2*M_PI); theta+=angle)
            {
                glVertex3f(size*cos(theta)*sin(phi),size*sin(theta)*sin(phi), size*cos(phi));
                glVertex3f(size*cos(theta)*sin(phi+angle), size*sin(theta)*sin(phi+angle), size*cos(phi+angle));
                glVertex3f(size*cos(theta+angle)*sin(phi), size*sin(theta+angle)*sin(phi), size*cos(phi));
                
                glVertex3f(size*cos(theta+angle)*sin(phi+angle), size*sin(theta+angle)*sin(phi+angle), size*cos(phi+angle));
                glVertex3f(size*cos(theta)*sin(phi+angle), size*sin(theta)*sin(phi+angle), size*cos(phi+angle));
                glVertex3f(size*cos(theta+angle)*sin(phi), size*sin(theta+angle)*sin(phi), size*cos(phi));
            }
        }
        
        glEnd();
        
    }
    glPopMatrix();
}

void Missle::Update(){


    x+=delta_x;
    y+=delta_y;
    z+=movement_speed/2;
    
    total_distance = sqrt(
                          pow(theGame->logic.player->x - x,2)
                          +pow(theGame->logic.player->y - y,2)
                          +pow(theGame->logic.player->z - z,2)
                          );

    if(total_distance < 1 || z > 50) {
        Explosion * boom = new Explosion(theGame->logic.player->x,theGame->logic.player->y,theGame->logic.player->z);
        theGame->UnRegister(this);
    }
}