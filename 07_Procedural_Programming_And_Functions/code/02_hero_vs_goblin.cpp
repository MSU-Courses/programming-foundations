#include <iostream>

int calculateDamage(int attack, int defense) {
    int damage = attack - defense;

    if (damage < 1) {
        damage = 1;
    }

    return damage;
}

int main() {
    int heroHealth = 100;
    int heroAttack = 30;
    int heroDefense = 12;

    int goblinHealth = 60;
    int goblinAttack = 15;
    int goblinDefense = 10;

    goblinHealth = goblinHealth - calculateDamage(heroAttack, goblinDefense);
    heroHealth = heroHealth - calculateDamage(goblinAttack, heroDefense);

    std::cout << "Goblin health: " << goblinHealth << '\n';
    std::cout << "Hero health: " << heroHealth << '\n';

    return 0;
}
