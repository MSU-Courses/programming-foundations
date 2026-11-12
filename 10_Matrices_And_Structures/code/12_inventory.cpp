#include <iostream>
#include <string>

struct Item {
    std::string name;
    int price;
    int count;
};

void printInventory(Item items[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << i + 1 << ". " << items[i].name << " x" << items[i].count
                  << " (" << items[i].price << " coins)\n";
    }
}

int inventoryValue(Item items[], int size) {
    int total = 0;

    for (int i = 0; i < size; i++) {
        total = total + items[i].price * items[i].count;
    }

    return total;
}

int findItem(Item items[], int size, std::string name) {
    for (int i = 0; i < size; i++) {
        if (items[i].name == name) {
            return i;
        }
    }

    return -1;
}

int main() {
    const int SIZE = 4;
    Item inventory[SIZE] = {
        {"Sword", 120, 1},
        {"Potion", 25, 3},
        {"Arrow", 2, 40},
        {"Shield", 80, 1}
    };

    printInventory(inventory, SIZE);
    std::cout << "Value: " << inventoryValue(inventory, SIZE) << " coins\n";

    int index = findItem(inventory, SIZE, "Potion");

    if (index != -1) {
        inventory[index].count--;
        std::cout << "Potions left: " << inventory[index].count << '\n';
    }

    return 0;
}
