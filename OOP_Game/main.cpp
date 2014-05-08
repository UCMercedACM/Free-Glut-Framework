# include <iostream>
# include "Game.h"
# include "stdafx.h"
#include "Grid.h"


//==========================================================================
// Main routine
//==========================================================================


int main ( int argc, char** argv )
{
    // Init freeglut library:
    glutInit ( &argc,argv );
    glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    
    
    // Now create the window of your application:
    Game* Main = new Game ();
    Grid * surface = new Grid();
    theGame->run();

    return 0;
}
