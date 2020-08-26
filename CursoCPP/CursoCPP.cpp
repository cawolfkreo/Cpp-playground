#include <algorithm>
#include <iostream>
#include <limits>
#include <new>
#include <sstream>


int getNumInput() {
    int input{};

    while (true) {
        std::cout << "How many names would you like to enter? ";
        std::cin >> input;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.fail() || input < 1) {
            std::cin.clear();
            std::cout << "Please enter a valid positive number.\n";
        }
        else {
            break;
        }
    }

    return input;
}

std::string getName() {
    std::string name{};
    std::getline(std::cin, name);

    return name;
}

void loadNames(std::string *names, int size) {
    std::string inputName{};
    for (int i{ 0 }; i < size; ++i) {
        std::cout << "Enter name #" << i + 1 << ": ";
        inputName = getName();

        names[i] = inputName;
    }

    std::cout << '\n';
}

void printNames(std::string* names, int size) {
    std::cout << "Here is your sorted list:\n";
    for (int i{ 0 }; i < size; ++i) {
        std::cout << "Name #" << i + 1 << ": " << names[i] << '\n';
    }
}

int main() {
    int numNames{ getNumInput() };
    auto *names{ new std::string[numNames]{} };

    loadNames(names, numNames);

    std::sort(names, names + numNames);

    printNames(names, numNames);

    delete[] names;

    names = nullptr;

    return 0;
}