#include <iostream>

int calculateDamage(int attack, int defense) {
    if (attack > defense) {
        return attack - defense;
    }

    return 1;
}

int main() {
    std::cout << calculateDamage(30, 10) << '\n';
    std::cout << calculateDamage(10, 15) << '\n';

    return 0;
}
