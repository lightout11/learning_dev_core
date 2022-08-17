#include <sstream>
#include <iomanip>
#include <string>
#include "Song.h"

using namespace std;

Song::Song(std::string name, int rating, std::string performers = "Unknown performers") :
    name(name), rating(rating), performers(performers) {}

string Song::get_info() {
    stringstream ss;
    ss << setw(32) << name << setw(32) << performers << setw(8) << rating;
    return ss.str();
}