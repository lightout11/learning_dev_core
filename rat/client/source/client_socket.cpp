#include "client_socket.h"
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <string>

using namespace std;

ClientSocket::ClientSocket(string ip_address, int port) {
    socket_ = socket(AF_INET, SOCK_STREAM, 0);
    internet_socket_address_.sin_family = AF_INET;
    internet_socket_address_.sin_addr.s_addr = inet_addr(ip_address.c_str());
    internet_socket_address_.sin_port = htons(port);
    if (connect(socket_, (sockaddr*)&internet_socket_address_, sizeof(internet_socket_address_)) {
        cout << "Error connecting to " << ip_address << endl;
    }
}

int ClientSocket::Communicate() {
    while (true) {
    }
}