#ifndef SERVER_SOCKET_H
#define SERVER_SOCKET_H

#include <sys/socket.h>
#include <netinet/ip.h>
#include <string>

class ServerSocket {
    public:
        ServerSocket(std::string ip_address, int port);

        int Listen();
        int Kill(pid_t pid);
        int SendFile(std::string file_path);

    protected:
        static constexpr int kBackLog = 8;

    private:  
        int socketfd_;
        sockaddr socket_address_;
        sockaddr_in internet_socket_address_;
        std::string command_;
        char buffer[256];
};

#endif