#include <iostream>
#include <string>

struct Item {
    std::string name;
    int price;
    int count;
};

Item useItem(Item item) {
    if (item.count > 0) {
        item.count--;
    }

    return item;
}

int main() {
    Item potion = {"Potion", 25, 3};

    potion = useItem(potion);
    std::cout << potion.name << " x" << potion.count << '\n';

    return 0;
}
