#include "client_socket.h"
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    string ip_address = "127.0.0.1";
    int port = 7777;

    ClientSocket client_socket(ip_address, port);
    client_socket.Communicate();
}