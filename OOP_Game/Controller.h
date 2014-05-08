//
//  Controller.h
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 Matthew Bucci. All rights reserved.
//

#ifndef __OOP_Game__Controller__
#define __OOP_Game__Controller__

#include <iostream>
#include "stdafx.h"

class Controller {
    
public:
    Controller();
    enum EventType { SpecialKey, Keyboard, MouseUp, MouseDown, Motion, Menu, None };
    struct Event
    { EventType type;
        int button, key, menuev, mx, my;
        Event() { type=None; button=key=menuev=mx=my=0; }
    };
    
    static void glutMenuCB ( int m );
    static void glutMouseCB ( int b, int s, int x, int y );
    static void glutMotionCB ( int x, int y );
    
    static void glutKeyboardCB ( unsigned char key, int x, int y );
    static void glutSpecialCB ( int key, int x, int y );
    
    
};

#endif /* defined(__OOP_Game__Controller__) */
