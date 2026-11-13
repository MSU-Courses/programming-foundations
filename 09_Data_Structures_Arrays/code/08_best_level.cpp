#include <iostream>

int main() {
    const int LEVELS = 5;
    int scores[LEVELS] = {120, 95, 0, 210, 150};

    int best = 0;

    for (int i = 1; i < LEVELS; i++) {
        if (scores[i] > scores[best]) {
            best = i;
        }
    }

    std::cout << "Best level: " << best + 1 << '\n';
    std::cout << "Score: " << scores[best] << '\n';

    return 0;
}
