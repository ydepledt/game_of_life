#include "Universe.hpp"

Universe::~Universe() {
    Cell* current = head;
    while (current != nullptr) {
        Cell* next = current->next;
        delete current;
        current = next;
    }
}

void Universe::displayUniverse() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Cell* current = head;
            while (current != nullptr) {
                if (current->coordx == j && current->coordy == i) {
                    std::cout << "X";
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

