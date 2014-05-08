//
//  Player.cpp
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 Matthew Bucci. All rights reserved.
//

#include "Player.h"

Player::Player() : Actor(0,0,1,100) {
    pos_delta = 0;
}

void Player::draw() {
    
    
    glPushMatrix();
    glTranslatef(x,-3, -y);
    glRotated(60*(x-pos_delta),0,1,0);
    glColor3f(1, 1, 1);
    glScaled(.5,.5,.5);
    
    
    //cockpit
    glBegin(GL_QUADS);
    glVertex3f(-SIZE / 5, -SIZE / 2, 0);
    glVertex3f( SIZE / 5, -SIZE / 2, 0);
    glVertex3f( SIZE / 3.5,  SIZE / 2, 0);
    glVertex3f(-SIZE / 3.5,  SIZE / 2, 0);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex3f(-SIZE / 5, -SIZE / 2, .2);
    glVertex3f( SIZE / 5, -SIZE / 2, .2);
    glVertex3f( SIZE / 3.5,  SIZE / 2, .2);
    glVertex3f(-SIZE / 3.5,  SIZE / 2, .2);
    glEnd();
    
    //wings

    glTranslatef(0,SIZE/2 - .2, 0);
    glBegin(GL_TRIANGLES);
    glVertex3f(0, 0, .21);
    glVertex3f(-SIZE * 2, SIZE * 4, .21);
    glVertex3f( SIZE * 2,  SIZE * 4, .21);
    glEnd();
    
    glTranslatef(0,SIZE/2 - .2, 0);
    glBegin(GL_TRIANGLES);
    glVertex3f(0, 0, .01);
    glVertex3f(-SIZE * 2, SIZE * 4, .01);
    glVertex3f( SIZE * 2,  SIZE * 4, .01);
    glEnd();

    glPopMatrix();
    pos_delta = pos_delta + .2*(x-pos_delta);
    
    
    
}