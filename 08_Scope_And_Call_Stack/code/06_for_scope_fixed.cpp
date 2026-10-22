#include <iostream>

int main() {
    int spawnedEnemies = 0;

    for (int enemy = 1; enemy <= 3; enemy = enemy + 1) {
        std::cout << "Enemy " << enemy << " spawned\n";
        spawnedEnemies = enemy;
    }

    std::cout << spawnedEnemies << '\n';

    return 0;
}
