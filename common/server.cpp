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
  currentClientId = 0;

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
        std::cout << "Received connection from Ip: " << rIp << " Running Port: " << port << " With clientName: " << buffer << std::endl;
        ServerClient* client = new ServerClient();
        client->clientIp = rIp;
        client->clientPort = port;
        client->clientName = buffer;
        client->clientId = currentClientId;
        clients.push_back(client);
        currentClientId++;
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

  sf::Clock dtClock;
  float dt;

  while(isRunning)
  {
    dt = dtClock.getElapsedTime().asSeconds();
    if (mode == 'u')
    {
      if (dt >= 2)
      {
        printf("\033c");
        std::cout << "\x1B[2J\x1B[H";
        dt = dtClock.restart().asSeconds();
        std::string message = "stop server";
        for(auto &c : clients)
        {
          StringToData(c, message);

          SendUDPPacket(c);
          ReceiveUDPPacket(c);
        }
      }
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

void Server::StringToData(ServerClient* c, std::string message)
{
  strncpy(c->serverData, message.c_str(), sizeof(c->serverData));
  c->serverData[sizeof(c->serverData)-1] = '\0';
}

void Server::SendUDPPacket(ServerClient* client)
{
  if(Usocket.send(client->serverData, sizeof(client->serverData), client->clientIp, client->clientPort) == sf::Socket::Done)
  {
    std::cout << "succesfully send all data: " << client->serverData << std::endl;
  }
}

void Server::ReceiveUDPPacket(ServerClient* client)
{
  std::size_t received;
  if(Usocket.receive(client->clientData, sizeof(client->clientData), received , client->clientIp, client->clientPort) == sf::Socket::Done)
  {
    if (received > 0)
    {
      //client->clientData = buffer;
      std::cout << "Received: " << client->clientData << std::endl;
    }
  }
}
/*
void Server::SendTCPPacket(sf::Packet _packet)
{
  Tsocket.send(_packet);
  _packet.clear();
}

void Server::ReceiveTCPPacket(sf::Packet _packet)
{
  Tsocket.receive(_packet);
}
*/
