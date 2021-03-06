//
//  Explosion.cpp
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 ___UCMerced___. All rights reserved.
//

#include "Explosion.h"

#include "Game.h"
#include "City.h"
#include "HostileCity.h"

Explosion::Explosion(float x, float y, float z, int type): Actor(x,y,z,1,100){
    this->type = 0;
    size = .01;

}

void Explosion::draw(){
    float angle = M_PI/16;
    
    glPushMatrix();
    glTranslatef(x,y,z);
    if(type == 0) {
        
//        glColor3f(1,1,1);
//        glBegin(GL_QUADS);
//        glVertex3f( size, size,-size);    // Top Right Of The Quad (Top)
//        glVertex3f(-size, size,-size);    // Top Left Of The Quad (Top)
//        glVertex3f(-size, size, size);    // Bottom Left Of The Quad (Top)
//        glVertex3f( size, size, size);    // Bottom Right Of The Quad (Top)
//        glVertex3f( size,-size, size);    // Top Right Of The Quad (Bottom)
//        glVertex3f(-size,-size, size);    // Top Left Of The Quad (Bottom)
//        glVertex3f(-size,-size,-size);    // Bottom Left Of The Quad (Bottom)
//        glVertex3f( size,-size,-size);    // Bottom Right Of The Quad (Bottom)
//        glVertex3f( size, size, size);    // Top Right Of The Quad (Front)
//        glVertex3f(-size, size, size);    // Top Left Of The Quad (Front)
//        glVertex3f(-size,-size, size);    // Bottom Left Of The Quad (Front)
//        glVertex3f( size,-size, size);    // Bottom Right Of The Quad (Front)
//        glVertex3f( size,-size,-size);    // Top Right Of The Quad (Back)
//        glVertex3f(-size,-size,-size);    // Top Left Of The Quad (Back)
//        glVertex3f(-size, size,-size);    // Bottom Left Of The Quad (Back)
//        glVertex3f( size, size,-size);    // Bottom Right Of The Quad (Back)
//        glVertex3f(-size, size, size);    // Top Right Of The Quad (Left)
//        glVertex3f(-size, size,-size);    // Top Left Of The Quad (Left)
//        glVertex3f(-size,-size,-size);    // Bottom Left Of The Quad (Left)
//        glVertex3f(-size,-size, size);    // Bottom Right Of The Quad (Left)
//        glVertex3f( size, size,-size);    // Top Right Of The Quad (Right)
//        glVertex3f( size, size, size);    // Top Left Of The Quad (Right)
//        glVertex3f( size,-size, size);    // Bottom Left Of The Quad (Right)
//        glVertex3f( size,-size,-size);    // Bottom Right Of The Quad (Right)
//        glEnd();
        glColor3f(1, 1, 0);
        //glScaled(.01, .01, .01);
        
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

void Explosion::Update(){
    size+=.01;
    y+=.02;
    if(size > .5) {
        //kill any cities around me
        for(int i=0; i < theGame->logic.Actors.size();i++) {
            //check the type
         //   theGame->logic.Actors[i]->health = 0;
        }
        theGame->UnRegister(this);
    }
}