#include <iostream>

int calculateDamage(int attack, int defense) {
    int damage = attack - defense;

    if (damage < 1) {
        damage = 1;
    }

    return damage;
}

int countHits(int enemyHealth, int attack, int defense) {
    int hits = 0;

    while (enemyHealth > 0) {
        enemyHealth = enemyHealth - calculateDamage(attack, defense);
        hits = hits + 1;
    }

    return hits;
}

int main() {
    const int ENEMY_HEALTH = 100;
    int heroAttack = 30;
    int enemyDefense = 10;

    int hits = countHits(ENEMY_HEALTH, heroAttack, enemyDefense);

    std::cout << "Hits: " << hits << '\n';

    return 0;
}
