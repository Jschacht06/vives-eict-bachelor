#pragma once
#include <string>
#include <iostream>

namespace ch_movie_collection {

    class Movie {
    private:
        // Data attributes
        std::string directorName;
        std::string title;
        std::string genre;
        int duration; // in minutes

        // The link to the next node
        Movie* nextMovie;

    public:
        // Constructor
        Movie(std::string director, std::string title, std::string genre, int duration);

        // Getters for logic
        std::string getDirector() const;
        std::string getTitle() const;
        
        // Pointer management
        Movie* getNext() const;
        void setNext(Movie* next);

        // Display helper
        void display() const;
    };

}