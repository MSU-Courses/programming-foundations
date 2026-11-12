#include <iostream>

int main() {
    const int LEVELS = 2;
    const int ROWS = 3;
    const int COLS = 5;

    char dungeon[LEVELS][ROWS][COLS] = {
        {
            {'#', '#', '#', '#', '#'},
            {'#', 'C', '.', 'S', '#'},
            {'#', '#', '#', '#', '#'}
        },
        {
            {'#', '#', '#', '#', '#'},
            {'#', 'S', 'C', 'E', '#'},
            {'#', '#', '#', '#', '#'}
        }
    };

    std::cout << dungeon[1][1][3] << '\n';

    int coins = 0;

    for (int level = 0; level < LEVELS; level++) {
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                if (dungeon[level][row][col] == 'C') {
                    coins++;
                }
            }
        }
    }

    std::cout << "Coins in the dungeon: " << coins << '\n';

    return 0;
}
