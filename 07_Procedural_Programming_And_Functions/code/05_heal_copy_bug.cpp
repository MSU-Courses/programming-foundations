#include <iostream>

void heal(int health) {
    health = health + 20;
}

int main() {
    int playerHealth = 50;

    heal(playerHealth);

    std::cout << playerHealth << '\n';

    return 0;
}
