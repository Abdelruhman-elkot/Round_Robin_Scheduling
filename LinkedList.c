#include <stdio.h>
#include "LinkedList.h"

//===================================================
void CreateList(List *pl){
    pl->head = NULL;
    pl->size = 0;
}

int ListEmpty(List *pl){
    return pl->size == 0 ;
}

int Listfull(List *pl){
    return 0;
}

int ListSize(List *pl){
    return pl->size;
}

//=======================================================
void DestroyList(List *pl){
    ListNode *q = pl->head;
    while(q){
        q = q->next;
        free(pl->head);
        pl->head = q;
    }
    pl->size = 0;
}

//=========================================================
void InsertList(int pos , Process e , List *pl){
    ListNode *p, *q;
    int i ;
    q = (ListNode*)malloc(sizeof(ListNode));
    q->next = NULL;
    q->data = e;
    if(pos==0){
        q->next = pl->head;
        pl->head = q;
    }else{
        for(p=pl->head,i=0 ; i<pos-1 ; i++)
            p = p->next;
        q->next = p->next;
        p->next = q;
    }
    pl->size++;
}

//===========================================================
void DeleteItem(int pos , Process *pe , List *pl){
    ListNode *q,*p;
    int i;
    if(pos==0){
        *pe = pl->head->data;
        q = pl->head->next;
        free(pl->head);
        pl->head = q;
    }else{
        for(q=pl->head , i=0 ; i<pos-1 ; i++)
            q = q->next;
        *pe = q->next->data;
        p = q->next->next;
        free(q->next);
        q->next = p;
    }
    pl->size--;
}

//==========================================================
void TraverseList(List *pl , void (*pf)(Process)){
    ListNode *q=pl->head;
    while(q){
        (*pf)(q->data);
        q=q->next;
    }
}

//============================================================
void RetriveList(int pos ,Process *pe, List *pl){
    ListNode *q;
    int i ;
    for(q=pl->head ,i=0 ; i<pos ;i++){
        q=q->next;
    }
    *pe = q->data;
}

//=====================================================
void ReplaceList(int pos ,Process e, List *pl){
    ListNode *q;
    int i;

    for(q=pl->head , i=0 ; i<pos ; i++){
        q=q->next;
    }
    q->data = e;
}

//===========================================================
void ServeProcess (int pos ,List *pl , int Quantumtime){
    ListNode *q;
    int i;
    for(i=0,q=pl->head;i<pos;i++){
        q=q->next;
    }
    if(q->data.burstTime > Quantumtime){
    q->data.burstTime = q->data.burstTime - Quantumtime ;
    }else{
    q->data.burstTime =0;
    }
}

//======================================================
int NumberOfWatingProcess (List *pl){
    return pl->size ;
}

//===================================================
int IdCheck(List *pl , int id){
    ListNode *q = pl->head;
    while(q){
        if(q->data.processID == id)
            return 1;
        else
            q=q->next;
    }
    return 0 ;
}

//========================================================
int saveToFile(List *pl) {
    ListNode *temp = pl->head;
    FILE *fptr = fopen("processes.txt", "w");
    if (fptr == NULL) {
        return 0;
    }
    while (temp != NULL) {
        fprintf(fptr,"Process ID: %d, Burst Time: %d\n", temp->data.processID, temp->data.burstTime);
        temp = temp->next;
    }
    fclose(fptr);
    return 1;
}
//=========================================================
void addProcess(Process *pc, int burstTime){
    static int id = 1;
    id = getLastID() + 1;
    pc->processID = id++;
    pc->burstTime = burstTime;
}
//=========================================================
int getLastID(){
    int lastID = 0;
    FILE *fptr = fopen("processes.txt", "r");
    if (fptr != NULL) {
        char line[100];
        while (fgets(line, sizeof(line), fptr)) {
            int processID;
            if (fscanf(fptr, "Process ID: %d", &processID) == 1 && processID >= lastID) {
                lastID = processID;
            }
        }
        fclose(fptr);
    }
    return lastID;
}

//============================================================
int displayTotalBurstTime(){
    int total = 0;
    FILE *fptr = fopen("processes.txt", "r");
    if (fptr != NULL) {
        char line[100];
        while (fgets(line, sizeof(line), fptr)) {
            int burstTime;
            if (sscanf(line, "Process ID: %*d, Burst Time: %d", &burstTime)) {
                total += burstTime;
            }
        }
        fclose(fptr);
    }
    return total;
}
