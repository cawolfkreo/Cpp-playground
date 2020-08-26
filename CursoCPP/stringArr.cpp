#include "stringArr.h"
#include <algorithm>
#include <iostream>
#include <limits>
#include <new>
#include <sstream>


namespace stringArr {

    //Gets the number of names the user is going to provide from console.
    int getNumInput() {
        int input{};

        while (true) {
            std::cout << "How many names would you like to enter? ";
            std::cin >> input;

            if (std::cin.fail() || input < 1) {                                                 // If the user provides an invalid input or std::cin fails to save
                std::cin.clear();                                                               // the user input in our variable. We need to clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');             // Remove any extra characters on the input buffer and we tell the
                std::cout << "Please enter a valid positive number.\n";                         // user he made a mistake and needs to enter his input again.
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');             // If the input went correctly we still need to make sure no invalid
                return input;                                                                   // characters were stored in the buffer before returning the user input
            }
        }
    }

    // Gets a single name from the user.
    std::string getName() {
        std::string name{};
        std::getline(std::cin, name);

        return name;
    }

    //Saves all the names into an array of std::string (an array of strings).
    void loadNames(std::string* names, int size) {
        std::string inputName{};
        for (int i{ 0 }; i < size; ++i) {
            std::cout << "Enter name #" << i + 1 << ": ";
            inputName = getName();

            names[i] = inputName;
        }

        std::cout << '\n';
    }

    // Prints all the names inside the array of std::string (an array of strings).
    void printNames(std::string* names, int size) {
        std::cout << "Here is your sorted list:\n";
        for (int i{ 0 }; i < size; ++i) {
            std::cout << "Name #" << i + 1 << ": " << names[i] << '\n';
        }
    }

    // Runs the demo inside of this program.
    void mainDemo() {
        int numNames{ getNumInput() };
        auto* names{ new std::string[numNames]{} };

        loadNames(names, numNames);

        //Sorts the list of names.
        std::sort(names, names + numNames);

        printNames(names, numNames);

        //When the demo is finished, the memory used by the array is "cleaned" by deleting it.
        delete[] names;
        /*
        * In order to avoid any undefined behaviour by manipulating any dangling 
        * pointers ee set this pointer to "nullptr" after we delete the array of names.
        */
        names = nullptr;
    }
}