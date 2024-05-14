#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>  // for gettimeofday

int main() {
  int sockfd;
  struct sockaddr_in serveraddr;
  struct timeval start_time, end_time;
  double time_taken;

  // Create a UDP socket
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(1);
  }

  // Define server address
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_port = htons(12345);
  serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  // Message to send
  char* message = "Hello, Server!";

  // Get start time before sending
  gettimeofday(&start_time, NULL);

  // Send the message
  if (sendto(sockfd, message, strlen(message), 0, (struct sockaddr*) &serveraddr, sizeof(serveraddr)) == -1) {
    perror("sendto");
    exit(1);
  }

  // Get end time after sending
  gettimeofday(&end_time, NULL);

  // Calculate one-way latency (time taken to send)
  time_taken = (end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_usec - start_time.tv_usec);
  time_taken /= 1000000;  // convert to seconds

  printf("One-way latency (sending): %lf seconds\n", time_taken);

  close(sockfd);

  return 0;
}
