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
  std::cout << "(-TCP-) t or u (-UDP-)" << std::endl;
  std::cin >> mode;

  std::cout << "Set server port: ";
  std::cin >> port;

  std::cout << "Set max number of players: ";
  std::cin >> playersString;
  maxPlayers = std::stoi(playersString);

  connectedPlayers = 0;

  if (mode == 'u')
  {
    Usocket.bind(port);
    do {
      sf::IpAddress rIp;
      unsigned short port;
      Usocket.receive(buffer, sizeof(buffer), received, rIp, port);
      if (received > 0)
      {
        computerID[port] = rIp;
        std::cout << "Received connection from Ip: " << rIp << " Running Port: " << port << std::endl;
        connectedPlayers++;
      }
    } while(connectedPlayers != maxPlayers);
  }
  if (mode == 't')
  {
    listener.listen(port);
    listener.accept(Tsocket);
    Tsocket.send(text.c_str(), text.length() + 1);
    Tsocket.receive(buffer, sizeof(buffer), received);
    std::cout << buffer << std::endl;
    tcpStatus = 's';
  }
}

void Server::Run()
{
  isRunning = true;
  std::cout << "Starting loop " << isRunning << std::endl;
  while(isRunning)
  {
    if (mode == 'u')
    {
      std::getline(std::cin, text);
      if (text == "stop server")
      {
        isRunning = false;
      }
      std::map<unsigned short, sf::IpAddress>::iterator tempIterator;
      for(tempIterator = computerID.begin(); tempIterator != computerID.end(); tempIterator++)
        Usocket.send(text.c_str(), text.length() + 1, tempIterator->second, tempIterator->first);
    }

    if (mode == 't')
    {
      if (tcpStatus == 's')
      {
        std::getline(std::cin, text);
        Tsocket.send(text.c_str(), text.length() + 1);
        tcpStatus = 'r';
      }
      else if (tcpStatus == 'r')
      {
        Tsocket.receive(buffer, sizeof(buffer), received);
        if (received > 0)
        {
          std::cout << "Received: " << buffer << std::endl;
          tcpStatus = 's';
        }
      }
    }

  }
}
