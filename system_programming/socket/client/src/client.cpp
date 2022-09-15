#include <iostream>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <string>
#include <fcntl.h>

using namespace std;

const int MAX_BUFFER_SIZE = 8;

void communicate(int socketfd) {
    char buffer[MAX_BUFFER_SIZE];
    int n;
    while (true) {
        bzero(buffer, MAX_BUFFER_SIZE);
        cout << "Enter message: ";
        n = 0;
        while ((buffer[n++] = getchar()) != '\n') {}
        write(socketfd, buffer, sizeof(buffer));
        bzero(buffer, sizeof(buffer));
        cout << "From server: " << buffer << endl;
        if (strncmp(buffer, "exit" , 4) == 0) {
            cout << "Client exit..." << endl;
            break;
        }
    }
}

int main(int argc, char* argv[]) {
    cout << "Creating socket..." << endl;
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        cout << "Error creating socket: " << strerror(errno) << endl;
        return 1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    string ipaddr = "127.0.0.1";
    addr.sin_addr.s_addr = inet_addr(ipaddr.c_str());
    addr.sin_port = htons(9001);

    cout << "Connecting to server " << ipaddr << "..." << endl;
    int connecting = connect(socketfd, (struct sockaddr*)& addr, sizeof(addr));
    if (connecting == -1) {
        cout << "Error connecting to server: " << strerror(errno) << endl;
        return 1;
    }
    cout << "Connected to server." << endl;

    communicate(socketfd);
}