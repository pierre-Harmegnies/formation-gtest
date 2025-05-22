#pragma once
#include <string>
#include "Arme.h"

class Personnage {
public:
    Personnage(const std::string& nom, int vie, int attaque, const Arme& arme);
    void attaquer(Personnage& cible);
    void recevoirDegats(int degats);
    bool estVivant() const;
    std::string getNom() const;
    int getVie() const;
private:
    std::string m_nom;
    int m_vie;
    int m_attaque;
    Arme m_arme;
};
