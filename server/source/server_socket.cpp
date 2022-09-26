#include "server_socket.h"
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <iostream>
#include <sys/sendfile.h>
#include <fcntl.h>
#include <cstdio>
#include <cstring>

using namespace std;

ServerSocket::ServerSocket(string ip_address, int port) {
    command_ = "";
    socket_ = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_ < 0) {
        cout << "Error creating socket." << endl;
        exit(1);
    }
    internet_socket_address_.sin_family = AF_INET;
    internet_socket_address_.sin_addr.s_addr = inet_addr(ip_address.c_str());
    internet_socket_address_.sin_port = htons(port);
    if (bind(socket_, (sockaddr*)&internet_socket_address_, sizeof(internet_socket_address_)) < 0) {
        cout << "Error binding socket." << endl;
        exit(1);
    }
}

int ServerSocket::SendFile(std::string file_path) {
    FILE* file = fopen(file_path.c_str(), "r");
    char buffer[kBufferSize];
    memset(buffer, 0, kBufferSize);
    while (fgets(buffer, kBufferSize, file) != nullptr) {
        cout << "Sending data..." << endl;
        if (send(accepted_socket_, buffer, sizeof(buffer), 0) <= 0) {
            cout << "Error sending file." << endl;
            return 1;
        }
        memset(buffer, 0, kBufferSize);
    }
    cout << "Sent file." << endl;
    memset(buffer, 0, sizeof(buffer));
    fclose(file);
    return 0;
}

int ServerSocket::Handle() {
    while (true) {
        read(accepted_socket_, buffer_, sizeof(buffer_));
        cout << buffer_ << endl;
        string file = kTemporaryFileName;
        command_ = buffer_ + string(" > ") + file;
        system(command_.c_str());
        SendFile(file);
        char buffer[kBufferSize];
        memset(buffer, 0, kBufferSize);
        strcpy(buffer, "\e");
        send(accepted_socket_, buffer, kBufferSize, 0);
    }
    return 0;
}

int ServerSocket::Listen() {
    cout << "Listening..." << endl;
    if (listen(socket_, kBackLog) < 0) {
        cout << "Error listening socket." << endl;
        exit(1);
    }
    socklen_t internet_socket_address_length = sizeof(internet_socket_address_);
    accepted_socket_ = accept(socket_, (sockaddr*)&internet_socket_address_, &internet_socket_address_length);
    if (accepted_socket_ < 0) {
        cout << "Error accepting socket." << endl;
        exit(1);
    }
    cout << "Accepted!" << endl;
    return 0;
}