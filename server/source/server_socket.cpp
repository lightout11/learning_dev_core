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
    // command_ = "";
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

int ServerSocket::Handle() {
    while (true) {
        char buffer[kBufferSize];
        read(accepted_socket_, buffer, sizeof(buffer));
        cout << buffer << endl;
        message_ = buffer;
        int parse = ParseMessage();
        switch (parse) {
            case 0: {
                string command = message_ + " > " + kOutput;
                SendFile(kOutput);
                char buffer[kBufferSize];
                memset(buffer, 0, kBufferSize);
                strcpy(buffer, "\e");
                send(accepted_socket_, buffer, kBufferSize, 0);
                break;
            }
            case 1: {
                string path = message_.substr(message_.find(" ") + 1);
                SendFile(path);
                char buffer[kBufferSize];
                memset(buffer, 0, kBufferSize);
                strcpy(buffer, "\e");
                send(accepted_socket_, buffer, kBufferSize, 0);
                break;
            }
            case 2: {
                
            }
        }
        
        // string file = kTemporaryFileName;
        // string command = buffer + string(" > ") + file;
        // system(command.c_str());
        // SendFile(file);
        // // char buffer[kBufferSize];
        // memset(buffer, 0, kBufferSize);
        // strcpy(buffer, "\e");
        // send(accepted_socket_, buffer, kBufferSize, 0);
    }
    return 0;
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

int ServerSocket::ParseMessage() {
    if (message_.find("sendfile") == 0) {
        return 1;
    }
    if (message_.find("getfile") == 0) {
        return 2;
    }
    if (message_.find("cd") == 0) {
        return 3;
    }
    if (message_.find("remoteexit")) {
        return 4;
    }
    return 0;
}