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
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <IP_address>\n", argv[0]);
    return 1;
  }

  char *address = argv[1];

  int net_socket = socket(AF_INET, SOCK_STREAM, 0);

  if (net_socket == -1) {
    perror("Error creating socket");
    return 1;
  }

  struct sockaddr_in remote_address;
  remote_address.sin_family = AF_INET;
  remote_address.sin_port = htons(80);
  inet_aton(address, &remote_address.sin_addr.s_addr);

  if (connect(net_socket, (struct sockaddr *) &remote_address, sizeof(remote_address)) == -1) {
    perror("Error connecting to the server");
    close(net_socket);
    return 1;
  }

  char request[] = "GET /imghp?hl=en&ogbl HTTP/1.1\r\n\r\n";
  char response[4096];

  if (send(net_socket, request, sizeof(request), 0) == -1) {
    perror("Error sending request");
    close(net_socket);
    return 1;
  }

  if (recv(net_socket, &response, sizeof(response), 0) == -1) {
    perror("Error receiving response");
    close(net_socket);
    return 1;
  }

  // Find the end of the header (double CRLF)
  char *header_end = strstr(response, "\r\n\r\n");

  if (header_end != NULL) {
    // Calculate the length of the header
    size_t header_length = header_end - response;

    // Null-terminate the header to print only the header
    response[header_length] = '\0';

    printf("Header response from the web server:\n%s\n", response);
  } else {
    fprintf(stderr, "Invalid response format\n");
  }

  close(net_socket);

  return 0;
}

