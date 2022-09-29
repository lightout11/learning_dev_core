#include "client_socket.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    cout << "Enter IP address: ";
    string ip_address;
    cin >> ip_address;
    cout << "Enter port: ";
    int port;
    cin >> port;

    ClientSocket client_socket(ip_address, port);
    client_socket.Communicate();
}