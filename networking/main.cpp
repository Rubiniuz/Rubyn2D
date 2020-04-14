#include <iostream>

#include "server.h"
#include "client.h"
//#include "network.h"

int main()
{
  //Network* network = new Network();
  std::string inputString;

  sf::IpAddress ip = sf::IpAddress::getLocalAddress();

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
    client.serverIp = ip;
    client.serverPort = 2000;
    client.Start();
    client.Run();
  }

  return 0;
}
