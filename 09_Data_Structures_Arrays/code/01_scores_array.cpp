#include <iostream>

int main() {
    const int LEVELS = 5;
    int scores[LEVELS] = {120, 95, 0, 210, 150};

    std::cout << "Level 1: " << scores[0] << '\n';
    std::cout << "Level 5: " << scores[4] << '\n';

    scores[2] = 80;
    std::cout << "Level 3: " << scores[2] << '\n';

    return 0;
}
