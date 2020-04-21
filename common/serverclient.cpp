#include "serverclient.h"

ServerClient::ServerClient()
{

}

ServerClient::~ServerClient()
{

}

void ServerClient::Update()
{
  if (inputs[0]) { position.x += 2.5f; } //W
  if (inputs[1]) { rotation -= 5; } //A
  if (inputs[2]) { position.x -= 2.5f; } //S
  if (inputs[3]) { rotation += 5; } //D

  //if (inputs[1]) { position.y -= 5; } //A
  //if (inputs[3]) { position.y += 5; } //D
  
  if (inputs[4]) { } //shoot bullet
}
