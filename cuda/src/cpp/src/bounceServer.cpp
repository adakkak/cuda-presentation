// Bounce.cpp
// Demonstrates a simple animated rectangle
// program with GLUT
// OpenGL SuperBible, 3rd Edition
// Richard S. Wright Jr.
// rwright@starstonesoftware.com

#include <iostream>
#include <sstream>
#include <string>

#include "../../gen-cpp/Split.h"
#include <protocol/TBinaryProtocol.h>
#include <server/TSimpleServer.h>
#include <transport/TServerSocket.h>
#include <transport/TBufferTransports.h>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace apache::thrift::server;

using boost::shared_ptr;

using namespace split;
using namespace std;


class SplitHandler:virtual public SplitIf {
public:
// Initial square position and size
    float x;
    float y;
    float rsize;

// Step size in x and y directions
// (number of pixels to move each time)
    float xstep;
    float ystep;

// Keep track of windows changing width and height
    float windowWidth;
    float windowHeight;
    SplitHandler() {
        x = 0.0f;
        y = 0.0f;
        rsize = 25;

        // Step size in x and y directions
        // (number of pixels to move each time)
        xstep = 1.0f;
        ystep = 1.0f;
    }

    float rand_float() {
        return (float) rand() / RAND_MAX;
    }
    ////////////////////////////////////////// Called to draw scene void
    void display(string & _return) {
        ostringstream result;
        result << "color,";
        result << rand_float() << "," << rand_float() << "," << rand_float() << endl;

        result << "rect,";
        result << x << "," << y << "," << x + rsize << "," << y - rsize;

        string s = result.str();
        _return = &s[0];
//      printf("in display\n");
    }

    ///////////////////////////////////////////////////////////
    // Called by GLUT library when idle (window not being
    // resized or moved)
    void idle() {
        // Reverse direction when you reach left or right edge
        if (x > windowWidth - rsize || x < -windowWidth)
            xstep = -xstep;

        // Reverse direction when you reach top or bottom edge
        if (y > windowHeight || y < -windowHeight + rsize)
            ystep = -ystep;

        // Actually move the square
        x += xstep;
        y += ystep;

        // Check bounds. This is in case the window is made
        // smaller while the rectangle is bouncing and the
        // rectangle suddenly finds itself outside the new
        // clipping volume
        if (x > (windowWidth - rsize + xstep))
            x = windowWidth - rsize - 1;
        else if (x < -(windowWidth + xstep))
            x = -windowWidth - 1;

        if (y > (windowHeight + ystep))
            y = windowHeight - 1;
        else if (y < -(windowHeight - rsize + ystep))
            y = -windowHeight + rsize - 1;
//      printf("in idle\n");
    }


    ///////////////////////////////////////////////////////////
    // Called by GLUT library when the window has chanaged size
    void reshapeFunc(int16_t w, int16_t h) {
        windowWidth = w;
        windowHeight = h;
        printf("in reshape %d %d\n", w, h);
    }

    void keyboardEventFunc(const int8_t key, const int16_t x,
                           const int16_t y) {
        // Your implementation goes here
        printf("keyboardEventFunc\n");
    }

    void mouseEventFunc(const int16_t button, const int16_t x,
                        const int16_t y) {
        // Your implementation goes here
        printf("mouseEventFunc\n");
    }

    void mouseMotionFunc(const int16_t x, const int16_t y) {
        // Your implementation goes here
        printf("mouseMotionFunc\n");
    }

};

///////////////////////////////////////////////////////////
// Main program entry point
int main(int argc, char *argv[])
{
    int port = 9090;
    shared_ptr < SplitHandler > handler(new SplitHandler());
    shared_ptr < TProcessor > processor(new SplitProcessor(handler));
    shared_ptr < TServerTransport >
    serverTransport(new TServerSocket(port));
    shared_ptr < TTransportFactory >
    transportFactory(new TBufferedTransportFactory());
    shared_ptr < TProtocolFactory >
    protocolFactory(new TBinaryProtocolFactory());

    TSimpleServer server(processor, serverTransport, transportFactory,
                         protocolFactory);
    server.serve();
    return 0;
}
