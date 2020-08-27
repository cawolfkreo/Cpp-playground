#include "linkedList.h"
#include "linkedNum.h"
#include <iostream>
#include <string>

namespace linkedList {

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
		std::cout << "We don't have the 2!\n";

		linkedNum::addToPosition(list, 2, 1);
		linkedNum::printList(list);
		std::cout << "There you go, much better!\n";
	}
}