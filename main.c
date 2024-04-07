#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Global.h"
#include "LinkedList.h"
#include "Helpers.h"

void Display(Process e){
    printf("\nprocess ID : %d  Remaining Time : %d second \n",e.processID,e.burstTime);
}

int main()
{
    List l;
    Process e;
    CreateList(&l);
    int choice, burstTime;

    int loopcounter;
    int y,x=1,position=0,key,additioncase;

     do {
        printf("\nMenu:\n");
        printf("1. Add a process\n");
        printf("2. Serve a process\n");
        printf("3. How many waiting processes?\n");
        printf("4. Display information of waiting processes\n");
        printf("5. Display total CPU burst time\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                while (true){
                    printf("\nEnter Process Time : ");
                    if (scanf("%d", &burstTime) == 1 && burstTime > 0){
                        addProcess(&e,burstTime);
                        InsertList(ListSize(&l),e,&l);
                        int a = saveToFile(&l);
                        printf("Process with Id Number : %d and time %d added Successfully !\n",e.processID,e.burstTime);
                        break;
                    } else {
                        while (getchar() != '\n');
                        printf("Invalid input. Please enter a positive integer.\n");
                    }
                }
                break;
            case 2:
                break;
            case 3:
                printf("\nThere are %d waiting process\n" , NumberOfWatingProcess(&l));
                break;
            case 4:
                 TraverseList(&l,&Display);
                break;
            case 5:
                 printf("\nTotal Burst Time : %d\n", displayTotalBurstTime());
                break;
            case 6:
                if(saveToFile(&l)){
                    printf("\nExiting And Saved Successfully.\n");
                }else{
                    printf("\nError Opening File Not Saved.\n");
                }
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 6);

    return 0;
}
