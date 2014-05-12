//
//  Player.cpp
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 Matthew Bucci. All rights reserved.
//

#include "Player.h"
#include "aiming.h"
#include "Bomb.h"

Player::Player() : Actor(0,-3,0,1,100) {
    pos_delta = 0;
    reticle = new Aiming();

}

void Player::draw() {
    
    
    glPushMatrix();
    glTranslatef(x,y, -z);
    glRotated(60*(x-pos_delta),0,1,0);
    glColor3f(.80, .81, .88);
    glScaled(.5,.5,.5);
    
    
    //cockpit
    //glColor3f(1, 0, 0);
    glBegin(GL_QUADS);
    glVertex3f(-SIZE / 4, -SIZE * 1.5, 0);
    glVertex3f( SIZE / 4, -SIZE * 1.5, 0);
    glVertex3f( SIZE / 3,  -SIZE / 3, 0);
    glVertex3f(-SIZE / 3,  -SIZE / 3, 0);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex3f(-SIZE / 3, -SIZE / 3, 0);
    glVertex3f( SIZE / 3, -SIZE / 3, 0);
    glVertex3f( SIZE / 3.5,  SIZE / 2, 0);
    glVertex3f(-SIZE / 3.5,  SIZE / 2, 0);
    glEnd();
    
    glColor3f(.90, .91, .98);

    //body
    glBegin(GL_QUADS);
    glVertex3f(-SIZE / 3.5, SIZE / 2, 0.0);
    glVertex3f( SIZE / 3.5, SIZE / 2, 0.0);
    glVertex3f( SIZE / 3.5,  SIZE * 4, 0.0);
    glVertex3f(-SIZE / 3.5,  SIZE * 4, 0.0);
    glEnd();
    
    
    //tailtip
    glBegin(GL_QUADS);
    glVertex3f(-SIZE / 6, SIZE * 4.5, 0.0);
    glVertex3f( SIZE / 6, SIZE * 4.5, 0.0);
    glVertex3f( SIZE / 3.5,  SIZE * 4, 0.0);
    glVertex3f(-SIZE / 3.5,  SIZE * 4, 0.0);
    glEnd();
    
    
    //wings
    glColor3f(1, 0, 0);

    glBegin(GL_QUADS);
    glVertex3f(0.0, SIZE , -0.01);
    glVertex3f(SIZE * 3.75, SIZE * 1.5, -0.01);
    glVertex3f( SIZE * 4, SIZE * 2 , -0.01);
    glVertex3f( 0.0,  SIZE * 2 , -0.01);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex3f(0.0, SIZE , -0.01);
    glVertex3f( -SIZE * 3.75, SIZE * 1.5, -0.01);
    glVertex3f( -SIZE * 4, SIZE * 2 , -0.01);
    glVertex3f( 0.0,  SIZE * 2 , -0.01);
    glEnd();
    
    
    //tailwings
    glColor3f(0, 0, 1);
    glBegin(GL_QUADS);
    glVertex3f(-SIZE / 3.5, SIZE * 3.3, 0.0);
    glVertex3f( -SIZE * 1.5, SIZE * 3.6, 0.5);
    glVertex3f( -SIZE * 1.5,  SIZE * 4, 0.5);
    glVertex3f(-SIZE / 3.5,  SIZE * 4, 0.0);
    glEnd();
    
    
    glColor3f(0, 0, 1);
    glBegin(GL_QUADS);
    glVertex3f(SIZE / 3.5, SIZE * 3.3, 0.0);
    glVertex3f( SIZE * 1.5, SIZE * 3.6, 0.5);
    glVertex3f( SIZE * 1.5,  SIZE * 4, 0.5);
    glVertex3f(SIZE / 3.5,  SIZE * 4, 0.0);
    glEnd();
    
    //bottomtailwing
    glBegin(GL_QUADS);
    glVertex3f(0.0, SIZE * 3.3, 0.0);
    glVertex3f( 0.0, SIZE * 3.6, -0.4);
    glVertex3f( 0.0,  SIZE * 4, -0.4);
    glVertex3f(0.0,  SIZE * 4, 0.0);
    glEnd();
    
    
    
    glPopMatrix();
    pos_delta = pos_delta + .2*(x-pos_delta);
    
    
}

void Player::Update() {
    if(isfiring==true) {
        Bomb * bomb = new Bomb(x,y+.5,-z-.05);
        isfiring = false;
    }
}