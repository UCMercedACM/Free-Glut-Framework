# include <iostream>
# include "Game.h"
# include "stdafx.h"



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
    return 0;
}
