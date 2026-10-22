#include <iostream>

int main() {
    for (int wave = 1; wave <= 3; wave = wave + 1) {
        int enemy = 1;

        while (enemy <= 2) {
            std::cout << "Wave " << wave << ", enemy " << enemy << '\n';
            enemy = enemy + 1;
        }
    }

    return 0;
}
