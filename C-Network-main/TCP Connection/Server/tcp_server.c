#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>


int main()
{

  char message[256] = "Hello World!";
  
  int net_socket = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(2000);
  server_address.sin_addr.s_addr = INADDR_ANY;

  bind(net_socket, (struct sockaddr *) &server_address, sizeof(server_address));
  
  listen(net_socket, 5);
  printf("Server Listening ...\n");

  int client_socket;
  client_socket = accept(net_socket, NULL, NULL);
  
  send(client_socket, message, sizeof(message), 0);
  
  close(socket);

  return 0;
}
