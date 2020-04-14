#include "server.h"
#include<iostream>

Server::Server()
{

}

Server::~Server()
{

}

void Server::Start()
{
  std::cout << "Set server port: ";
  std::cin >> port;

  socket.bind(port);

  std::cout << "Set max number of players: ";
  std::cin >> playersString;
  maxPlayers = std::stoi(playersString);

  connectedPlayers = 0;

  do {
    sf::IpAddress rIp;
    unsigned short port;
    socket.receive(buffer, sizeof(buffer), received, rIp, port);
    if (received > 0)
    {
      computerID[port] = rIp;
      std::cout << "Received connection from Ip: " << rIp << " Running Port: " << port << std::endl;
      connectedPlayers++;
    }
  } while(connectedPlayers != maxPlayers);
}

void Server::Run()
{
  while(isRunning)
  {
    std::getline(std::cin, text);
    if (text == "stop server")
    {
      isRunning = false;
    }
    std::map<unsigned short, sf::IpAddress>::iterator tempIterator;
    for(tempIterator = computerID.begin(); tempIterator != computerID.end(); tempIterator++)
      socket.send(text.c_str(), text.length() + 1, tempIterator->second, tempIterator->first);
  }
}
