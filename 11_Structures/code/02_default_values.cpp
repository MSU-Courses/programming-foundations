#include <iostream>
#include <string>

struct Item {
    std::string name = "Empty";
    int price = 0;
    int count = 0;
};

int main() {
    Item slot;
    Item sword = {"Sword", 120};

    std::cout << slot.name << ' ' << slot.price << ' ' << slot.count << '\n';
    std::cout << sword.name << ' ' << sword.price << ' ' << sword.count << '\n';

    return 0;
}
