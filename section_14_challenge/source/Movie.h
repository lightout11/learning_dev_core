#pragma once

#include <string>

class Movie {
    public:
        std::string name;
        std::string rating;
        long long watched;

        Movie(std::string name, std::string rating, long long watched);

        void display();

    protected:

    private:
};