#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

void error(const char *error_message)
{
  perror(error_message);
  exit(1);
}

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    fprintf(stderr, "Port Number Not Defined \n");
    exit(1);
  }

  char buffer[256];
  struct sockaddr_in server_address, client_address;
  socklen_t client;
  int net_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (net_socket < 0)
  {
    error("error socket communication \n");
  }
  bzero((char *)&server_address, sizeof(server_address));
  int port = atoi(argv[1]);

  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(port);

  if (bind(net_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0)
    error("binding failed \n");

  listen(net_socket, 5);
  client = sizeof(client_address);
  int newsocket = accept(net_socket, (struct sockaddr *) &client_address, &client);
  if (newsocket < 0)
    error("communication can't accept \n");

  while(1)
  {
    bzero(buffer, 256);
    int n = read(newsocket, buffer, 255);
    if (n < 0)
      error("error to read data .\n");
    printf("Clinet : %s", buffer);
    bzero(buffer, 255);
    printf("Server : ");
    fgets(buffer, 255, stdin);
    n = write(newsocket, buffer, 255);
    if (n < 0)
      error("error to write data .\n");
    int i = strncmp("finish", buffer, 6);
    if (i == 0)
      break;
  }
  close(newsocket);
  close(net_socket);
  return 0;
}
