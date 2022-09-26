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


    protected:
        static constexpr int kBufferSize = 256;

    private:
        int socket_;
        sockaddr_in internet_socket_address_;
        char buffer_[kBufferSize];

};

#endif