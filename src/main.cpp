#include <iostream>
#include "Universe.hpp"
#include "Cell.hpp"

int main() {
    Universe universe(10, 100);

    universe.addCell(1, 1);
    universe.addCell(2, 2);
    universe.addCell(3, 3);

    Cell* cell = universe.getCell(2, 2);
    if (cell) {
        std::cout << "Found cell at (2, 2)" << std::endl;
    } else {
        std::cout << "Cell at (2, 2) not found" << std::endl;
    }


    universe.displayUniverse();

    return 0;
}