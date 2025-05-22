#pragma once

class SuperBonus {
public:
    SuperBonus();
    virtual ~SuperBonus(); // destructeur virtuel pour le polymorphisme
    SuperBonus(const SuperBonus& other); // constructeur de copie
    SuperBonus& operator=(const SuperBonus& other); // opérateur d'affectation
    virtual int getBonus() const; // virtual pour permettre le mock
private:
    int m_bonus;
};
