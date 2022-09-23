#include "server_socket.h"
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>

using namespace std;

ServerSocket::ServerSocket(string ip_address, int port) {
    command_ = "";
    socketfd_ = socket(AF_INET, SOCK_STREAM, 0);
    internet_socket_address_.sin_family = AF_INET;
    internet_socket_address_.sin_addr.s_addr = inet_addr(ip_address.c_str());
    internet_socket_address_.sin_port = htons(port);
    bind(socketfd_, (sockaddr*)& internet_socket_address_, sizeof(internet_socket_address_));
}

int ServerSocket::Listen() {
    listen(socketfd_, kBackLog);
}

int ServerSocket::Kill(pid_t pid) {
    kill(pid, 0);
}