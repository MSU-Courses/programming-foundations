#include <iostream>

int findItem(char bag[], int count, char item) {
    for (int i = 0; i < count; i++) {
        if (bag[i] == item) {
            return i;
        }
    }

    return -1;
}

int main() {
    char bag[4] = {'S', 'P', 'K', 'P'};

    std::cout << findItem(bag, 4, 'K') << '\n';
    std::cout << findItem(bag, 4, 'G') << '\n';

    int key = findItem(bag, 4, 'K');

    if (key != -1) {
        std::cout << "The door opens\n";
    } else {
        std::cout << "You need a key\n";
    }

    return 0;
}
