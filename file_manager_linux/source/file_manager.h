#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include <fstream>
#include <filesystem>

/*
void create_file(std::string file_path);

void make_directory(std::string directory_path);

void remove(std::string file_path);

void remove_directory(std::string directory_path);

void read_file(std::string file_path);

void list_directory_content(std::string directory_path);

void copy(std::string source, std::string destination);
*/

class file_manager {
    public:
        file_manager();
        
        void create_file(std::string file_path);
        void make_directory(std::string directory_path);
        void change_directory(std::string directory_path);
        void remove(std::string file_path);
        void remove_directory(std::string directory_path);
        //void read_file(std::string file_path);
        void list_directory_content(std::string directory_path);
        void copy(std::string source, std::string destination);
        void move(std::string source, std::string destination);

    protected:

    private:
        std::filesystem::path current_path;
        
};

#endif