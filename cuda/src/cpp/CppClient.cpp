#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include <protocol/TBinaryProtocol.h>
#include <transport/TSocket.h>
#include <transport/TTransportUtils.h>

#include "../gen-cpp/Split.h"

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace split;

using namespace boost;

int main(int argc, char** argv) {
  shared_ptr<TTransport> socket(new TSocket("localhost", 9090));
  shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
  SplitClient client(protocol);

  try {
    transport->open();

    client.keyboardEventFunc(1, 1, 1);

    transport->close();
  } catch (TException &tx) {
    printf("ERROR: %s\n", tx.what());
  }

}
