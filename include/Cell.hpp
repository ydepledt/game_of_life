#ifndef CELL_HPP
#define CELL_HPP

#include <iostream>


class Cell {
public:
    Cell(int coordx, int coordy) : coordx(coordx), coordy(coordy), status(true), next(nullptr) {}
    int coordx;
    int coordy;
    int status;
    Cell* next;
};

#endif
