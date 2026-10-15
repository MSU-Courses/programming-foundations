#include <iostream>

int readDamage() {
    int damage = 0;

    do {
        std::cout << "Damage (greater than 0): ";
        std::cin >> damage;

        if (damage <= 0) {
            std::cout << "Damage must be greater than 0\n";
        }
    } while (damage <= 0);

    return damage;
}

int countHits(int health, int damage) {
    int hits = 0;

    while (health > 0) {
        health = health - damage;
        hits = hits + 1;
    }

    return hits;
}

void showWaveCleared(int wave, int hits) {
    std::cout << "Wave " << wave << " cleared, hits: " << hits << '\n';
}

int main() {
    const int WAVES = 3;
    const int ENEMY_HEALTH = 100;

    int damage = readDamage();
    int totalHits = 0;

    for (int wave = 1; wave <= WAVES; wave = wave + 1) {
        int hits = countHits(ENEMY_HEALTH, damage);
        totalHits = totalHits + hits;

        showWaveCleared(wave, hits);
    }

    std::cout << "Total hits: " << totalHits << '\n';

    return 0;
}
