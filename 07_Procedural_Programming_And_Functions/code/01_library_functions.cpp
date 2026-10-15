#include <algorithm>
#include <cstdlib>
#include <iostream>

int main() {
    int heroX = 4;
    int goblinX = 11;

    std::cout << std::abs(heroX - goblinX) << '\n';
    std::cout << std::max(30 - 35, 1) << '\n';
    std::cout << std::min(90 + 20, 100) << '\n';

    return 0;
}
