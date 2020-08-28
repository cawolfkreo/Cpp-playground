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

    /*
    Adds a number to a particual position of the list except the first position [0].
    The position cannot be bigger than the size of the list (the current size -1).
    */
    linkedInt* addToPosition(linkedInt *head, int data, int position) {
        linkedInt *previousNode{ getPosition(head, position - 1) };

        linkedInt* nodeToAdd = new (std::nothrow) linkedInt;

        if (nodeToAdd != nullptr) {
            *nodeToAdd = { 1, data, previousNode->next };
            previousNode->next = nodeToAdd;
            ++(head->size);
        }

        return head;
    }

    /*
    Uses the triple pointer operation to search for an item on the list.
    If the item is not on the list, it will return the size of the list.
    */
    int searchIndex(linkedInt**pointToList, int dataToSearch) {
        int currentIndex{ 0 };
        linkedInt **currentPointer{ pointToList };

        while (*currentPointer != nullptr && (*currentPointer)->data != dataToSearch ) {
            currentPointer = &(*currentPointer)->next;
            ++currentIndex;
        }

        return currentIndex;
    }

    /*
    Gets the node on the position specified by parameter.
    The position cannot be bigger than the size of the list.
    */
    linkedInt* getPosition(linkedInt* head, int position) {
        linkedInt* current{ head };
        int currentPosition{ 0 };

        while (currentPosition < position) {
            current = current->next;
            ++currentPosition;
        }

        return current;
    }

    void printList(linkedInt *head) {
        if (head->size == 0) {
            std::cout << "The list is empty! :C\n";
        }
        else {
            linkedInt* current{ head };
            for (long i{ 1 }; current != nullptr; ++i) {
                std::cout << i << ". \t" << current->data << '\n';
                current = current->next;
            }
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

    linkedInt* deletePosition(linkedInt *head, int position) {
        linkedInt *previous{ getPosition(head, position - 1) };
        linkedInt *nodeToRemove{ previous->next };
        previous->next = nodeToRemove->next;
        nodeToRemove->next = nullptr;

        delete nodeToRemove;
        --(head->size);

        return head;
    }
}
