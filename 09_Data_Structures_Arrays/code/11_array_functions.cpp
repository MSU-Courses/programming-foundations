#include <iostream>

void printScores(int scores[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "Level " << i + 1 << ": " << scores[i] << '\n';
    }
}

int totalScore(int scores[], int size) {
    int total = 0;

    for (int i = 0; i < size; i++) {
        total = total + scores[i];
    }

    return total;
}

int main() {
    const int LEVELS = 5;
    int scores[LEVELS] = {120, 95, 0, 210, 150};

    printScores(scores, LEVELS);
    std::cout << "Total: " << totalScore(scores, LEVELS) << '\n';

    return 0;
}
