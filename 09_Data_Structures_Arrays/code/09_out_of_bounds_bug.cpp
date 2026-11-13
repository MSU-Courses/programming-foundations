#include <iostream>

int main() {
    const int LEVELS = 5;
    int scores[LEVELS] = {120, 95, 0, 210, 150};

    for (int i = 0; i <= LEVELS; i++) {
        std::cout << "Level " << i + 1 << ": " << scores[i] << '\n';
    }

    return 0;
}
