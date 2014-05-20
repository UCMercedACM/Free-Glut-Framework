# include <iostream>
# include "Game.h"
# include "stdafx.h"

#include "Grid.h"

//==========================================================================
// Main routine
//==========================================================================


Game* theGame;
int main ( int argc, char** argv )
{
    // Init freeglut library:
    glutInit ( &argc,argv );
    glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    
    
    // Now create the window of your application:
    theGame = new Game();
    theGame->setup();
    theGame->run();

    return 0;
}
