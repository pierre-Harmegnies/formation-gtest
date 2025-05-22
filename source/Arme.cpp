#include "Arme.h"

Arme::Arme(const std::string& nom, int puissance)
    : m_nom(nom), m_puissance(puissance), m_bonus() {}

Arme::~Arme() = default;

Arme::Arme(const Arme& other)
    : m_nom(other.m_nom), m_puissance(other.m_puissance), m_bonus(other.m_bonus) {}

Arme& Arme::operator=(const Arme& other) {
    if (this != &other) {
        m_nom = other.m_nom;
        m_puissance = other.m_puissance;
        m_bonus = other.m_bonus;
    }
    return *this;
}

std::string Arme::getNom() const { return m_nom; }

int Arme::getPuissance() const {
    return m_puissance * m_bonus.getBonus();
}

int Arme::getPuissanceBase() const {
    return m_puissance;
}

int Arme::getBonus() const {
    return m_bonus.getBonus();
}