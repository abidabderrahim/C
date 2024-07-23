#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  char *address;
  address = argv[1];

  int net_socket = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in remot_address;
  remot_address.sin_family = AF_INET;
  remot_address.sin_port = htons(80);
  inet_aton(address, &remot_address.sin_addr.s_addr);

  connect(net_socket, (struct sockaddr *) &remot_address, sizeof(remot_address));

  char request[] = "GET /imghp?hl=en&ogbl HTTP/1.1\r\n\r\n";
  char response[4096];

  send(net_socket, request, sizeof(request), 0);
  recv(net_socket, &response, sizeof(response), 0);
  printf("response for web server : \n%s\n", response);
  close(net_socket);

  return 0;
}
