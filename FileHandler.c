#include <stdio.h>
#include "FileHandler.h"

//================== GET DATA OF PROCESSES WERE SAVED IN FILES =====================================================
int ReadFromFile(List *pl) {
    FILE *pf = fopen("processes.txt", "r");

    if (pf == NULL) {
        return 0;
    }

    ListNode *q;

    while (!feof(pf)) {

        ListNode *pn = (ListNode*)malloc(sizeof(ListNode));
        if (fscanf(pf, "Process ID: %d, Burst Time: %d\n", &(pn->data.processID), &(pn->data.burstTime)) == 2) {
            pn->next = NULL;
            if (pl->head == NULL) {
                pl->head = pn;
            }
            else {
                q->next = pn;
            }
            q = pn;
            pl->size++;
        }
    }

    fclose(pf);
    return 1;
}

//================== SAVED DATA OF PROCESSES AFTER FINISHED IN FILES TO GET AGAIN =======================================
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

//================== SAVED LAST POSISION AFTER SERVE IN FILE TO GET AGAIN WHEN START A PROGRAM ==========================
int SavePosToFile(int pos) {
    FILE *pf = fopen("ServePos.txt", "w");
    if (pf == NULL) {
        return 0;
    }

    fprintf(pf, "Last Possession : %d", pos);
    fclose(pf);
    return 1;
}

//=============== GET THE POSISION WHERE WE STOPED LAST TIME TO START SERVED AGAIN AFTER THAT ============================
int ReadPosFromFile(int *pos) {
    FILE *pf = fopen("ServePos.txt", "r");
    if (pf == NULL) {
        return 0;
    }

    if (fscanf(pf, "Last Possession : %d", pos) != 1) {
        fclose(pf);
        return 0;
    }

    fclose(pf);
    return pos;
}
