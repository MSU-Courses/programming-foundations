#include <iostream>
#include <string>

struct Item {
    std::string name;
    int price;
    int count;
};

int main() {
    Item potion = {"Potion", 25, 3};

    std::cout << potion.name << ": " << potion.price << " coins, x" << potion.count << '\n';

    potion.count--;
    std::cout << "Left: " << potion.count << '\n';

    return 0;
}
