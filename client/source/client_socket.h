#ifndef CLIENT_SOCKET_H
#define CLIENT_SOCKET_H

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <string>

class ClientSocket {
    public:
        ClientSocket(std::string ip_address, int port);

        int Communicate();
        int Receive(std::string file_path);
        int PrintFile(std::string file_path);

    protected:
        static constexpr int kBufferSize = 256;
        inline static const std::string kTemporaryFileName = "temp.txt";

    private:
        int socket_;
        sockaddr_in internet_socket_address_;
        char buffer_[kBufferSize];

};

#endif