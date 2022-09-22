#include "file_manager.h"
#include <fstream>
#include <filesystem>

using namespace std;

void file_manager::create_file(string file_path) {
    ofstream file(file_path);
    file.close();
}

void file_manager::make_directory(string directory_path) {
    string command = directory_path;
    command = "mkdir " + command;
    system(command.c_str());
}

void file_manager::change_directory(string directory_path) {
    filesystem::path temp_path(directory_path);
    current_path = temp_path;
}

void file_manager::remove(string file_path) {
    string command = file_path;
    command = "rm -f" + command;
    system(command.c_str());
}

void file_manager::remove_directory(string directory_path) {
    string command = directory_path;
    command = "rmdir -f" + command;
    system(command.c_str());
}

void file_manager::copy(string source, string destination) {
    string command = source;
    command = "cp " + command + " " + destination;
}

void file_manager::move(string source, string destination) {
    string command = source;
    command = "cp " + command + " " + destination;
})