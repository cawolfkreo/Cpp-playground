#include "linkedList.h"
#include "linkedNum.h"
#include <iostream>
#include <new>
#include <string>

namespace linkedList {

	namespace constants {
		// The miminum possible value currently, for list interaction.
		constexpr int MIN_OPTION{ 1 };
		// The maximum possible value currently, for list interactionn.
		constexpr int MAX_OPTION{ 5 };
	}

	/*
	Gets a number from the user input. If the user enters an invalid option,
	the question passed by parameter will be displayed on the console.
	*/
	int getNumber(std::string inputQuestion) {
		int userNumber{ -1 };
		bool foundErrors{ false };

		while (true) {
			std::cin >> userNumber;

			foundErrors = std::cin.fail();
			if (foundErrors) {
				std::cin.clear();
			}
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (foundErrors) {
				std::cout << "You entered an invalid option!\n";
				std::cout << inputQuestion;
				std::cout << "\n\n";
			}
			else {
				return userNumber;
			}
		}
	}

	/*
	Prints the main prompt of the list on the console.
	*/
	void mainPrompt(linkedNum::linkedInt *head, int minOpt, int maxOpt) {
		std::cout << "The list currently look like this:\n";
		linkedNum::printList(head);
		/*
		* Double list to separate the previous messages from 
		* the list of options.
		*/
		std::cout << "\n\n";

		std::cout << "You can do this actions to the list:\n";
		std::cout << "1. Add an element to the tail of the list.\n";
		std::cout << "2. Add an element to an specific position of the list.\n";
		std::cout << "3. Remove an element from a position of the list.\n";
		std::cout << "4. show an element from a position of the list.\n";
		std::cout << "5. Exit the demo (and finish the program).\n";
		std::cout << "What would you like to do? (" << minOpt << " - ";
		std::cout << maxOpt << "): ";
	}

	/*
	Gets the slected action the user wants to perform on the list.
	*/
	int getSelectedOption(linkedNum::linkedInt *head, int minOpt, int maxOpt) {
		int selectedOption{ -1 };
		bool foundErrors{ false };

		while (true) {
			std::cin >> selectedOption;

			foundErrors = std::cin.fail();
			if (foundErrors) {
				std::cin.clear();
			}
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (foundErrors || selectedOption < minOpt || selectedOption > maxOpt) {
				std::cout << "You entered an invalid option!\n";
				std::cout << "Please send a number between " << minOpt << " and " << maxOpt << '.';
				std::cout << "\n\n";
				mainPrompt(head, minOpt, maxOpt);
			}
			else {
				return selectedOption;
			}
		}
	}

	/*
	Gets a number from the user and adds it to the list
	*/
	linkedNum::linkedInt* addTail(linkedNum::linkedInt *head, linkedNum::linkedInt *tail) {
		linkedNum::linkedInt *current{ head };
		std::string question{ "Enter the number to add at the end of the list: " };
		std::cout << question;

		int numToAdd{ getNumber(question) };

		linkedNum::addToTail(head, tail, numToAdd);

		return current;
	}

	/*
	Adds a new element to a linked list in the position specified. The data added cannot be in a position
	outside of the range of the list (bigger than it's size).
	*/
	linkedNum::linkedInt* addToListPosition(linkedNum::linkedInt* head, int data, int position) {
		linkedNum::linkedInt *list{ head };
		if (position >= head->size) {																			// If the position to add the element is not valid, an error
			std::cout << "You tried to add "<< data <<" to a position out of bounds!\n";						// message will be show in the console saying that the position
			std::cout << "please make sure you don't add something to a position above " << (head->size) + 1;	// position was invalid and it cannot be bigger than the size of
			std::cout << "\n\n";																				// the list. A double line break to make this message clearer.
		}
		else if (position == 0) {
			linkedNum::linkedInt *newItem = new (std::nothrow) linkedNum::linkedInt;
			if (newItem != nullptr) {																			// If the position is the head of the list, then a new node is
				int newSize{ ++list->size };																	// created and if the memory allocation had no issues (the
				*newItem = { newSize, data, list };																// pointer is not nullptr) will point to the previous head of
				list = newItem;																					// the list. Because of this, the head of the list is updated.
			}
		}
		else {																									// If the position where we add the data resides within the list
			list = linkedNum::addToPosition(head, data, position);												// the method created for dealing with this condition is executed.
		}

		/*
		* We return the list in case the head of the list was updated in any way.
		*/
		return list;
	}

	/*
	Removes an element from the list in the position specified. The position provided cannot be
	greater than the size of the list (bigger than it's size).
	*/
	linkedNum::linkedInt* removeFromList(linkedNum::linkedInt* head, int position) {
		linkedNum::linkedInt *list{ head };

		if (position >= head->size) {																				// If the element to remove lies outside of the size of the
			std::cout << "You tried to remove data from position #" << position + 1 << "\n";						// list, an error message is displayed in the console
			std::cout << "That position is bigger than the current size of the list (" << head->size << ")!\n";		// explaining the position was invalid and could not be used.
			std::cout << "Please make sure you don't remove anything outside of the limits of the list :C.\n\n";	// A double line break to make this message clearer.
		}
		else if (position == 0) {																					// If the position to remove is the head of the list then
			list = head->next;																						// the local pointer to the list is updated with the next
			list->size = head->size;																				// element of the list and the value of it's size is also
			delete head;																							// copied. Then the old head is deleted from memory and
			head = nullptr;																							// to avoid dangling pointers, it is updated to "nullptr".
			--(list->size);																							// The size of the list is updated after removing the node.
		}
		else {																										// If we are removing some other element inside of the list
			list = linkedNum::deletePosition(head, position);														// the method that handles that is called.
		}

		/*
		* We return the list in case the head of the list was updated in any way.
		*/
		return list;
	}

	void mainDemo() {
		std::cout << "Welcome to the interactive linked list demo!\n";
		std::cout << "Here you can interact with a linked list data ";
		std::cout <<  "structure.\n\n";

		int userSelection{ 0 };

		/*
		* We created a new list and we save a reference to it and
		* also to it's tail, which right now is the list itself.
		*/
		linkedNum::linkedInt* list{ linkedNum::createList() };
		linkedNum::linkedInt* listTail{ list };

		bool runDemo{true};

		while (runDemo) {
			mainPrompt(list, constants::MIN_OPTION, constants::MAX_OPTION);

			userSelection = getSelectedOption(list, constants::MIN_OPTION, constants::MAX_OPTION);

			switch (userSelection) {
				//Add element to tail.
			case 1:
				listTail = addTail(list, listTail);
				break;
				//Add element to position.
			case 2:
				break;
				//Remove from position.
			case 3:
				break;
				//Show element from position.
			case 4:
				break;
			case 5:
				runDemo = false;
				break;
			default:
				break;
			}
		}		

		linkedNum::deleteList(list);
		list = nullptr;
	}
}