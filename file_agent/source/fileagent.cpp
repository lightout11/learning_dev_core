#include "fileagent.h"
#include <chrono>
#include <string>

using namespace std;

FileAgent::FileAgent(string file_path) {
    file_path_ = {file_path};
    last_modified = filesystem::last_write_time(file_path_);
}

bool FileAgent::is_modified() {
    auto current_time = filesystem::last_write_time(file_path_);
    if (current_time != last_modified) {
        last_modified = current_time;
        return true;
    }
    return false;
}