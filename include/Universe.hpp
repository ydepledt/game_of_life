#ifndef UNIVERSE_HPP
#define UNIVERSE_HPP

#include <iostream>
#include "Cell.hpp"

class Universe {
    public:
        Universe(int width, int height) : width(width), height(height), head(nullptr) {}
        ~Universe();
        void displayUniverse();
        void addCell(int coordx, int coordy);
        void removeCell(int coordx, int coordy);
        Cell* getCell(int coordx, int coordy);
    private:
        int width;
        int height;
        Cell* head;
};

#endif