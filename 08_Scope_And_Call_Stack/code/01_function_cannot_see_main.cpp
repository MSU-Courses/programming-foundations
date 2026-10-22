#include <iostream>

int countHits(int damage) {
    int health = ENEMY_HEALTH;
    int hits = 0;

    while (health > 0) {
        health = health - damage;
        hits = hits + 1;
    }

    return hits;
}

int main() {
    const int ENEMY_HEALTH = 100;

    std::cout << countHits(30) << '\n';

    return 0;
}
