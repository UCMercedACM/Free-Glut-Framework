//
//  Controller.cpp
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 Matthew Bucci. All rights reserved.
//
#include "Game.h"
#include "Controller.h"
#include "Grid.h"
#include "GameControl.h"
Controller::Controller() {
    // Set up GLUT callback functions to receive events:
    ::glutKeyboardFunc ( glutKeyboardCB );
    ::glutSpecialFunc ( glutSpecialCB );
    ::glutMouseFunc ( glutMouseCB );
    ::glutPassiveMotionFunc ( glutMotionCB );
    ::glutMotionFunc(glutMotionCB);


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
    
    cout << key;
    if(key == 'a')
        theGame->logic.player->x-=.1;
    if(key == 'd')
        theGame->logic.player->x+=.1;
    if(key == 'w')
        theGame->logic.player->y+=.1;
    if(key == 's')
        theGame->logic.player->y-=.1;
    
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
    float x1 = float(x);
    float y1 = float(y);
    
    windowToScene(x1, y1);
    if(y1 > 1.8) y1 = 1.8;
    cout << y1 << endl;
    theGame->logic.player->y = theGame->logic.player->y + .1*(y1 - theGame->logic.player->y);
    theGame->logic.player->x = theGame->logic.player->x + .1*(x1 - theGame->logic.player->x);
}

void Controller::glutMenuCB ( int m )
{
    /*
    CurEvent.type = Menu;
    CurEvent.menuev = m;
    Singleton->handle ( CurEvent );
    */
}

// mouse events are in window coordinates, but your scene is in [0,1]x[0,1],
// so make here the conversion when needed
void Controller::windowToScene ( float& x, float &y )
{
    x = -2*((x/float(WINDOW_WIDTH))*2 - 1.0f);
    y = (2.0f*(y/float(WINDOW_HEIGHT)))*2 -1.0f;
}
