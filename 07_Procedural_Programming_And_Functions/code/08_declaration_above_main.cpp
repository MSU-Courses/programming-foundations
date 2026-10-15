#include <iostream>

int calculateDamage(int attack, int defense);

int main() {
    std::cout << calculateDamage(30, 10) << '\n';

    return 0;
}

int calculateDamage(int attack, int defense) {
    int damage = attack - defense;

    if (damage < 1) {
        damage = 1;
    }

    return damage;
}
