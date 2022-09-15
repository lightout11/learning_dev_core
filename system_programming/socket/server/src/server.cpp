#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

const int MAX_BUFFER_SIZE = 8;

void communicate(int client_socketfd) {
    char buffer[MAX_BUFFER_SIZE];
    int n;
    while (true) {
        bzero(buffer, MAX_BUFFER_SIZE);
        read(client_socketfd, buffer, sizeof(buffer));
        cout << "From client: " << buffer << "\t To client: ";
        bzero(buffer, MAX_BUFFER_SIZE);
        n = 0;
        while ((buffer[n++] = getchar()) != '\n') {}
        write(client_socketfd, buffer, sizeof(buffer));
        if (strncmp("exit", buffer, 4) == 0) {
            cout << "Server exit..." << endl;
            break;
        }
    }
}

int main(int argc, const char* argv[]) {
    cout << "Creating Socket..." << endl;
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        cout << "Error creating socket: " << strerror(errno) << endl;
        return 1;
    }
    cout << "Socket is successfully created." << endl;

    struct sockaddr_in addr;
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    string ipaddr = "127.0.0.1";
    addr.sin_addr.s_addr = inet_addr(ipaddr.c_str());
    //addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(9001);

    cout << "Binding socket to address " << ipaddr << endl;
    //cout << "Binding socket to address " << inet_ntoa(addr.sin_addr) << endl;
    int bound = bind(socketfd, (struct sockaddr*)& addr, sizeof(addr));
    if (bound == -1) {
        cout << "Error binding socket: " << strerror(errno) << endl;
        return 1;
    }

    cout << "Listening for connections..." << endl;
    int listening = listen(socketfd, 10);
    if (listening != 0) {
        cout << "Error listening on socket: " << strerror(errno) << endl;
        return 1;
    }

    struct sockaddr_in client_addr;
    bzero(&client_addr, sizeof(client_addr));
    socklen_t client_addr_len = sizeof(client_addr);
    int client_socketfd = accept(socketfd, (struct sockaddr*)& client_addr, &client_addr_len);
    if (client_socketfd == -1) {
        cout << "Error accepting connection: " << strerror(errno) << endl;
        return 1;
    }
    cout << "Accepted connection from " << inet_ntoa(client_addr.sin_addr) << endl;

    communicate(client_socketfd);
    
    return 0;
}