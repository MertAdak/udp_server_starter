#ifndef __UDPCLIENT__
#define __UDPCLIENT__

#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

class udp_server{
public:
    int sockfd;
    char client_message[256];
    char server_message[256];
    struct sockaddr_in client_addr, serv_addr; //server address and client address
    socklen_t cLen = sizeof(client_addr);

    udp_server(int port, const char* comms_ip);
    void recieve_message();


};
#endif