#include "Personnage.h"

Personnage::Personnage(const std::string& nom, int vie, int attaque, const Arme& arme)
    : m_nom(nom), m_vie(vie), m_attaque(attaque), m_arme(arme) {}

void Personnage::attaquer(Personnage& cible) {
    int degats = m_attaque + m_arme.getPuissance();
    cible.recevoirDegats(degats);
}

void Personnage::recevoirDegats(int degats) {
    m_vie -= degats;
    if (m_vie < 0) m_vie = 0;
}

bool Personnage::estVivant() const { return m_vie > 0; }
std::string Personnage::getNom() const { return m_nom; }
int Personnage::getVie() const { return m_vie; }