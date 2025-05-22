#include "De.h"
#include <cstdlib>
#include <ctime>

De::De(int faces) : m_faces(faces) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

int De::lancer() const {
    return (std::rand() % m_faces) + 1;
}