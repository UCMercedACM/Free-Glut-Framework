//
//  Bomb.cpp
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 ___UCMerced___. All rights reserved.
//

#include "Bomb.h"
#include "Game.h"
#include "Explosion.h"

Bomb::Bomb(float x, float y, float z, int type): Actor(x,y,z,1,100){
    this->type = 0;
}

void Bomb::draw(){
    glPushMatrix();
    glTranslatef(x,y-.05,z);
    if(type == 0) {

        glColor3f(1,.5,0);
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

void Bomb::Update(){
    z-=.02;
    y-=.03;
    
    
    if(z<-2) {
        Explosion * boom = new Explosion(x,y,z);
        for(int i = 0; i < theGame->logic.Actors.size(); i++) {
            double total_distance = sqrt(
                                  pow(theGame->logic.Actors[i]->x - x,2)
                                  +pow(theGame->logic.Actors[i]->y - y,2)
                                  +pow(theGame->logic.Actors[i]->z - z,2)
                                  );
            if(total_distance < .5)
                theGame->logic.Actors[i]->die();
        }
        theGame->UnRegister(this);
    }
}