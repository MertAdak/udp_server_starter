#include "udp_server.h"

udp_server::udp_server(int port, const char* comms_ip){

    //Create socket here
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    std::cout << "socfd: " << sockfd << std::endl;
    if(sockfd < 0){  // int sockfd = socket(domain, type, protocol) and AF_INET uses IPv4 and SOCK_DGRAM uses Datagram Protocol=UDP
        cout<<"Cannot create socket"<<endl;
        exit(-1);   
    }
    memset(&server_message, '\0', sizeof(server_message));
    memset(&client_message, '\0', sizeof(client_message));
    cout<<"Socket created successfully!"<<endl;
    //Identify socket here
    serv_addr.sin_family      = AF_INET;
    serv_addr.sin_port        = htons(port); //htons means convert a number into 16-bit network representation
    serv_addr.sin_addr.s_addr = inet_addr(comms_ip);

        // Bind the socket with the server address 
    if ( bind(sockfd, (const struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0 ) { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
        } 
    std::cout<<"debug"<<std::endl;

};
void udp_server::recieve_message(){
    while(true){
        int n = recvfrom(sockfd, client_message, sizeof(client_message), MSG_WAITALL, (struct sockaddr*) &client_addr, &cLen);

    std::cout << "n: " << n << std::endl; 

    printf("Received message from IP: %s and port: %i\n",
           inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    
    printf("Msg from client: %s\n", client_message);
    }
    
    
    // // Respond to client:
    // strcpy(server_message, client_message);
    
    // if (sendto(sockfd, server_message, strlen(server_message), 0, (struct sockaddr*)&client_addr, cLen) < 0){
    //     printf("Can't send\n");
    //     exit(-1);
    // }
    
    // Close the socket:
    close(sockfd);
    exit(0);
}
