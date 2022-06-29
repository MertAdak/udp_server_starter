#include "udp_server.h"

udp_server::udp_server(int port, std::string comms_ip){
    memset(&client_message, '\0', sizeof(client_message));
    serv_addr.sin_family      = AF_INET;
    serv_addr.sin_port        = htons(port); //htons means convert a number into 16-bit network representation
    serv_addr.sin_addr.s_addr = inet_addr(comms_ip.c_str());

    //Create socket here
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0){  // int sockfd = socket(domain, type, protocol) and AF_INET uses IPv4 and SOCK_DGRAM uses Datagram Protocol=UDP
        std::cout << "Cannot create socket" << std::endl;
        exit(-1);   
    }
    std::cout << "Socket created successfully and ready to recieve message!" << std::endl;
    // Bind the socket with the server address 
    if (bind(sockfd, (const struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0 ) { 
        perror("Binding the socket failed, cannot recieve message!"); 
        exit(EXIT_FAILURE); 
    }
    std::cout << "Successfully binded the socket" << std::endl;

};
void udp_server::recieve_message(){
    if(recvfrom(sockfd, client_message, sizeof(client_message), MSG_WAITALL, (struct sockaddr*) &client_addr, &cLen)<0){
        std::cout << "Cannot recieve the message!" << std::endl;
    }
    std::cout <<"Message from client: " << client_message << std::endl;
    close(sockfd);
    exit(0);
}
