#include <iostream>

void spawnEnemy() {
    int spawned = 0;
    spawned = spawned + 1;
    std::cout << "Spawned: " << spawned << '\n';
}

int main() {
    spawnEnemy();
    spawnEnemy();
    spawnEnemy();

    return 0;
}
