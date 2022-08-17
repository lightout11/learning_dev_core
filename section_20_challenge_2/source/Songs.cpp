#include <iostream>
#include "Songs.h"

using namespace std;

Songs::Songs()  : songs(), pointer(songs.begin()) {}

void Songs::add(string name, string performers, int rating) {
    songs.emplace_back(name, performers, rating);
    cout << "Added " << name << endl;
}