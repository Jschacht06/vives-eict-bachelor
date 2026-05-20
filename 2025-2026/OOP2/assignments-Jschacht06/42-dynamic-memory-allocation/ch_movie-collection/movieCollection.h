#pragma once
#include <string>
#include "Movie.h"

namespace ch_movie_collection {

    class MovieCollection {
    private:
        std::string name;
        Movie* head;    
        Movie* current;

    public:
        MovieCollection(std::string name);
        ~MovieCollection(); // Destructor 

        
        void addMovie(std::string director, std::string title, std::string genre, int duration);
        void removeMovie(std::string director, std::string title);
        
        void showFirstMovie();
        void showNextMovie();
        
        void showMovies() const;
        void clearMovies();
    };

}