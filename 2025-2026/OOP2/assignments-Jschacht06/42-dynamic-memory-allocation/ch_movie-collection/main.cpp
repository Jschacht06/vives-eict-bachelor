#include <iostream>
#include "MovieCollection.h"

using namespace std;
using namespace ch_movie_collection;

int main() {
    MovieCollection myCollection("My Favorites");

    myCollection.addMovie("Christopher Nolan", "Inception", "Sci-Fi", 148);
    myCollection.addMovie("Frank Darabont", "The Shawshank Redemption", "Drama", 142);
    myCollection.addMovie("Quentin Tarantino", "Pulp Fiction", "Crime", 154);
    myCollection.addMovie("Steven Spielberg", "Jurassic Park", "Adventure", 127);

    myCollection.showMovies();

    myCollection.showFirstMovie();

    myCollection.showNextMovie(); 
    myCollection.showNextMovie(); 

    std::cout << "\nRemoving 'Pulp Fiction'..." << std::endl;
    myCollection.removeMovie("Quentin Tarantino", "Pulp Fiction");

    myCollection.showMovies();

    myCollection.clearMovies();
    myCollection.showMovies();

    return 0;
}