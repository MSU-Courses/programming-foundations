#include <iostream>

int countHits(int health, int damage) {
    int hits = 0;

    while (health > 0) {
        health = health - damage;
        hits = hits + 1;
    }

    return hits;
}

int main() {
    int totalHits = 0;

    for (int wave = 1; wave <= 3; wave = wave + 1) {
        totalHits = totalHits + countHits(100, 30);
    }

    std::cout << "Total hits: " << totalHits << '\n';

    return 0;
}
