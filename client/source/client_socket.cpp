#include "client_socket.h"
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/sendfile.h>
#include <fcntl.h>

using namespace std;

ClientSocket::ClientSocket(string ip_address, int port) {
    socket_ = socket(AF_INET, SOCK_STREAM, 0);
    internet_socket_address_.sin_family = AF_INET;
    internet_socket_address_.sin_addr.s_addr = inet_addr(ip_address.c_str());
    internet_socket_address_.sin_port = htons(port);
    cout << "Connecting..." << endl;
    if (connect(socket_, (sockaddr*)&internet_socket_address_, sizeof(internet_socket_address_))) {
        cout << "Error connecting to " << ip_address << endl;
        exit(1);
    }
}

int ClientSocket::Receive(string file_path) {
    ofstream file(file_path);
    char buffer[kBufferSize];
    while (true) {
        cout << "Receiving data..." << endl;
        if (recv(socket_, buffer, kBufferSize, 0) <= 0) {
            break;
        }
        // int data = recv(socket_, buffer, kBufferSize, MSG_DONTWAIT);
        // cout << data << endl;
        // if (data <= 0) {
        //     break;
        // }
        // if (strlen(buffer) == 0) {
        //     break;
        // }
        if (strcmp(buffer, "\e") == 0) {
            break;
        }
        // cout << buffer << endl;
        file << buffer;
        memset(buffer, 0, kBufferSize);
    }
    cout << "Received file." << endl;
    file.close();
    return 0;
}

int ClientSocket::PrintFile(string file_path) {
    ifstream file(file_path);
    string buffer;
    while (getline(file, buffer)) {
        cout << buffer << endl;
    }
    file.close();
    return 0;
}

int ClientSocket::Communicate() {
    while (true) {
        // send message
        memset(buffer_, 0, kBufferSize);
        cout << "> ";
        string tmp;
        getline(cin, tmp);
        strcpy(buffer_, tmp.c_str());
        send(socket_, buffer_, kBufferSize, 0);
        // receive file
        Receive(kTemporaryFileName);
        PrintFile(kTemporaryFileName);
    }
    return 0;
}