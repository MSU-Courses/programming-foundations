#include <iostream>
#include <string>

struct Item {
    std::string name;
    int price;
    int count;
};

int main() {
    Item potion = {"Potion", 25, 3};
    Item chestLoot = potion;

    chestLoot.count = 10;

    std::cout << potion.name << " x" << potion.count << '\n';
    std::cout << chestLoot.name << " x" << chestLoot.count << '\n';

    return 0;
}
