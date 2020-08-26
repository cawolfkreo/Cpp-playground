#ifndef LINKEDNUM_H
#define LINKEDNUM_H
namespace linkedNum {
    struct linkedInt {
        int size;
        int data;
        linkedInt* next;
    };

    linkedInt* createList();
    linkedInt* addToTail(linkedInt* head, linkedInt* tail, int addThis);
    void printList(linkedInt* head);
    void deleteList(linkedInt* head);
}
#endif
#pragma once
