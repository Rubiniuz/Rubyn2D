#include"network.h"

using namespace std;

Network::Network()
{
  std::cout << "Enter (s) for Server, Enter (c) for Client." << std::endl;
  std::cin >> connectionType;

  std::cout << "Set port number: ";
  std::cin >> port;

  socket.bind(port);

  if (connectionType == 's')
  {
    std::cout << "Set max number of players: ";
    std::cin >> playersString;
    maxPlayers = std::stoi(playersString);

    int players = 0;

    do {
      sf::IpAddress rIp;
      unsigned short port;
      socket.receive(buffer, sizeof(buffer), received, rIp, port);
      if (received > 0)
      {
        computerID[port] = rIp;
        std::cout << "Received connection from Ip: " << rIp << " Running Port: " << port << std::endl;
        players++;
      }
    } while(players != maxPlayers);
  }
  else
  {
    sf::IpAddress sIP = sf::IpAddress::getLocalAddress();
    sf::IpAddress sendIP(sIP);
    std::cout << "Got IP:" << sendIP << std::endl;
    socket.send(text.c_str(), text.length() + 1, sendIP, 2000);
    std::cout << "send the IP" << std::endl;
  }

  bool done = false;

  while(!done)
  {
    if (connectionType == 's')
    {
      std::getline(std::cin, text);
      std::map<unsigned short, sf::IpAddress>::iterator tempIterator;
      for(tempIterator = computerID.begin(); tempIterator != computerID.end(); tempIterator++)
        socket.send(text.c_str(), text.length() + 1, tempIterator->second, tempIterator->first);
    }
    else
    {
      sf::IpAddress tempIp;
      unsigned short tempPort;
      socket.receive(buffer, sizeof(buffer), received , tempIp, tempPort);
      if (received > 0)
      {
        std::cout << "Received: " << buffer << std::endl;
      }
    }
  }

}

Network::~Network()
{

}
