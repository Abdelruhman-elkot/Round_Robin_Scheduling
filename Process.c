#include <stdio.h>
#include <stdlib.h>
#include "Process.h"

// ====================== ADD PROCESSES ========================================================
void addProcess(Process *pc, int burstTime, List *pl){
    static int id = 1;
    ListNode *p;
    int i ;
    if (!ListEmpty(pl)){
        for(p=pl->head,i=0 ; i<pl->size-1; i++)
                p = p->next;
                id = p->data.processID + 1;
    }
    pc->processID = id++;
    pc->burstTime = burstTime;
}

//======================= SERVE PROCESS ==========================================================
void ServeProcess(int pos ,List *pl, Process *e){
    ListNode *pn;
    int i;
    for(i = 0 , pn = pl->head; i < pos; i++){
        pn = pn->next;
    }
    if(pn->data.burstTime > QuantumTime){
        pn->data.burstTime -= QuantumTime ;
        e->burstTime = pn->data.burstTime;
        e->processID = pn->data.processID;
    } else{
        pn->data.burstTime = 0;
        e->burstTime = pn->data.burstTime;
        e->processID = pn->data.processID;
    }
}

//======================= NUMBER OF WAITING PROCESS ==================================================
int NumberOfWatingProcess (List *pl){
    return pl->size;
}

//======================= DISPLAY PROCESSES INFORMATIONS ==============================================
/*void DisplayProcessesInfo(List *pl) {
    if (pl->head != NULL && pl->size != 0) {
        ListNode *temp = pl->head;
        do {
            printf("Id is : %d , Burst time is : %d\n", temp->data.processID, temp->data.burstTime);
            temp = temp->next;
        } while (temp);
    }
    else
        printf("The list is empty!\n");
}*/

//======================= DISPLAY TOTAL BURSTTIME ========================================================
int displayTotalBurstTime(List *pl) {
    int totalBurstTime = 0;
    ListNode *temp = pl->head;
    while (temp != NULL) {
        totalBurstTime += temp->data.burstTime;
        temp = temp->next;
    }
    return totalBurstTime;
}
