#include"network.h"

using namespace std;

Network::Network()
{
  std::cout << "Enter (s) for Server, Enter (c) for Client." << std::endl;
  cin >> connectionType;

  std::cout << "Set port number: ";
  cin >> port;

  socket.bind(port);

  if (connectionType == 's')
  {
    char answer = 'b';
    do {
      sf::IpAddress rIp;
      unsigned short rPort;
      socket.receive(buffer, sizeof(buffer), received, rIp, rPort);
      if (received > 0)
        computerID[rPort] = rIp;
      cin >> answer;
    } while(answer != 'a');

    /*listener.listen(2000);
    listener.accept(socket);
    text += "Server";
    mode = 's';*/
  }
  else //if (connectionType == 'c')
  {
    std::string sIP;
    std::cout << "Enter server ip: ";
    std::cin >> sIP;
    sf::IpAddress sendIP(sIP);
    socket.send(text.c_str(), text.length() + 1, sendIP, 2000);
    /*
    socket.connect(ip, 2000);
    text += "Client";
    mode = 'r';*/
  }

  /*socket.send(text.c_str(), text.length() + 1);

  socket.receive(buffer, sizeof(buffer), received);

  std::cout << buffer << std::endl;
  */
  while(!done)
  {
    if (connectionType == 's')
    {
      std::getline(cin, text);
      std::map<unsigned short, sf::IpAddress>::iterator tempIterator;
      for(tempIterator = computerID.begin(); tempIterator != computerID.end(); tempIterator++)
        socket.send(text.c_str(), text.length() + 1, tempIterator->second, tempIterator->first);
      /*socket.send(text.c_str(), text.length() + 1);
      mode = 'r';*/
    }
    else //if(mode == 'r')
    {
      sf::IpAddress tempIp;
      unsigned short tempPort;
      socket.receive(buffer, sizeof(buffer), received , tempIp, tempPort);
      if (received > 0)
      {
        std::cout << "Received: " << buffer << std::endl;
        //mode = 's';
      }
    }
  }

}

Network::~Network()
{

}
