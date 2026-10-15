#include <iostream>

int heal(int health) {
    return health + 20;
}

int main() {
    int playerHealth = 50;

    playerHealth = heal(playerHealth);

    std::cout << playerHealth << '\n';

    return 0;
}
