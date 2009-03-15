#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <sys/time.h>

#include <GL/glut.h>

#include <protocol/TBinaryProtocol.h>
#include <transport/TSocket.h>
#include <transport/TTransportUtils.h>

#include "../../gen-cpp/Split.h"

using namespace std;
using namespace
  apache::thrift;
using namespace
  apache::thrift::protocol;
using namespace
  apache::thrift::transport;

using namespace
  split;

using namespace
  boost;
//
SplitClient *
  client;

// Initial square position and size
GLfloat
  x = 0.0f;
GLfloat
  y = 0.0f;
GLfloat
  rsize = 25;

// Step size in x and y directions
// (number of pixels to move each time)
GLfloat
  xstep = 1.0f;
GLfloat
  ystep = 1.0f;

// Keep track of windows changing width and height
GLfloat
  windowWidth;
GLfloat
  windowHeight;

///////////////////////////////////////////////////////////
// Called to draw scene
void
RenderScene (void)
{
  string
    s = "";
  client->display (s);
  cout << s << endl;
  // Clear the window with current clearing color
  glClear (GL_COLOR_BUFFER_BIT);

  // Set current drawing color to red
  //                 R     G         B
  glColor3f (1.0f, 0.0f, 0.0f);

  // Draw a filled rectangle with current color
  glRectf (x, y, x + rsize, y - rsize);

  // Flush drawing commands and swap
  glutSwapBuffers ();
}

///////////////////////////////////////////////////////////
// Called by GLUT library when idle (window not being
// resized or moved)
void
TimerFunction (int value)
{
  client->idle ();
}


///////////////////////////////////////////////////////////
// Setup the rendering state
void
SetupRC (void)
{
  // Set clear color to blue
  glClearColor (0.0f, 0.0f, 1.0f, 1.0f);
}


///////////////////////////////////////////////////////////
// Called by GLUT library when the window has chanaged size
void
ChangeSize (int w, int h)
{
  client->reshapeFunc (w, h);
}

///////////////////////////////////////////////////////////
// Main program entry point
int
main (int argc, char *argv[])
{
  glutInit (&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowSize (800, 600);
  glutCreateWindow ("Bounce");
  shared_ptr < TTransport > socket (new TSocket ("localhost", 9090));
  shared_ptr < TTransport > transport (new TBufferedTransport (socket));
  shared_ptr < TProtocol > protocol (new TBinaryProtocol (transport));
  client = new SplitClient (protocol);
  try
  {
    transport->open ();

  } catch (TException & tx)
  {
    printf ("ERROR: %s\n", tx.what ());
  }
  glutDisplayFunc (RenderScene);
  glutReshapeFunc (ChangeSize);
  glutTimerFunc (33, TimerFunction, 1);

  SetupRC ();

  glutMainLoop ();
  transport->close ();

  return 0;
}
