#include <iostream>
#include "Movie.h"

using namespace std;

Movie::Movie(string name, string rating, long long watched) :
    name {name}, rating {rating}, watched {watched} {}

void Movie::display() {
    cout << "Movie: " << name << endl;
    cout << "Rating: " << rating << endl;
    cout << "Watched: " << watched << endl;
}