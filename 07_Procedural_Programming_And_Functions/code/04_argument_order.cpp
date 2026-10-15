#include <iostream>

int calculateDamage(int attack, int defense) {
    int damage = attack - defense;

    if (damage < 1) {
        damage = 1;
    }

    return damage;
}

int main() {
    int loss1 = calculateDamage(30, 10);
    int loss2 = calculateDamage(10, 30);

    std::cout << loss1 << '\n';
    std::cout << loss2 << '\n';

    return 0;
}
