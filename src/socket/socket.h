#ifndef SOCKET_H
#define SOCKET_H

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

#include "../packets/packets.h"

// Establish a connection with a server
int initializeConnection(const char* ip, int port);

#endif