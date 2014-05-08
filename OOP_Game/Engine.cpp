//
//  Engine.cpp
//  OOP_Game
//
//  Created by Deathstar on 5/7/14.
//  Copyright (c) 2014 ___UCMerced___. All rights reserved.
//

#include "Engine.h"
#include "Game.h"

Engine::Engine() {
    // First store this instance in our singleton pointer

    // Set up idle callback for background processing if needed:
    ::glutIdleFunc (glutIdleCB);
    
    // Set up GLUT callback function for resizing window:
    ::glutReshapeFunc (glutReshapeCB);
    
    // Set up GLUT callback for drawing the scene:
    ::glutDisplayFunc (glutDisplayCB);
    
    ObjectUID = 0;
}

void Engine::glutIdleCB ()
{
    theGame->update();
    theGame->draw();
}

void Engine::glutReshapeCB ( int w, int h )
{
    theGame->resize ( w, h );
}

void Engine::glutDisplayCB ()
{
    theGame->draw();
}

void Engine::Register(GraphicsObject *Object){
    
    Actor * ActorToRegister = dynamic_cast<Actor*>(Object);
    //Object->uid = ObjectUID;
    
    if(ActorToRegister)
        logic.Register(ActorToRegister);
    
    renderer.Register(Object);
}

void Engine::UnRegister(GraphicsObject *Object){
    Actor * ActorToRegister = dynamic_cast<Actor*>(Object);
    
    if(ActorToRegister)
        logic.UnRegister(ActorToRegister);
    
    renderer.UnRegister(Object);
}