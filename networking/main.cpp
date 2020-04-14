#include <iostream>

#include "server.h"
#include "client.h"
//#include "network.h"

int main()
{
  //Network* network = new Network();

  char connectionType;

  std::cout << "Enter (s) for Server, Enter (c) for client: " << std::endl;
  std::cin >> connectionType;

  if (connectionType == 's')
  {
    Server server;
    server.Start();
    server.Run();
  }
  else if (connectionType == 'c')
  {
    Client client;
    client.Start();
    client.Run();
  }

  return 0;
}
