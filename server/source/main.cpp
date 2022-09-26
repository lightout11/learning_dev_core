#include "server_socket.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    string ip_address = "127.0.0.1";
    int port = 7777;
    
    ServerSocket server_socket(ip_address, port);
    server_socket.Listen();
    server_socket.Handle();
}