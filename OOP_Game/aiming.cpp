//
//  aiming.cpp
//  OOP_Game
//
//  Created by Matthew Bucci on 5/11/14.
//  Copyright (c) 2014 ___UCMerced___. All rights reserved.
//

#include "aiming.h"
#include "Game.h"
#include <math.h>

void Aiming::draw() {
    glPushMatrix();
    glTranslatef(theGame->logic.player->x, theGame->logic.player->z-5, -1.98);
    glColor3f(1,0,0);
    
    /*
    glBegin(GL_LINE_LOOP);
    for(int i =0; i <= 300; i++){
        float r = .5;
        float x1 = r* cos(2 * 3.14159 * i / 300);
        float y1 = r* sin(2 * 3.14159 * i / 300);
        
        glVertex3f(x1,y1,0);
    }
    glEnd();
    */
    
    glRotated(45,0,0,1);
    
    glBegin(GL_LINES);
    glVertex3f(-SIZE / 2, 0, 0);
    glVertex3f( SIZE / 2, 0, 0);
    glVertex3f(0, -SIZE / 2, 0);
    glVertex3f(0, SIZE / 2, 0);
    glEnd();
    glPopMatrix();
}