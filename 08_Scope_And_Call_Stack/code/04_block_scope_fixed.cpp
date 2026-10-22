#include <iostream>

int main() {
    int health = 30;
    int bonus = 0;

    if (health < 50) {
        bonus = 20;
        health = health + bonus;
    }

    std::cout << health << '\n';
    std::cout << bonus << '\n';

    return 0;
}
