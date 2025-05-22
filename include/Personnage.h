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
    const Arme* getArme() const;  // Correction du type de retour
private:
    std::string m_nom;
    int m_vie;
    int m_attaque;
    const Arme* m_arme; // Changement ici : pointeur constant vers Arme
};
