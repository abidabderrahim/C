#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

/* socket client for connect and retrieve data .*/

int main()
{
  int net_socket;
  // socket(domain, type socket, protocol);
  net_socket = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in server_address; // socket structure .
  server_address.sin_family = AF_INET; // family address .
  server_address.sin_port = htons(2000);
  server_address.sin_addr.s_addr = INADDR_ANY;

  int result = connect(net_socket, (struct sockaddr *) &server_address, sizeof(server_address));

  char data[256];
  if (result == 0)
  {
    printf("socket connected .\n");
    recv(net_socket, &data, sizeof(data), 0);
    printf("retrieve data : \n%s\n", data);
  }
  else
    printf("socket unconnected .\n");

  close(socket);
  return 0;
}
