#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include "stdlib.h"
#include "Global.h"

typedef struct listnode{
    Process data;
    struct listnode *next;
}ListNode;

typedef struct {
    ListNode *head;
    int size;
}List;

void CreateList(List *pl);
int ListEmpty(List *pl);
int Listfull(List *pl);
int ListSize(List *pl);
void DestroyList(List *pl);
void InsertList(int pos , Process e , List *pl);
void DeleteItem(int pos , Process *pe , List *pl);
void TraverseList(List *pl , void (*pf)(Process));
void RetrieveList(int pos ,Process *pe, List *pl);
void ReplaceList(int pos ,Process e, List *pl);


void ServeProcess(int pos ,List *pl , int Quantumtime);
int NumberOfWatingProcess(List *pl);
int IdCheck(List *pl , int id); // 3shan acheck 2bl ma add el id

int displayTotalBurstTime();
int saveToFile(List *pl);
int getLastID();

void addProcess(Process *pc, int burstTime);

#endif // LINKEDLIST_H_INCLUDED
