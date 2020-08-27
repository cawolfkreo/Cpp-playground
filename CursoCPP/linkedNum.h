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
    linkedInt* addToPosition(linkedInt* head, int data, int position);
    void printList(linkedInt* head);
    void deleteList(linkedInt* head);
}
#endif
#pragma once
