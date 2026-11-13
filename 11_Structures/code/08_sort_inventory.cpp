#include <iostream>
#include <string>

struct Item {
    std::string name;
    int price;
    int count;
};

void printInventory(Item items[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << items[i].name << " - " << items[i].price << '\n';
    }
}

void sortByPrice(Item items[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int cheapest = i;

        for (int j = i + 1; j < size; j++) {
            if (items[j].price < items[cheapest].price) {
                cheapest = j;
            }
        }

        Item temp = items[i];
        items[i] = items[cheapest];
        items[cheapest] = temp;
    }
}

int main() {
    const int SIZE = 4;
    Item shop[SIZE] = {
        {"Sword", 120, 1},
        {"Potion", 25, 3},
        {"Arrow", 2, 40},
        {"Shield", 80, 1}
    };

    sortByPrice(shop, SIZE);
    printInventory(shop, SIZE);

    return 0;
}
