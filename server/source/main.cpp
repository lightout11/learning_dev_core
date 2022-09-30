#include "server_socket.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    string default_ip_address = "127.0.0.1";
    int default_port = 10000;
    string ip_address = "";
    int port = 0;
    switch (argc) {
        case 1:
            ip_address = default_ip_address;
            port = default_port;
        case 3:
            ip_address = argv[1];
            port = stoi(argv[2]);
            break;
        default:
            cout << "Invalid input.";
            return 1;
    }
    
    ServerSocket server_socket(ip_address, port);
    server_socket.Listen();
    server_socket.Handle();
}