#include <iostream>

int main() {
    const int LEVELS = 5;
    int scores[LEVELS] = {};

    for (int i = 0; i < LEVELS; i++) {
        std::cout << "Level " << i + 1 << " score: ";
        std::cin >> scores[i];
    }

    for (int i = 0; i < LEVELS; i++) {
        std::cout << scores[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}
