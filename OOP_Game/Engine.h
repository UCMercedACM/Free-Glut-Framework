//
//  Engine.h
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 Matthew Bucci. All rights reserved.
//

#ifndef __OOP_Game__Engine__
#define __OOP_Game__Engine__

#include <iostream>
#include "stdafx.h"
#include "Controller.h"
#include "GraphicsCore.h"
#include "AudioCore.h"
#include "GameControl.h"

using namespace std;

class Engine {
    Controller controls;
    Graphics renderer;
    Audio sound;
    GameControl logic;
    
    void initFreeglut(const char* label,int x, int y, int w, int h);
    

public:
    Engine();
    virtual void draw() = 0;
    virtual void resize( int w, int h ) {}
    virtual void update() {}
    
    void redraw() { glutPostRedisplay(); }
    
    // Note that glutMainLoop never returns so your program is entirely event-driven
    void run () { glutMainLoop (); }
    
    //Glut CallBacks
    static void glutDisplayCB ();
    static void glutIdleCB ();
    static void glutReshapeCB ( int w, int h );
};

static Engine* Singleton;

#endif /* defined(__OOP_Game__Engine__) */
