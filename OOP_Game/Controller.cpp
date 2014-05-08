//
//  Controller.cpp
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 Matthew Bucci. All rights reserved.
//
#include "Engine.h"
#include "Controller.h"
#include "Grid.h"
#include "GameControl.h"
Controller::Controller() {
    // Set up GLUT callback functions to receive events:
    ::glutKeyboardFunc ( glutKeyboardCB );
    ::glutSpecialFunc ( glutSpecialCB );
    ::glutMouseFunc ( glutMouseCB );
    ::glutMotionFunc ( glutMotionCB );


}

void Controller::glutKeyboardCB ( unsigned char key, int x, int y )
{
    /*
    CurEvent.type = Keyboard;
    CurEvent.key = key;
    CurEvent.mx = x;
    CurEvent.my = y;
    Singleton->handle ( CurEvent );
    */
    /*
    cout << key;
    if(key == 'a')
        Actors[0]->x-=.1;
    if(key == 'b')
        Actors[0]->x+=.1;
    */
        //theGame->logic.player->x+=.01;
}

void Controller::glutSpecialCB ( int key, int x, int y )
{
    /*
    CurEvent.type = SpecialKey;
    CurEvent.key = key;
    CurEvent.mx = x;
    CurEvent.my = y;
    Singleton->handle ( CurEvent );
    */
}

void Controller::glutMouseCB ( int b, int s, int x, int y )
{
    /*
    CurEvent.type = s==GLUT_UP? MouseUp:MouseDown;
    CurEvent.button = b;
    CurEvent.mx = x;
    CurEvent.my = y;
    Singleton->handle ( CurEvent );
    */
}

void Controller::glutMotionCB ( int x, int y )
{
    /*
    // use this to ignore a mouse event right after menu selection:
    //if ( CurEvent.type==Menu ) return;
    CurEvent.type = Motion;
    CurEvent.mx = x;
    CurEvent.my = y;
    Singleton->handle ( CurEvent );
    */
}

void Controller::glutMenuCB ( int m )
{
    /*
    CurEvent.type = Menu;
    CurEvent.menuev = m;
    Singleton->handle ( CurEvent );
    */
}