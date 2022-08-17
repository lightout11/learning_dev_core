#include <iostream>
#include "Songs.h"

using namespace std;

Songs::Songs()  : songs(), pointer(songs.begin()) {}

void Songs::add(string name, string performers, int rating) {
    songs.emplace_back(name, performers, rating);
    cout << "Added " << name << endl;
}

void Songs::play_first_song() {
    pointer = songs.begin();
    cout << "Playing:" << endl;
    cout << pointer->get_info() << endl;
}

void Songs::play_next_song() {
    if (++pointer != songs.end()) {
        cout << "Playing:" << endl;
        cout << pointer->get_info() << endl;
    } else {
        cout << "End of playlist.";
    }
}

void Songs::play_previous_song() {
    if (pointer != songs.begin()) {
        cout << "Playing:" << endl;
        cout << (--pointer)->get_info() << endl;
    } else {
        cout << "This is the first song of the playlist." << endl;
    }
}

void Songs::add_and_play(string name, string performers, int rating) {
    songs.emplace(pointer, name, performers, rating);
    cout << "Added " << name << endl;
}

void Songs::display_playlist() {
    for (auto it = songs.begin(); it != songs.end(); it++) {
        cout << it->get_info() << endl;
    }
}