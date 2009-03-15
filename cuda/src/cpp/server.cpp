// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "Split.h"
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

char data[] = "this is a test\n";
class SplitHandler : virtual public SplitIf {
 public:
  SplitHandler() {
    // Your initialization goes here
  }

  void display(std::string& _return) {
    // Your implementation goes here
    _return = data;
    printf("display\n");
  }

  void keyboardEventFunc(const int8_t key, const int16_t x, const int16_t y) {
    // Your implementation goes here
    printf("keyboardEventFunc\n");
  }

  void mouseEventFunc(const int16_t button, const int16_t x, const int16_t y) {
    // Your implementation goes here
    printf("mouseEventFunc\n");
  }

  void mouseMotionFunc(const int16_t x, const int16_t y) {
    // Your implementation goes here
    printf("mouseMotionFunc\n");
  }

  void reshapeFunc(const int16_t x, const int16_t y) {
    // Your implementation goes here
    printf("reshapeFunc\n");
  }

  void idle() {
    // Your implementation goes here
    printf("idle\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<SplitHandler> handler(new SplitHandler());
  shared_ptr<TProcessor> processor(new SplitProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

