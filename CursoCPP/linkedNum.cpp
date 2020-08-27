#include "linkedNum.h"
#include <iostream>
#include <new>

namespace linkedNum {

    linkedInt* createList() {
        linkedInt *ptr = new (std::nothrow) linkedInt;

        if (ptr != nullptr) {
            *ptr = { 0, -1, nullptr };
        }

        return ptr;
    }

    linkedInt* addToTail(linkedInt *head, linkedInt *tail, int addThis) {
        linkedInt *current{ head };

        if (head->size == 0) {
            *current = { 1, addThis, nullptr };
        }
        else {
            current = tail;
            linkedInt *newTail = new (std::nothrow) linkedInt;

            if (newTail != nullptr) {
                *newTail = { 1, addThis, nullptr };

                current->next = newTail;
                ++head->size;
                current = newTail;
            }

        }

        return current;
    }

    void printList(linkedInt *head) {
        linkedInt *current{ head };
        for (long i{ 1 }; current != nullptr; ++i) {
            std::cout << i << ". \t" << current->data << '\n';
            current = current->next;
        }
    }

    void deleteList(linkedInt *head) {
        linkedInt *current{ head };
        linkedInt *next{ nullptr };

        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }

        current = nullptr;
        next = nullptr;
    }

}
