#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_socket, 5);

    printf("Server listening...\n");
    int client_socket = accept(server_socket, NULL, NULL);
    printf("Connection established.\n");

    char data[1024];
    recv(client_socket, data, sizeof(data), 0);
    printf("Received data: %s\n", data);

    close(client_socket);
    close(server_socket);

    return 0;
}
