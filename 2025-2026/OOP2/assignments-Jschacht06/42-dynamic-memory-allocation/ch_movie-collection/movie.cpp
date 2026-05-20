#include "Movie.h"

namespace ch_movie_collection {

    Movie::Movie(std::string director, std::string title, std::string genre, int duration)
        : directorName(director), title(title), genre(genre), duration(duration), nextMovie(nullptr) 
    {
    }

    std::string Movie::getDirector() const {
        return directorName;
    }

    std::string Movie::getTitle() const {
        return title;
    }

    Movie* Movie::getNext() const {
        return nextMovie;
    }

    void Movie::setNext(Movie* next) {
        this->nextMovie = next;
    }

    void Movie::display() const {
        std::cout << "Title: " << title 
                  << " | Director: " << directorName 
                  << " | Genre: " << genre 
                  << " | Duration: " << duration << " min" << std::endl;
    }
}