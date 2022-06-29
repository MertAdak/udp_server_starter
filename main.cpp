#include "udp_server.h"
using namespace std;

int main (int argc, char *argv[]){

    int port = 8080;

    udp_server UDP_server = udp_server(port, "192.168.1.145");
    UDP_server.recieve_message();

}