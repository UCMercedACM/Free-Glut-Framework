//
//  Grid.cpp
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 ___UCMerced___. All rights reserved.
//

#include "Grid.h"

const int speed = 50;

void Grid::draw() {
    
    
    //glRotatef(65,1.0f,0.0f,0.0f);
    
    //Because I can't find SIZE
    /*
    glScalef(10,10,10);
    glColor3f(0, 1, 0);
    glBegin(GL_QUADS);
    glVertex3f(-SIZE / 2, -SIZE / 2, 0);
    glVertex3f( SIZE / 2, -SIZE / 2, 0);
    glVertex3f( SIZE / 2,  SIZE / 2, 0);
    glVertex3f(-SIZE / 2,  SIZE / 2, 0);
    glColor3f(1, 1, 1);
    
    */
    
    
    //The WALL
    glPushMatrix();
    glTranslatef(0, 1, 0);
    glScalef(10,10,10);
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex3f(-SIZE *2, -SIZE *2, -SIZE / 2);
    glVertex3f(-SIZE *2, -SIZE *2,  SIZE / 2);
    glVertex3f(SIZE *2,  -SIZE *2, SIZE / 2);
    glVertex3f(SIZE *2,  -SIZE *2, -SIZE / 2);
    glEnd();
    glPopMatrix();
    
    
    //THE FLOOR
    glPushMatrix();
    glTranslatef(0, 0, -2);
    glScalef(10,10,10);
    //glColor3f(.3,.3,.3);
    //glColor3f(0.5f, 0.3f, 0.01f); brownish
    //glColor3f(0.8f, 0.8f, 0.7f); //wheat
    //glColor3f(0.858824, 0.576471, 0.439216);  //tan
    //glColor3f(0.91, 0.76, 0.65);          //lightwood
    glColor3f( 0.75 , 0.6 , 0.49);        //mediumwood
    //glColor3f( 0.59 , 0.41 , 0.31);       //darktan
    
    
    glBegin(GL_QUADS);
    glVertex3f(-SIZE / 2, -SIZE *2, 0);
    glVertex3f( SIZE / 2, -SIZE *2, 0);
    glVertex3f( SIZE / 2,  SIZE *2, 0);
    glVertex3f(-SIZE / 2,  SIZE *2, 0);
    glEnd();
    glPopMatrix();
    
    
    
    
    //The GRID
    glPushMatrix();
    glTranslatef(0, 0, -2);
    glTranslatef(0, double(offset)/speed, .01);
    glScalef(10,10,10);
    
    glBegin(GL_LINES);
    
    int gridSize = 50;
    glColor3f(.25,.25,.25);
    for(int i=-gridSize/2;i<=gridSize/2;i++) {
        
        glVertex3f(SIZE*i/gridSize,-SIZE *2,0);
        glVertex3f(SIZE*i/gridSize,SIZE *2,0);
        
        
        glVertex3f(-SIZE / 2,SIZE*(i-gridSize/2)/gridSize *2,0);
        glVertex3f(SIZE / 2,SIZE*(i-gridSize/2)/gridSize *2,0);
        
         
    };
    glEnd();
    glPopMatrix();
    offset++;
    offset%=20;
}