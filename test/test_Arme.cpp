#include <gtest/gtest.h>
#include "Arme.h"

TEST(ArmeTest, Construction) {
    Arme a("Épée", 10);
    EXPECT_EQ(a.getNom(), "Épée");
    EXPECT_EQ(a.getPuissanceBase(), 10);
    int bonus = a.getBonus();
    EXPECT_GE(bonus, 0);
    EXPECT_LE(bonus, 3);
    EXPECT_EQ(a.getPuissance(), 10 * bonus);
}

TEST(ArmeTest, Getters) {
    Arme a("Hache", 7);
    EXPECT_EQ(a.getNom(), "Hache");
    EXPECT_EQ(a.getPuissanceBase(), 7);
    int bonus = a.getBonus();
    EXPECT_GE(bonus, 0);
    EXPECT_LE(bonus, 3);
    EXPECT_EQ(a.getPuissance(), 7 * bonus);
}
