#include <fstream>
#include <sstream>
#include "Universe.hpp"

Universe::~Universe() {
    Cell* current = head;
    while (current != nullptr) {
        Cell* next = current->next;
        delete current;
        current = next;
    }
}

Universe* Universe::loadUniverse(std::string filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filepath << std::endl;
        return nullptr;
    }

    int width, height;
    file >> width >> height;

    int maxGen;
    file >> maxGen;

    // Create a new Universe object
    Universe* universe = new Universe(width, height, maxGen);

    std::string line;
    std::getline(file, line); // Read the newline character after the max_gen

    for (int y = 0; y < height; ++y) {
        std::getline(file, line);
        for (int x = 0; x < width; ++x) {
            if (line[x] == 'o' || line[x] == 'O') {
                universe->addCell(x, y);
            }
        }
    }

    file.close();
    return universe;
}

void Universe::saveUniverse(std::string filepath) {
    std::ofstream file(filepath);

    std::cout << "Saving universe to " << filepath << "..." << std::endl;

    file << width << " " << height << std::endl;
    file << simulationStep << std::endl;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            Cell* cell = getCell(x, y);
            if (cell != nullptr) {
                file << "o";
            } else {
                file << ".";
            }
        }
        file << std::endl;
    }

    file.close();

    std::cout << "...Universe saved to " << filepath << std::endl;

}


void Universe::displayUniverse(std::string displayChar) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Cell* current = head;
            while (current != nullptr) {
                if (current->coordx == j && current->coordy == i) {
                    std::cout << displayChar;
                    break;
                }
                current = current->next;
            }
            if (current == nullptr) {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }
}

void Universe::addCell(int coordx, int coordy) {
    Cell* newCell = new Cell(coordx, coordy);
    newCell->next = head;
    head = newCell;
}

void Universe::removeCell(int coordx, int coordy) {
    Cell* current = head;
    Cell* previous = nullptr;
    while (current != nullptr) {
        if (current->coordx == coordx && current->coordy == coordy) {
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            break;
        }
        previous = current;
        current = current->next;
    }
}

Cell* Universe::getCell(int coordx, int coordy) {
    Cell* current = head;
    while (current != nullptr) {
        if (current->coordx == coordx && current->coordy == coordy) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

