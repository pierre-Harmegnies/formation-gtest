#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Personnage.h"
#include "Arme.h"
#include "SuperBonus.h"

// Mock pour SuperBonus afin de contrôler la valeur du bonus dans les tests
class MockSuperBonus : public SuperBonus {
public:
    MOCK_METHOD(int, getBonus, (), (const, override));
};

// Arme mockée utilisant MockSuperBonus pour contrôler la puissance retournée
class MockArme : public Arme {
public:
    MockArme(const std::string& nom, int puissance, MockSuperBonus* bonus)
        : Arme(nom, puissance), m_mockBonus(bonus) {}

    // Redéfinition pour utiliser le bonus mocké
    int getPuissance() const override {
        int bonus = m_mockBonus->getBonus();        
        return getPuissanceBase() * bonus;
    }
    int getBonus() const override {
        return m_mockBonus->getBonus();
    }
private:
    MockSuperBonus* m_mockBonus;
};

// Adaptateur pour utiliser MockArme dans Personnage
class TestPersonnage : public Personnage {
public:
    TestPersonnage(const std::string& nom, int vie, int attaque, const Arme& arme)
        : Personnage(nom, vie, attaque, arme) {}
};

using ::testing::Return;

// Teste la construction d'un personnage avec une arme classique
TEST(PersonnageTest, Construction) {
    Arme arme("Arc", 8);
    Personnage p("Robin", 20, 5, arme);
    EXPECT_EQ(p.getNom(), "Robin");
    EXPECT_EQ(p.getVie(), 20);
    EXPECT_TRUE(p.estVivant());
}

// Teste l'attaque et la réception de dégâts avec des armes et bonus mockés
TEST(PersonnageTest, AttaqueEtDegatsAvecBonusMock) {
    MockSuperBonus bonus1;
    MockSuperBonus bonus2;
    // On force le bonus à 2 pour chaque arme
    EXPECT_CALL(bonus1, getBonus()).WillRepeatedly(Return(2));
    EXPECT_CALL(bonus2, getBonus()).WillRepeatedly(Return(2));

    MockArme arme1("Bâton", 2, &bonus1); // puissance = 2*2 = 4
    MockArme arme2("Dague", 1, &bonus2); // puissance = 1*2 = 2

    TestPersonnage p1("Mage", 10, 3, arme1);
    TestPersonnage p2("Voleur", 10, 2, arme2);

    std::cout << "Arme de p1 " << p1.getArme()->getNom() << std::endl;

    // Mage attaque Voleur : dégâts = 4 (puissance arme)
    EXPECT_EQ(p2.getVie(), 10);
    p1.attaquer(p2); 
    EXPECT_EQ(p2.getVie(), 3) << "La vie de p2 devrait être 3 après l'attaque de p1";

    // Voleur attaque Mage : dégâts = 2 (puissance arme)
    EXPECT_EQ(p1.getVie(), 10);
    p2.attaquer(p1);
    EXPECT_EQ(p1.getVie(), 6) << "La vie de p1 devrait être 6 après l'attaque de p1";

}

// Teste la mort d'un personnage après avoir reçu trop de dégâts
TEST(PersonnageTest, Mort) {
    Arme arme("Marteau", 10);
    Personnage p("Nain", 5, 2, arme);
    p.recevoirDegats(20);
    EXPECT_FALSE(p.estVivant());
    EXPECT_EQ(p.getVie(), 0);
}
