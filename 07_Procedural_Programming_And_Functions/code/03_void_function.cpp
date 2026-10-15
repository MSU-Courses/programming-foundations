#include <iostream>

void showWaveCleared(int wave, int hits) {
    std::cout << "Wave " << wave << " cleared, hits: " << hits << '\n';
}

int main() {
    showWaveCleared(1, 4);
    showWaveCleared(2, 5);

    return 0;
}
