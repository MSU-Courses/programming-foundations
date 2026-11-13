#include <iostream>

int main() {
    const int LEVELS = 5;
    int scores[LEVELS] = {120, 95, 0, 210, 150};

    int total = 0;
    int passed = 0;

    for (int i = 0; i < LEVELS; i++) {
        total = total + scores[i];

        if (scores[i] > 0) {
            passed++;
        }
    }

    std::cout << "Total: " << total << '\n';
    std::cout << "Passed: " << passed << " of " << LEVELS << '\n';

    return 0;
}
