#include <iostream>
#include "Songs.h"

using namespace std;

int main() {
    Songs songs;
    songs.add("Chung ta cua hien tai", "Son Tung M-TP", 5);
    songs.add("Lan hen ho dau tien", "Huyen Tam Mon", 5);
    songs.add("Tu thich thich thanh thuong thuong", "AMEE, Hoang Dung", 5);
    songs.add("Vao ha", "Suni Ha Linh", 5);
    songs.play_first_song();
    songs.play_next_song();
    songs.play_next_song();
    songs.play_previous_song();
    songs.display_playlist();
}