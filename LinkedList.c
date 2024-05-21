#include <stdio.h>
#include "LinkedList.h"

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

//===============================================================================================
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

//===============================================================================================
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

//===============================================================================================
void TraverseList(List *pl , void (*pf)(Process)){
    ListNode *q=pl->head;
    while(q){
        (*pf)(q->data);
        q=q->next;
    }
}
