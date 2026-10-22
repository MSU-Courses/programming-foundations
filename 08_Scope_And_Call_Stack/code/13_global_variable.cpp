#include <iostream>

int playerHealth = 50;

void heal() {
    playerHealth = playerHealth + 20;
}

int main() {
    heal();

    std::cout << playerHealth << '\n';

    return 0;
}
