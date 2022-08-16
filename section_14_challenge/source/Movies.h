#pragma once

#include <vector>
#include "Movie.h"

class Movies {
    public:
        void add(std::string name, std::string rating, long long watched);
        void increase_watched(std::string name, int count);
        void display_all_movies();

    protected:
    
    private:
        std::vector<Movie> movies;
};