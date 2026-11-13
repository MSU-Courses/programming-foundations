#include <iostream>

const int ROWS = 4;
const int COLS = 6;

struct Position {
    int row;
    int col;
};

Position findSymbol(char map[][COLS], int rows, char symbol) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < COLS; col++) {
            if (map[row][col] == symbol) {
                return {row, col};
            }
        }
    }

    return {-1, -1};
}

int main() {
    char map[ROWS][COLS] = {
        {'#', '#', '#', '#', '#', '#'},
        {'#', '.', 'C', '.', '.', '#'},
        {'#', '.', '#', 'C', 'E', '#'},
        {'#', '#', '#', '#', '#', '#'}
    };

    Position exitPos = findSymbol(map, ROWS, 'E');
    std::cout << "Exit: row " << exitPos.row << ", column " << exitPos.col << '\n';

    Position key = findSymbol(map, ROWS, 'K');

    if (key.row == -1) {
        std::cout << "No key on this level\n";
    }

    return 0;
}
