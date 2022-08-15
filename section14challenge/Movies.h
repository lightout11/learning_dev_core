#pragma once

#include <set>
#include "Movie.h"

class Movies {
    public:
        void add(std::string name, std::string rating, int watched);
        void increase_watched_count(std::string name);
        void display_all_movies();

    protected:
    
    private:
        std::set<Movie> movies;
};