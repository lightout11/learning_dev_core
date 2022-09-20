#ifndef FILEAGENT_H
#define FILEAGENT_H

#include <string>
#include <filesystem>

class FileAgent {
    public:
        FileAgent(std::string filepath);

        bool is_modified();
        std::filesystem::file_time_type get_last_modified();
    
    protected:

    private:
        std::filesystem::file_time_type last_modified;
        std::filesystem::path file_path_;        
};

#endif