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

    int exitRow = -1;
    int exitCol = -1;

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (map[row][col] == 'E') {
                exitRow = row;
                exitCol = col;
            }
        }
    }

    std::cout << "Exit: row " << exitRow << ", column " << exitCol << '\n';

    return 0;
}
