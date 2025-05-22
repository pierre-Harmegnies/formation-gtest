#include <iostream>
#include "Personnage.h"
#include "Arme.h"
#include "De.h"

int main() {
    Arme epee("Épée", 5);
    Arme hache("Hache", 7);

    Personnage joueur("Héros", 30, 3, epee);
    Personnage ennemi("Orc", 25, 4, hache);

    De de(6);

    std::cout << "Début du combat !" << std::endl;
    while (joueur.estVivant() && ennemi.estVivant()) {
        if (de.lancer() > 3) {
            joueur.attaquer(ennemi);
            std::cout << joueur.getNom() << " attaque " << ennemi.getNom()
                      << " (vie restante: " << ennemi.getVie() << ")" << std::endl;
        } else {
            ennemi.attaquer(joueur);
            std::cout << ennemi.getNom() << " attaque " << joueur.getNom()
                      << " (vie restante: " << joueur.getVie() << ")" << std::endl;
        }
    }
    if (joueur.estVivant())
        std::cout << joueur.getNom() << " a gagné !" << std::endl;
    else
        std::cout << ennemi.getNom() << " a gagné !" << std::endl;

    return 0;
}
