#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

int main(int argc, char* argv[]) {
    time_t current_time = time(nullptr);
    cout << ctime(&current_time) << endl;
}