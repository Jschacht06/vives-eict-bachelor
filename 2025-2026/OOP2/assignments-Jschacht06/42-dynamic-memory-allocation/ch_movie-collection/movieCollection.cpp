#include "MovieCollection.h"
#include <iostream>

namespace ch_movie_collection {

    MovieCollection::MovieCollection(std::string name) 
        : name(name), head(nullptr), current(nullptr) 
    {
    }

    MovieCollection::~MovieCollection() {
        
        clearMovies();
    }

    void MovieCollection::addMovie(std::string director, std::string title, std::string genre, int duration) {
        
        Movie* newMovie = new Movie(director, title, genre, duration);

        
        if (head == nullptr) {
            head = newMovie;
        } 
        else {
            
            Movie* temp = head;
            while (temp->getNext() != nullptr) {
                temp = temp->getNext();
            }
            
            temp->setNext(newMovie);
        }
    }

    void MovieCollection::removeMovie(std::string director, std::string title) {
        if (head == nullptr) return;

        
        if (head->getDirector() == director && head->getTitle() == title) {
            Movie* temp = head;
            head = head->getNext();
            
            
            if (current == temp) current = nullptr;
            
            delete temp;
            std::cout << "Removed: " << title << std::endl;
            return;
        }

       
        Movie* iter = head;
        while (iter->getNext() != nullptr) {
            Movie* target = iter->getNext();
            
            if (target->getDirector() == director && target->getTitle() == title) {
                
                iter->setNext(target->getNext());
                
                if (current == target) current = nullptr;

                delete target;
                std::cout << "Removed: " << title << std::endl;
                return;
            }
            iter = iter->getNext();
        }
        std::cout << "Movie not found: " << title << std::endl;
    }

    void MovieCollection::showFirstMovie() {
        if (head == nullptr) {
            std::cout << "Collection is empty." << std::endl;
            current = nullptr;
            return;
        }
        current = head;
        std::cout << "--- First Movie ---" << std::endl;
        current->display();
    }

    void MovieCollection::showNextMovie() {
        if (current == nullptr) {
            std::cout << "No current movie selected. Use showFirstMovie() to start." << std::endl;
            return;
        }

        if (current->getNext() != nullptr) {
            current = current->getNext();
            std::cout << "--- Next Movie ---" << std::endl;
            current->display();
        } else {
            std::cout << "End of the list reached." << std::endl;
        }
    }

    void MovieCollection::showMovies() const {
        std::cout << "\n--- Collection: " << name << " ---" << std::endl;
        if (head == nullptr) {
            std::cout << "(Empty)" << std::endl;
            return;
        }

        Movie* temp = head;
        while (temp != nullptr) {
            temp->display();
            temp = temp->getNext();
        }
        std::cout << "---------------------------" << std::endl;
    }

    void MovieCollection::clearMovies() {
        Movie* iter = head;
        while (iter != nullptr) {
            Movie* trash = iter;
            iter = iter->getNext();
            delete trash;
        }
        head = nullptr;
        current = nullptr;
        std::cout << "Collection cleared." << std::endl;
    }
}