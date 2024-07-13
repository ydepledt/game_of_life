// #include "Cell.hpp"

// void Cell::addCell(int coordx, int coordy) {
//     if (next == nullptr) {
//         next = new Cell(coordx, coordy);
//     } else {
//         next->addCell(coordx, coordy);
//     }
// };

// void Cell::removeCell(int coordx, int coordy) {
//     if (next != nullptr) {
//         if (next->coordx == coordx && next->coordy == coordy) {
//             Cell* temp = next;
//             next = next->next;
//             delete temp;
//         } else {
//             next->removeCell(coordx, coordy);
//         }
//     }
// };

// Cell* Cell::getCell(int coordx, int coordy) {
//     if (this->coordx == coordx && this->coordy == coordy) {
//         return this;
//     } else if (next != nullptr) {
//             return next->getCell(coordx, coordy);
//     } else {
//             return nullptr;
//     }
// };