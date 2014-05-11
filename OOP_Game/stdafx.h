//
//  stdafx.h
//  OOP_Game
//
//  Created by Matthew Bucci on 5/7/14.
//  Copyright (c) 2014 Matthew Bucci. All rights reserved.
//

#ifndef OOP_Game_stdafx_h
#define OOP_Game_stdafx_h

// Include GLUT (OpenGL Graphics Utility Library) header files.
// In Windows we include our own included freeglut header file, but
// in Linux, the header file should be installed in the system.
#if defined WIN32
#include <freeglut/freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <OpenGL/OpenGL.h>
#else
#include <GL/freeglut.h>
#endif

#include <typeinfo>
#include "Math.h"


//GAME OPTIONS
#define WINDOW_START_X 0
#define WINDOW_START_Y 0
#define WINDOW_WIDTH   1024
#define WINDOW_HEIGHT  800
#define GAME_TITLE     "THE BEST GAME EVER"
#define SIZE .5

#endif
