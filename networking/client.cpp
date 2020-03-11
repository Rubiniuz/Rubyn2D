#include "client.h"
#include<iostream>

Client::Client()
{

}

Client::~Client()
{

}

void Client::Start()
{
  socket.connect(serverIp, 25565);
  std::string text = "Connected to: Client";
  socket.send(text.c_str(), text.length() + 1);

  socket.receive(buffer, sizeof(buffer), received);

  std::cout << buffer << std::endl;
}

void Client::Run()
{
  while(isRunning)
  {
    if(mode == 's')
    {
      std::getline(std::cin, text);
      socket.send(text.c_str(), text.length() + 1);
      mode = 'r';
    }
    else if(mode == 'r')
    {
      socket.receive(buffer, sizeof(buffer), received);
      std::cout << "Received: " << buffer << std::endl;
      mode = 's';
    }
  }
}
