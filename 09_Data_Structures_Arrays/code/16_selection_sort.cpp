#include <iostream>

void printScores(int scores[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << scores[i] << ' ';
    }
    std::cout << '\n';
}

void sortDescending(int scores[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int best = i;

        for (int j = i + 1; j < size; j++) {
            if (scores[j] > scores[best]) {
                best = j;
            }
        }

        int temp = scores[i];
        scores[i] = scores[best];
        scores[best] = temp;
    }
}

int main() {
    const int PLAYERS = 5;
    int scores[PLAYERS] = {120, 95, 0, 210, 150};

    sortDescending(scores, PLAYERS);
    printScores(scores, PLAYERS);

    return 0;
}
