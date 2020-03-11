#include <iostream>

#include "server.h"
#include "client.h"

int main()
{
  std::string inputString;

  sf::IpAddress ip = sf::IpAddress::getLocalAddress();

  char connectionType;

  std::cout << "Enter (s) for Server, Enter (c) for client: " << std::endl;
  std::cin >> connectionType;

  if (connectionType == 's')
  {
    Server server;
    server.mode = 's';
    server.Start();
    server.Run();
  }
  else if (connectionType == 'c')
  {
    Client client;
    client.serverIp = ip;
    client.mode = 'r';
    client.Start();
    client.Run();
  }

  return 0;
}