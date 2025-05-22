#pragma once
#include <string>
#include "SuperBonus.h"

class Arme {
public:
    Arme(const std::string& nom, int puissance);
    virtual ~Arme();
    Arme(const Arme& other); // constructeur de copie
    Arme& operator=(const Arme& other); // opérateur d'affectation
    virtual std::string getNom() const;
    virtual int getPuissance() const;
    virtual int getPuissanceBase() const;
    virtual int getBonus() const;
protected:
    std::string m_nom;
    int m_puissance;
    SuperBonus m_bonus;
};
