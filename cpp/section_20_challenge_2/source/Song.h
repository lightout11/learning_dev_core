#pragma once

#include <string>

class Song {
    public:
        Song(std::string name, std::string performers, int rating);

        std::string get_info();

    protected:

    private:
        std::string name;
        std::string performers;
        int rating;
};