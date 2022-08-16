#include <iostream>
#include "Movies.h"

using namespace std;

void Movies::add(string name, string rating, long long watched) {
    for (auto movie : movies) {
        if (movie.name == name) {
            cout << name << " has already exist.";
            return;
        }
    }
    movies.push_back(Movie(name, rating, watched));
    cout << "Added " << name << "." << endl;
}

void Movies::increase_watched(string name, int count) {
    for (auto& movie : movies) {
        if (movie.name == name) {
            movie.watched += count;
            return;
        }
    }
}

void Movies::display_all_movies() {
    for (auto it = movies.begin(); it != movies.end(); it++) {
        it->display();
        cout << endl;
    }
}