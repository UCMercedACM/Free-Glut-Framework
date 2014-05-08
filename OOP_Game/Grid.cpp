//
//  Grid.cpp
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 ___UCMerced___. All rights reserved.
//

#include "Grid.h"

void Grid::draw() {

    glRotatef(65,1.0f,0.0f,0.0f);
    glTranslatef(0, 1, 0);
    glBegin(GL_QUADS);
    glVertex3f(-SIZE / 2, -SIZE / 2, 0);
    glVertex3f( SIZE / 2, -SIZE / 2, 0);
    glVertex3f( SIZE / 2,  SIZE / 2, 0);
    glVertex3f(-SIZE / 2,  SIZE / 2, 0);
    glEnd();

    /*
    //draw the vertical lines
    glBegin(GL_LINES);
    glVertex3f(-1.5, -2.0, -10.0);
    glVertex3f(-1.5, 2.0, -10.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(-1.0, -2.0, -10.0);
    glVertex3f(-1.0, 2.0, -10.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(-0.5, -2.0, -10.0);
    glVertex3f(-0.5, 2.0, -10.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(0.0, -2.0, -10.0);
    glVertex3f(0.0, 2.0, -10.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(0.5, -2.0, -10.0);
    glVertex3f(0.5, 2.0, -10.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(1.0, -2.0, -10.0);
    glVertex3f(1.0, 2.0, -10.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(1.5, -2.0, -10.0);
    glVertex3f(1.5, 2.0, -10.0);
    glEnd();
    
    //draw the horizontal lines
    glBegin(GL_LINES);
    glVertex3f(-2.0,-1.5, -10.0);
    glVertex3f(2.0, -1.5, -10.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(-2.0, -1.0, -10.0);
    glVertex3f(2.0, -1.0, -10.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(-2.0,-0.5, -10.0);
    glVertex3f( 2.0,-0.5, -10.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(-2.0,0.0, -10.0);
    glVertex3f(2.0, 0.0, -10.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(0.5, -2.0, -10.0);
    glVertex3f(0.5, 2.0, -10.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(1.0, -2.0, -10.0);
    glVertex3f(1.0, 2.0, -10.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(1.5, -2.0, -10.0);
    glVertex3f(1.5, 2.0, -10.0);
    glEnd();
    */
}