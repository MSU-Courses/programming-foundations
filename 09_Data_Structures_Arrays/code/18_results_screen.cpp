#include <iostream>

void printScores(int scores[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "Level " << i + 1 << ": ";

        if (scores[i] > 0) {
            std::cout << scores[i] << '\n';
        } else {
            std::cout << "not passed\n";
        }
    }
}

int totalScore(int scores[], int size) {
    int total = 0;

    for (int i = 0; i < size; i++) {
        total = total + scores[i];
    }

    return total;
}

int countPassed(int scores[], int size) {
    int passed = 0;

    for (int i = 0; i < size; i++) {
        if (scores[i] > 0) {
            passed++;
        }
    }

    return passed;
}

int findBest(int scores[], int size) {
    int best = 0;

    for (int i = 1; i < size; i++) {
        if (scores[i] > scores[best]) {
            best = i;
        }
    }

    return best;
}

int findFirstNotPassed(int scores[], int size) {
    for (int i = 0; i < size; i++) {
        if (scores[i] == 0) {
            return i;
        }
    }

    return -1;
}

int main() {
    const int LEVELS = 5;
    int scores[LEVELS] = {120, 95, 0, 210, 150};

    printScores(scores, LEVELS);

    std::cout << "Total: " << totalScore(scores, LEVELS) << '\n';
    std::cout << "Passed: " << countPassed(scores, LEVELS) << " of " << LEVELS << '\n';
    std::cout << "Best level: " << findBest(scores, LEVELS) + 1 << '\n';

    int next = findFirstNotPassed(scores, LEVELS);

    if (next != -1) {
        std::cout << "Continue from level " << next + 1 << '\n';
    } else {
        std::cout << "All levels passed\n";
    }

    return 0;
}
