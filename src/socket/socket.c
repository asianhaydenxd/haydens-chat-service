/* socket.c */

#include "socket.h"

int initializeConnection(const char* ip, int port) {
  // Create socket
  int mySocket = socket(AF_INET, SOCK_STREAM, 0);

  if(mySocket < 0) {
    printf("Socket could not be created\n");
    return -1;
  }

  // Establish server address
  struct sockaddr_in serverAddress;
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = htons(port);
  int internetSuccess = inet_pton(AF_INET, ip, &serverAddress.sin_addr);

  if(internetSuccess <= 0) {
    printf("Invalid address\n");
    return -1;
  }

  // Connect socket with server
  int connectSuccess = connect(mySocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

  if(connectSuccess < 0) {
    printf("Could not connect to server\n");
    return -1;
  }

  return mySocket;
}
