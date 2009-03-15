#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <sys/time.h>

#include <GL/glut.h>

#include <protocol/TBinaryProtocol.h>
#include <transport/TSocket.h>
#include <transport/TTransportUtils.h>


#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include "../../gen-cpp/Split.h"

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace split;

using namespace boost;
//
SplitClient *client;

// Initial square position and size
GLfloat x = 0.0f;
GLfloat y = 0.0f;
GLfloat rsize = 25;

// Step size in x and y directions
// (number of pixels to move each time)
GLfloat xstep = 1.0f;
GLfloat ystep = 1.0f;

// Keep track of windows changing width and height
GLfloat windowWidth;
GLfloat windowHeight;


///////////////////////////////////////////////////////////
// Called to draw scene
void RenderScene(void)
{
    string s;
    client->display(s);
    vector < string > splitVec;
    boost::split(splitVec, s, boost::is_any_of("\n"));

    glClear(GL_COLOR_BUFFER_BIT);

    vector < string > commandVec;
    for (vector < string >::iterator line = splitVec.begin();
	 line != splitVec.end(); ++line) {
	boost::split(commandVec, *line, boost::is_any_of(","));
	if (commandVec.empty()) {
	    continue;
	}
	if (commandVec[0].compare("color") == 0) {

	    float r = boost::lexical_cast < float >(commandVec[1]);
	    float g = boost::lexical_cast < float >(commandVec[2]);
	    float b = boost::lexical_cast < float >(commandVec[3]);

	    glColor3f(r, g, b);
	} else if (commandVec[0].compare("rect") == 0) {

	    float x = boost::lexical_cast < float >(commandVec[1]);
	    float y = boost::lexical_cast < float >(commandVec[2]);
	    float w = boost::lexical_cast < float >(commandVec[3]);
	    float h = boost::lexical_cast < float >(commandVec[4]);

	    glRectf(x, y, w, h);
	} else {
	    cout << "Unknown command " << commandVec[0] << endl;
	}
    }
    glutSwapBuffers();
}

///////////////////////////////////////////////////////////
// Called by GLUT library when idle (window not being
// resized or moved)
void TimerFunction(int value)
{
    client->idle();
    glutPostRedisplay();
    glutTimerFunc(33, TimerFunction, 1);
}


///////////////////////////////////////////////////////////
// Setup the rendering state
void SetupRC(void)
{
    // Set clear color to blue
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}


///////////////////////////////////////////////////////////
// Called by GLUT library when the window has chanaged size
void ChangeSize(int w, int h)
{
    cout << "in reshape " << w << ", " << h << endl;
    client->reshapeFunc(w, h);
    GLfloat aspectRatio;

    // Prevent a divide by zero
    if (h == 0)
	h = 1;

    // Set Viewport to window dimensions
    glViewport(0, 0, w, h);

    // Reset coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Establish clipping volume (left, right, bottom, top, near, far)
    aspectRatio = (GLfloat) w / (GLfloat) h;
    if (w <= h) {
	windowWidth = 100;
	windowHeight = 100 / aspectRatio;
	glOrtho(-100.0, 100.0, -windowHeight, windowHeight, 1.0, -1.0);
    } else {
	windowWidth = 100 * aspectRatio;
	windowHeight = 100;
	glOrtho(-windowWidth, windowWidth, -100.0, 100.0, 1.0, -1.0);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

///////////////////////////////////////////////////////////
// Main program entry point
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Bounce");
    shared_ptr < TTransport > socket(new TSocket("localhost", 9090));
    shared_ptr < TTransport > transport(new TBufferedTransport(socket));
    shared_ptr < TProtocol > protocol(new TBinaryProtocol(transport));
    client = new SplitClient(protocol);
    try {
	transport->open();

    } catch(TException & tx) {
	printf("ERROR: %s\n", tx.what());
    }
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    glutTimerFunc(33, TimerFunction, 1);

    SetupRC();

    glutMainLoop();
    transport->close();

    return 0;
}
