#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

// Function to extract the content between <title> and </title> tags
void extractTitle(const char *html, char *title, size_t titleSize) {
    const char *titleStart = strstr(html, "<title>");
    if (titleStart != NULL) {
        titleStart += strlen("<title>");

        const char *titleEnd = strstr(titleStart, "</title>");
        if (titleEnd != NULL) {
            size_t length = titleEnd - titleStart;
            if (length < titleSize - 1) {
                strncpy(title, titleStart, length);
                title[length] = '\0';
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        return 1;
    }

    char *address = argv[1];

    int net_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in remote_address;
    remote_address.sin_family = AF_INET;
    remote_address.sin_port = htons(80);
    inet_aton(address, &remote_address.sin_addr.s_addr);

    connect(net_socket, (struct sockaddr *) &remote_address, sizeof(remote_address));

    char request[] = "GET /imghp?hl=en&ogbl HTTP/1.1\r\n\r\n";
    char response[4096];

    send(net_socket, request, sizeof(request), 0);
    recv(net_socket, &response, sizeof(response), 0);

    // Extract and print the title
    char title[256];
    extractTitle(response, title, sizeof(title));
    printf("Title: %s\n", title);

    close(net_socket);

    return 0;
}

