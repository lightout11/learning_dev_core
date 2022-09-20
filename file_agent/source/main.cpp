#include "fileagent.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: file_agent <file_path>" << endl;
        return 1;
    }
    FileAgent file_agent(argv[1]);
    cout << "File agent created for file: " << argv[1] << endl;
    while (true) {
        if (file_agent.is_modified()) {
            
            //cout << "File modified!" << file_agent.get_last_modified() << endl;
        }
    }
    return 0;
}