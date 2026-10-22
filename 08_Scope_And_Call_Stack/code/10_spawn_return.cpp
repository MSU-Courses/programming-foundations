#include <iostream>

int spawnEnemy(int spawned) {
    spawned = spawned + 1;
    std::cout << "Spawned: " << spawned << '\n';

    return spawned;
}

int main() {
    int spawned = 0;

    spawned = spawnEnemy(spawned);
    spawned = spawnEnemy(spawned);
    spawned = spawnEnemy(spawned);

    return 0;
}
