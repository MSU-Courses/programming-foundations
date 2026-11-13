#include <iostream>

int findItem(char bag[], int count, char item) {
    for (int i = 0; i < count; i++) {
        if (bag[i] == item) {
            return i;
        } else {
            return -1;
        }
    }

    return -1;
}

int main() {
    char bag[4] = {'S', 'P', 'K', 'P'};

    std::cout << findItem(bag, 4, 'K') << '\n';

    return 0;
}
