#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>


int main()
{
  FILE *file;
  file = fopen("file.html", "r");
  if (file == NULL)
  {
    printf("Unbale to open file .\n");
    return -1;
  }
  char response [1024];
  fgets(response, 1024, file);
  char http_header[2048] = "HTTP/1.1 200 OK\r\n\n";
  strcat(http_header, response);

  int net_socket = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(2000);
  server_address.sin_addr.s_addr = INADDR_ANY;

  bind(net_socket, (struct sockaddr *) &server_address, sizeof(server_address));
  listen(net_socket, 5);
  
  int client_socket;
  while(1)
  {
    client_socket = accept(net_socket, NULL, NULL);
    send(client_socket, http_header, sizeof(http_header), 0);
    close(client_socket);
  }
  
  return 0;
}
