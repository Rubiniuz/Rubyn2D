#include <iostream>

#include <common/server.h>

int main()
{
  Server server;
  server.Start();
  server.Run();

  return 0;
}
