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
Controller::Controller() {
    // Set up GLUT callback functions to receive events:
    ::glutKeyboardFunc ( glutKeyboardCB );
    ::glutSpecialFunc ( glutSpecialCB );
    ::glutMouseFunc ( glutMouseCB );
    ::glutMotionFunc ( glutMotionCB );
    
    // GLUT also supports a simple menu system, you may try this:
    int id = ::glutCreateMenu ( glutMenuCB ); // the returned id could be used for adding submenus if needed
    glutAttachMenu ( GLUT_RIGHT_BUTTON );
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
    //Create The World
    cout << key;
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
    cout << "test";
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
    cout << "test";
}

void Controller::glutMenuCB ( int m )
{
    /*
    CurEvent.type = Menu;
    CurEvent.menuev = m;
    Singleton->handle ( CurEvent );
    */
}