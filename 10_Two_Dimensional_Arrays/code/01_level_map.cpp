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

    std::cout << map[1][2] << '\n';
    std::cout << map[2][4] << '\n';

    map[1][2] = '.';

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            std::cout << map[row][col];
        }
        std::cout << '\n';
    }

    return 0;
}
