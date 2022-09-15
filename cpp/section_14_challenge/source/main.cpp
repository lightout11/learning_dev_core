#include <iostream>
#include "Movies.h"

using namespace std;

int main() {
    Movies movies {};
    movies.add("Teasing master Takagi-san", "G", 1000000000);
    movies.add("When will Ayumu make his move?", "PG", 100000000);
    
    movies.display_all_movies();

    movies.add("Phineas and Ferb", "G", 10000000000);
    movies.add("Tom and Jerry", "G", 10000000000);

    movies.increase_watched("Phineas and Ferb", 1000);
    movies.display_all_movies();


}