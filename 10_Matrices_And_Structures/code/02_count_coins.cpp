#include <iostream>

int main() {
    const int ROWS = 4;
    const int COLS = 6;

    char map[ROWS][COLS] = {
        {'#', '#', '#', '#', '#', '#'},
        {'#', '.', 'C', '.', '.', '#'},
        {'#', '.', '#', 'C', 'E', '#'},
        {'#', '#', '#', '#', '#', '#'}
    };

    int coins = 0;

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (map[row][col] == 'C') {
                coins++;
            }
        }
    }

    std::cout << "Coins on the map: " << coins << '\n';

    return 0;
}
