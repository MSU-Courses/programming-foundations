#include <iostream>

int calculateDamage(int attack, int defense) {
    if (attack - defense < 1) {
        return 1;
    }

    return attack - defense;
}

int main() {
    std::cout << calculateDamage(30, 10) << '\n';
    std::cout << calculateDamage(11, 10) << '\n';
    std::cout << calculateDamage(10, 10) << '\n';
    std::cout << calculateDamage(5, 12) << '\n';

    return 0;
}
