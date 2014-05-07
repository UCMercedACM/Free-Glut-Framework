
# include <iostream>
# include "app_window.h"

AppWindow::AppWindow ( const char* label, int x, int y, int w, int h )
          :GlutWindow ( label, x, y, w, h )
 {
   _markx = 0;
   _marky = 0;
   addMenuEntry ( "Option 0", evOption0 );
   addMenuEntry ( "Option 1", evOption1 );
 }

// mouse events are in window coordinates, but your scene is in [0,1]x[0,1],
// so make here the conversion when needed
void AppWindow::windowToScene ( float& x, float &y )
 {
   x = (2.0f*(x/float(_w))) - 1.0f;
   y = 1.0f - (2.0f*(y/float(_h)));
 }

// Called every time there is a window event
void AppWindow::handle ( const Event& e )
 {
   bool rd=true;

   if ( e.type==Keyboard ) 
    switch ( e.key )
    { case ' ': // space bar
	   std::cout << "Space pressed.\n";
       _markx = 1.5;
       _marky = 1.5;
       redraw();
	   break;

	  case 27: // Esc was pressed
	   exit(1);
	}

   if ( e.type==MouseDown || e.type==Motion)
    { _markx=(float)e.mx;
      _marky=(float)e.my;
      windowToScene(_markx,_marky);
    }

   if ( e.type==Menu )
    { std::cout<<"Menu Event: "<<e.menuev<<std::endl;
      rd=false; // no need to redraw
    }

   const float incx=0.02f;
   const float incy=0.02f;
   if ( e.type==SpecialKey )
    switch ( e.key )
    { case GLUT_KEY_LEFT:  _markx-=incx; break;
      case GLUT_KEY_RIGHT: _markx+=incx; break;
      case GLUT_KEY_UP:    _marky+=incy; break;
      case GLUT_KEY_DOWN:  _marky-=incy; break;
      default: rd=false; // no redraw
	}

   if (rd) redraw(); // ask the window to be rendered when possible
}

void AppWindow::resize ( int w, int h )
 {
   // Define that OpenGL should use the whole window for rendering
   glViewport( 0, 0, w, h );
   _w=w; _h=h;
 }

// here we will redraw the scene according to the current state of the application.
void AppWindow::draw ()
 {
   // Clear the rendering window
   glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

   // Clear the trasnformation stack
   glMatrixMode( GL_MODELVIEW );
   glLoadIdentity();

   // Set drawing color to yellow
   glColor3d ( 1.0, 0.9, 0.3 );		

   // Draw a cross
   const double s=0.05;
   glBegin ( GL_LINES );
   glVertex2d ( _markx-s, _marky );
   glVertex2d ( _markx+s, _marky );
   glVertex2d ( _markx, _marky-s );
   glVertex2d ( _markx, _marky+s );
   glEnd();

   // Draw some white points
   glColor3d ( 1.0, 1.0, 1.0 );		
   glBegin ( GL_POINTS );
   glVertex2d ( 0.5, 0.5 );
   glVertex2d (-0.5,-0.5 );
   glVertex2d ( 0.5,-0.5 );
   glVertex2d (-0.5, 0.5 );
   glEnd();

   // Draw three overlapping triangles
   glBegin( GL_TRIANGLES ); // you may use GL_POLYGON for generic *convex* polygons
   glColor3f ( 1.0, 0.0, 0.0 ); // red
   glVertex2d (-0.7, -0.5 );
   glVertex2d ( 0.1, 0.8 );
   glVertex2d ( 0.3, 0.6 );

   glColor3f ( 0.0, 1.0, 0.0 ); // green
   glVertex3d ( -0.3, 0.7, 0.1 ); // the Z coordinate allows to control what is on top of what
   glVertex3d ( 0.6,-0.5, -0.1 );
   glVertex3d ( 0.7,-0.3, -0.1 );

   glColor3f ( 0.0, 0.0, 1.0 ); // blue
   glVertex3d ( 0.85, -0.25, 0.0 );
   glVertex3d ( -0.8, -0.4, -0.1 );
   glVertex3d ( -0.8, -0.1, -0.1 );
   glEnd();

   /* you may use GL_POLYGON for generic *convex* polygons, like this:
   glBegin( GL_POLYGON );
   glColor3f ( ... );
   glVertex2d ( ... );
   glVertex2d ( ... );
   glVertex2d ( ... );
   glVertex2d ( ... );
   glEnd();*/

   // Swap buffers
   glFlush();         // flush the pipeline (usually not necessary)
   glutSwapBuffers(); // we were drawing to the back buffer, now bring it to the front
}

