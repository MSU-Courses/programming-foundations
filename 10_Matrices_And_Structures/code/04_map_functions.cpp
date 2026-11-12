#include <iostream>

const int ROWS = 4;
const int COLS = 6;

void printMap(char map[][COLS], int rows, int playerRow, int playerCol) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < COLS; col++) {
            if (row == playerRow && col == playerCol) {
                std::cout << '@';
            } else {
                std::cout << map[row][col];
            }
        }
        std::cout << '\n';
    }
}

bool canMoveTo(char map[][COLS], int rows, int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= COLS) {
        return false;
    }

    return map[row][col] != '#';
}

int main() {
    char map[ROWS][COLS] = {
        {'#', '#', '#', '#', '#', '#'},
        {'#', '.', 'C', '.', '.', '#'},
        {'#', '.', '#', 'C', 'E', '#'},
        {'#', '#', '#', '#', '#', '#'}
    };

    int playerRow = 1;
    int playerCol = 1;

    printMap(map, ROWS, playerRow, playerCol);

    std::cout << canMoveTo(map, ROWS, playerRow, playerCol + 1) << '\n';
    std::cout << canMoveTo(map, ROWS, playerRow - 1, playerCol) << '\n';
    std::cout << canMoveTo(map, ROWS, 5, 1) << '\n';

    return 0;
}
