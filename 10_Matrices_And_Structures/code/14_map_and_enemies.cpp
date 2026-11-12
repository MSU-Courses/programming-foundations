#include <iostream>

const int ROWS = 4;
const int COLS = 6;

struct Position {
    int row;
    int col;
};

struct Enemy {
    char symbol;
    int health;
    Position pos;
};

int findEnemyAt(Enemy enemies[], int count, Position cell) {
    for (int i = 0; i < count; i++) {
        if (enemies[i].health > 0 &&
            enemies[i].pos.row == cell.row &&
            enemies[i].pos.col == cell.col) {
            return i;
        }
    }

    return -1;
}

void printMap(char map[][COLS], int rows, Position player, Enemy enemies[], int count) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < COLS; col++) {
            Position cell = {row, col};
            int enemy = findEnemyAt(enemies, count, cell);

            if (row == player.row && col == player.col) {
                std::cout << '@';
            } else if (enemy != -1) {
                std::cout << enemies[enemy].symbol;
            } else {
                std::cout << map[row][col];
            }
        }
        std::cout << '\n';
    }
}

int main() {
    char map[ROWS][COLS] = {
        {'#', '#', '#', '#', '#', '#'},
        {'#', '.', 'C', '.', '.', '#'},
        {'#', '.', '#', 'C', 'E', '#'},
        {'#', '#', '#', '#', '#', '#'}
    };

    const int ENEMIES = 2;
    Enemy enemies[ENEMIES] = {
        {'G', 30, {1, 3}},
        {'O', 50, {2, 1}}
    };

    Position player = {1, 1};

    printMap(map, ROWS, player, enemies, ENEMIES);

    Position target = {player.row + 1, player.col};
    int index = findEnemyAt(enemies, ENEMIES, target);

    if (index != -1) {
        enemies[index].health = enemies[index].health - 20;
        std::cout << "Hit " << enemies[index].symbol
                  << ", health left: " << enemies[index].health << '\n';
    } else {
        std::cout << "Nobody there\n";
    }

    return 0;
}
