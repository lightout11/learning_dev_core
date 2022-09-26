#ifndef SERVER_SOCKET_H
#define SERVER_SOCKET_H

#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <string>

class ServerSocket {
    public:
        ServerSocket(std::string ip_address, int port);

        int Listen();
        int Handle();
        int SendFile(std::string file_path);

    protected:
        static constexpr int kBackLog = 8;
        static constexpr int kBufferSize = 256;
        inline static const std::string kTemporaryFileName = "temp.txt";

    private:
        int socket_;
        int accepted_socket_;
        sockaddr_in internet_socket_address_;
        std::string command_;
        char buffer_[kBufferSize];
};

#endif