#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

void error(const char *error_message)
{
  perror(error_message);
  exit(0);
}

int main(int argc, char *argv[])
{

  struct sockaddr_in server_address;
  struct hostent *server;

  char buffer[255];
  if (argc < 3)
  {
    fprintf(stderr,"usage %s <hostname> <port>\n", argv[0]);
    exit(0);
  }
  int port = atoi(argv[2]);
  int net_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (net_socket < 0)
  {
    error("error opening socket communication .\n");
    exit(0);
  }
  server = gethostbyname(argv[1]);
  if (server == NULL)
  {
    fprintf(stderr, "error define to hostname \n");
  }

  bzero((char *) &server_address, sizeof(server_address));
  server_address.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);
  server_address.sin_port = htons(port);

  if (connect(net_socket, (struct scokaddr *) &server_address, sizeof(server_address)) < 0)
  {
    error("error connecting .\n");
  }

  while (1)
  {
    bzero(buffer, 255);
    printf("Client : ");
    fgets(buffer, 255, stdin);
    int n = write(net_socket, buffer, strlen(buffer));
    if (n < 0)
      error("error writing to socket \n");
    bzero(buffer, 255);
    n = read(net_socket, buffer, 255);
    if (n < 0)
      error("error reading from socket \n");
    printf("server : %s", buffer);
    int i = strncmp("finish", buffer, 6);
    if (i == 0)
      break;
  }

  close(net_socket);

  return 0;
}
