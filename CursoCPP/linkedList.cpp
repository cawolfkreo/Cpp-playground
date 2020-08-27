#include "linkedList.h"
#include "linkedNum.h"
#include <iostream>
#include <new>
#include <string>

namespace linkedList {

	linkedNum::linkedInt* addToListPosition(linkedNum::linkedInt* head, int data, int position) {
		linkedNum::linkedInt *list{ head };
		if (position >= head->size) {
			std::cout << "You tried to add "<< data <<" to a position out of bounds!\n";
			std::cout << "please make sure you don't add something to a position above " << head->size;
			std::cout << "\n\n";
		}
		else if (position == 0) {
			linkedNum::linkedInt *newItem = new (std::nothrow) linkedNum::linkedInt;
			if (newItem != nullptr) {
				int newSize{ ++list->size };
				*newItem = { newSize, data, list };
				list = newItem;
			}
		}
		else {
			list = linkedNum::addToPosition(head, data, position);
		}

		return list;
	}

	linkedNum::linkedInt* removeFromList(linkedNum::linkedInt* head, int position) {
		linkedNum::linkedInt *list{ head };

		if (position >= head->size) {
			std::cout << "You tried to remove data from position #" << position + 1 << "\n";
			std::cout << "That position is bigger than the current size of the list (" << head->size << ")!\n";
			std::cout << "Please make sure you don't remove anything outside of the limits of the list :C.\n\n";
		}
		else if (position == 0) {
			list = head->next;
			list->size = head->size;
			delete head;
			head = nullptr;
			--(list->size);
		}
		else {
			list = linkedNum::deletePosition(head, position);
		}

		return list;
	}

	void mainDemo() {
		std::cout << "Let's try this list:\n";

		linkedNum::linkedInt *list{ linkedNum::createList()};
		linkedNum::linkedInt* listTail{ list };

		for (int i = 0; i < 5; ++i) {
			if (i == 1) {
				continue;
			}
			listTail = linkedNum::addToTail(list, listTail, i + 1);
		}

		linkedNum::printList(list);
		std::cout << "The size of the list is: " << list->size << '\n';
		std::cout << "We don't have the 2!\n";

		addToListPosition(list, 2, 1);
		linkedNum::printList(list);
		std::cout << "The size of the list is: " << list->size << '\n';
		std::cout << "There you go, much better!\n\n";

		addToListPosition(list, 2, 1);
		linkedNum::printList(list);
		std::cout << "The size of the list is: " << list->size << '\n';
		std::cout << "Wait no, now the 2 is twice! we need to remove it!\n";
		linkedNum::deletePosition(list, 1);
		linkedNum::printList(list);
		std::cout << "The size of the list is: " << list->size << '\n';
		std::cout << "Oh yeah! things seem in order now! :D\n";
	}
}