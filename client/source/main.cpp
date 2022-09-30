#include "client_socket.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    string default_ip_address = "127.0.0.1";
    int default_port = 10000;
    string ip_address = "";
    int port = 0;
    switch (argc) {
        case 1:
            cout << "Enter IP address: ";
            cin >> ip_address;
            cout << "Enter port: ";
            cin >> port;
            break;
        case 3:
            ip_address = argv[1];
            port = stoi(argv[2]);
            break;
        default:
            cout << "Invalid input.";
            return 1;
    }

    ClientSocket client_socket(ip_address, port);
    client_socket.Communicate();
}