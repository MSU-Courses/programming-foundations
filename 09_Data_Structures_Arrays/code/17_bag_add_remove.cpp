#include <iostream>

void printBag(char bag[], int count) {
    for (int i = 0; i < count; i++) {
        std::cout << bag[i] << ' ';
    }
    std::cout << "(" << count << " items)\n";
}

int main() {
    const int CAPACITY = 6;
    char bag[CAPACITY] = {'S', 'P', 'K', 'P'};
    int count = 4;

    printBag(bag, count);

    // Игрок выпил зелье из второй ячейки (индекс 1).
    int index = 1;
    if (index >= 0 && index < count) {
        for (int i = index; i < count - 1; i++) {
            bag[i] = bag[i + 1];
        }
        count--;
    }
    printBag(bag, count);

    // Игрок подобрал драгоценный камень.
    if (count < CAPACITY) {
        bag[count] = 'G';
        count++;
    } else {
        std::cout << "The bag is full\n";
    }
    printBag(bag, count);

    // Игрок положил амулет в первую ячейку (индекс 0).
    index = 0;
    if (count < CAPACITY) {
        for (int i = count; i > index; i--) {
            bag[i] = bag[i - 1];
        }
        bag[index] = 'A';
        count++;
    }
    printBag(bag, count);

    return 0;
}
