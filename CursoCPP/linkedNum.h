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
    int searchIndex(linkedInt** pointToList, int dataToSearch);
    linkedInt* getPosition(linkedInt* head, int position);
    void printList(linkedInt* head);
    void deleteList(linkedInt* head);
    linkedInt* deletePosition(linkedInt* head, int position);
}
#endif
#pragma once
