#include <iostream>

void printScores(int scores[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << scores[i] << ' ';
    }
    std::cout << '\n';
}

void bubbleSortDescending(int scores[], int size) {
    for (int pass = 0; pass < size - 1; pass++) {
        for (int j = 0; j < size - 1 - pass; j++) {
            if (scores[j] < scores[j + 1]) {
                int temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int PLAYERS = 5;
    int scores[PLAYERS] = {120, 95, 0, 210, 150};

    bubbleSortDescending(scores, PLAYERS);
    printScores(scores, PLAYERS);

    return 0;
}
