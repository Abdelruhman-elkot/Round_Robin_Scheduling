#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include "Global.h"

typedef struct listnode{
    Process data;
    struct listnode *next;
}ListNode;

typedef struct {
    ListNode *head;
    int size;
}List;

//===============================================================================================
void CreateList(List *pl);
int ListEmpty(List *pl);
int Listfull(List *pl);
int ListSize(List *pl);
void InsertList(int pos , Process e , List *pl);
void DeleteItem(int pos , Process *pe , List *pl);
void TraverseList(List *pl , void (*pf)(Process));

#endif // LINKEDLIST_H_INCLUDED
