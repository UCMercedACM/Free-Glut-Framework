//
//  Game.h
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 Matthew Bucci. All rights reserved.
//

// Ensure the header file is included only once in multi-file projects
#ifndef APP_WINDOW_H
#define APP_WINDOW_H

#include "stdafx.h"
#include "Engine.h"

// The functionality of your application should be implemented inside AppWindow
class Game : public Engine{
    
    enum MenuEv { evOption0, evOption1 };
    float _markx, _marky;
    int _w, _h;
    virtual void draw ();
    virtual void resize ( int w, int h );
    virtual void update();
    
public :
    Game();
    
    void windowToScene ( float& x, float &y );
 };

#endif // APP_WINDOW_H
