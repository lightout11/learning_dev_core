#pragma once

#include <string>

class Song {
    public:
        Song(std::string name, int rating, std::string performers = UNKNOWN_PERFORMERS);

        std::string get_info();

    protected:
        inline static const std::string UNKNOWN_PERFORMERS = "Unknown Performers";

    private:
        std::string name;
        std::string performers;
        int rating;
};