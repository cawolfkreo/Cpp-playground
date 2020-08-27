#include "linkedList.h"
#include "stringArr.h"
#include <iostream>
#include <string>
#include <sstream>

namespace constants {
    // The miminum possible value, currently for demo options.
    constexpr int MIN_OPTION{ 1 };
    // The maximum possible value, currently for demo options.
    constexpr int MAX_OPTION{ 2 };
}

// Prints the main options for this program on the console.
void mainPrompt(int min, int max) {
    std::cout << "Please choose one of the demos listed bellow to interact with it:\n";
    std::cout << "\t 1. create a list of names and show them sorted.\n";
    std::cout << "\t 2. A linked list of numbers you can do some operations with.\n";
    std::cout << "your selection (" << min << "-" << max <<"): ";
}

// Gets the demo selected by the user from the console.
int userSelectedDemo(int min, int max) {
    int demoSelected{ -1 };

    while ( true ) {
        std::cin >> demoSelected;       

        if (std::cin.fail() || demoSelected < min || demoSelected > max) {              // If reading from input fails or an invalid option is
            std::cin.clear();                                                           // given by the user the error flag will be toggle and
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');         // the input buffer will be cleaned from any extra characters
            std::cout << "You entered an incorrected option!\n";                        // and an error message will be show to the user.
            std::cout << "Please provide me with a correct number :C\n";

            mainPrompt(min, max);                                                       // The main prompt will be displayed again in case
                                                                                        // the user needs to read the options again.
        }
        else {
            break;                                                                      // If there was no error and everything went well, we
                                                                                        // break from the loop and
        }
    }

    return demoSelected;                                                                // we return the option the user gave.
}


// Runs the demo the user previously selected.
void runSelectedDemo(int demo) {
    std::cout << '\n';                                                                  //Line break to make the prompts of the demos more clear.

    switch (demo) {
    case 1:
        stringArr::mainDemo();
        break;
    case 2:
        linkedList::mainDemo();
        break;
    default:
        break;
    }
}

int main() {

    std::cout << "Welcome to the main demo of my C++ repository!!\n\n";

    mainPrompt(constants::MIN_OPTION, constants::MAX_OPTION);

    int userDemoSelected{ userSelectedDemo(constants::MIN_OPTION, constants::MAX_OPTION) };

    /*
    * The input buffer is cleaned in case there are any invalid characters
    * on it that we need to ignore, before we execute any of the demos.
    */
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    runSelectedDemo( userDemoSelected );

    return 0;
}