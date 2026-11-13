#include <iostream>

void doubleScore(int score) {
    score = score * 2;
}

void doubleScores(int scores[], int size) {
    for (int i = 0; i < size; i++) {
        scores[i] = scores[i] * 2;
    }
}

int main() {
    const int LEVELS = 5;
    int scores[LEVELS] = {120, 95, 0, 210, 150};
    int bonus = 50;

    doubleScore(bonus);
    doubleScores(scores, LEVELS);

    std::cout << "Bonus: " << bonus << '\n';
    std::cout << "Level 1: " << scores[0] << '\n';

    return 0;
}
