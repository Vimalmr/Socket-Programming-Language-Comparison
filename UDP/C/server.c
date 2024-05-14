#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
  int sockfd;
  struct sockaddr_in serveraddr, cliaddr;
  socklen_t len;
  char buffer[1024];

  // Create a UDP socket
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(1);
  }

  // Define server address
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_port = htons(12345);
  serveraddr.sin_addr.s_addr = INADDR_ANY;

  // Bind the socket to the address
  if (bind(sockfd, (struct sockaddr*) &serveraddr, sizeof(serveraddr)) == -1) {
    perror("bind");
    exit(1);
  }

  printf("Server listening...\n");

  // Receive the message (no latency measurement needed on server)
  len = sizeof(cliaddr);
  if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*) &cliaddr, &len) == -1) {
    perror("recvfrom");
    exit(1);
  }

  printf("Received data: %s\n", buffer);

  close(sockfd);

  return 0;
}
