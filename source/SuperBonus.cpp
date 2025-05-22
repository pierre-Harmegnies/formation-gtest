#include "SuperBonus.h"
#include <cstdlib>
#include <ctime>

SuperBonus::SuperBonus() {
    static bool seeded = false;
    if (!seeded) {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        seeded = true;
    }
    m_bonus = std::rand() % 4; // 0, 1, 2, 3
}

SuperBonus::SuperBonus(const SuperBonus& other) : m_bonus(other.m_bonus) {}

SuperBonus& SuperBonus::operator=(const SuperBonus& other) {
    if (this != &other) {
        m_bonus = other.m_bonus;
    }
    return *this;
}

SuperBonus::~SuperBonus() = default;

int SuperBonus::getBonus() const {
    return m_bonus;
}
