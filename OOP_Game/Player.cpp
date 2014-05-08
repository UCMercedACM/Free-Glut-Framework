//
//  Player.cpp
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 Matthew Bucci. All rights reserved.
//

#include "Player.h"

Player::Player() : Actor(0,0,1,100) {
    
    
}

void Player::draw() {
    
    glPushMatrix();
    glTranslatef(x,y, 0);
    glColor3f(1, 1, 1);
    
    glBegin(GL_QUADS);
    
    glVertex3f(-SIZE / 4, -SIZE / 4, 0);
    glVertex3f( SIZE / 4, -SIZE / 4, 0);
    glVertex3f( SIZE / 4,  SIZE / 4, 0);
    glVertex3f(-SIZE / 4,  SIZE / 4, 0);
    glEnd();
    
    glBegin(GL_QUADS);
    //glColor3b(255,1,1);
    glVertex3f(-SIZE / 4, -SIZE / 4, .1);
    glVertex3f( SIZE / 4, -SIZE / 4, .1);
    glVertex3f( SIZE / 4,  SIZE / 4, .1);
    glVertex3f(-SIZE / 4,  SIZE / 4, .1);
    glEnd();
    
    glColor3f(1, 1, 1);
    glPopMatrix();
    
    
}