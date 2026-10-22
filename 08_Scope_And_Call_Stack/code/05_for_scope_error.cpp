#include <iostream>

int main() {
    for (int enemy = 1; enemy <= 3; enemy = enemy + 1) {
        std::cout << "Enemy " << enemy << " spawned\n";
    }

    std::cout << enemy << '\n';

    return 0;
}
