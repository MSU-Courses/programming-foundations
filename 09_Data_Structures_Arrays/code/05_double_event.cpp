#include <iostream>

int main() {
    const int LEVELS = 5;
    int scores[LEVELS] = {120, 95, 0, 210, 150};

    for (int i = 0; i < LEVELS; i++) {
        scores[i] = scores[i] * 2;
    }

    for (int i = 0; i < LEVELS; i++) {
        std::cout << scores[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}
