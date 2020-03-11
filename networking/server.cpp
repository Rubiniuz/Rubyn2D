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
  listener.listen(25565);
  listener.accept(socket);

  socket.send(text.c_str(), text.length() + 1);

  socket.receive(buffer, sizeof(buffer), received);

  std::cout << buffer << std::endl;
}

void Server::Run()
{
  while(isRunning)
  {
    if(mode == 's')
    {
      std::getline(std::cin, text);
    }
    else if(mode == 'r')
    {

    }
  }
}
