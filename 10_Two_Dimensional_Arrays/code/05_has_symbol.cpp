#include <iostream>

const int ROWS = 4;
const int COLS = 6;

bool hasSymbol(char map[][COLS], int rows, char symbol) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < COLS; col++) {
            if (map[row][col] == symbol) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    char map[ROWS][COLS] = {
        {'#', '#', '#', '#', '#', '#'},
        {'#', '.', 'C', '.', '.', '#'},
        {'#', '.', '#', 'C', 'E', '#'},
        {'#', '#', '#', '#', '#', '#'}
    };

    std::cout << hasSymbol(map, ROWS, 'E') << '\n';
    std::cout << hasSymbol(map, ROWS, 'K') << '\n';

    return 0;
}
