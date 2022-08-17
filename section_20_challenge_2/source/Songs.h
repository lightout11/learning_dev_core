#pragma once

#include <list>
#include <string>
#include "Song.h"

class Songs {
    public:
        Songs();

        void add(std::string name, std::string performers, int rating);
        void play_first_song();
        void play_next_song();
        void play_previous_song();
        void add_and_play(std::string name, std::string performers, int rating);
        void display_playlist();

    protected:

    private:
        std::list<Song> songs;
        std::list<Song>::iterator pointer;
};