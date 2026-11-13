#include <iostream>

int main() {
    const int LEVELS = 5;
    int scores[LEVELS] = {120, 95, 0, 210, 150};

    int level = 0;
    std::cout << "Level number: ";
    std::cin >> level;

    std::cout << "Score: " << scores[level - 1] << '\n';

    return 0;
}
