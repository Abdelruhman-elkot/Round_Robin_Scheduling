#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Process.h"
#include "LinkedList.h"
#include "Helpers.h"
#include "FileHandler.h"

// Prototype Of Functions
void DisplayProcessInfo(Process e);

int main()
{
    List l;
    Process e;
    CreateList(&l);
    char choice;
    int pos = 0, burstTime;

    // Reads Data From Files.
    if (ReadFromFile(&l) == 0)
        printf("Error can't read from the file !\n");

    if (ReadPosFromFile(&pos) == 0){
        printf("Error loading Possession from file!\n");
        pos = ReadPosFromFile(&l);
    }

     do {
        MenuDisplay();
        scanf(" %c", &choice);
        while (getchar() != '\n');

        switch (choice) {
            // Add Processes.
            case 'a':
                while (true){
                    printf("\nEnter Process Time : ");
                    if (scanf("%d", &burstTime) == 1 && burstTime > 0){
                        addProcess(&e,burstTime,&l);
                        InsertList(ListSize(&l),e,&l);
                        printf("\n--------------- Process with Id : %d and BurstTime %d added Successfully ! -------------------\n\n",e.processID,e.burstTime);
                        break;
                    } else {
                        while (getchar() != '\n');
                        printf("\n------------------- Invalid input. Please enter a positive integer. -----------------------\n");
                    }
                }
                break;
            // Reserve Processes.
            case 'b':
                if (ListEmpty(&l)){
                    printf("\n---------------------------- There is No Process To Serve ------------------------------\n\n");
                } else {
                    ServeProcess(pos ,&l ,&e);
                    if (e.burstTime <= 0) {
                        printf("\n------------------- Process with ID: %d is already completed. ----------------------\n\n", e.processID);
                        DeleteItem(pos, &e, &l);
                        if (pos == 0){
                            continue;
                        } else {
                            pos = pos % (ListSize(&l));
                        }
                    } else {
                        printf("\n--------------------------- Process with ID: %d served ---------------------------- \n", e.processID);
                        printf("-------------------------------- Time left: %d -------------------------------------\n\n", e.burstTime);
                        pos = (pos + 1) % (ListSize(&l));
                    }
                }
                break;
            // How Many Waiting Processes.
            case 'c':
                printf("\n------------------------------ There are %d waiting process ----------------------------\n\n" , NumberOfWatingProcess(&l));
                break;
            // Display Processes Informations.
            case 'd':
                if (ListEmpty(&l)) {
                    printf("\n---------------------------- No Process Waiting yet ! ------------------------------\n\n");
                    break;
                } else {
                    printf("\n --------------------- Displaying waiting processes information: ----------------------\n\n");
                    TraverseList(&l, &DisplayProcessInfo);
                }
                printf("\n-----------------------------------------------------------------------------------------\n\n");
                break;
            // Display Total BurstTime.
            case 'e':
                printf("\n--------------------------- Total Burst Time : %d -----------------------------------\n\n", displayTotalBurstTime(&l));
                break;

            case 'f':
                if(saveToFile(&l) && SavePosToFile(pos)){
                    printf("\n-------------------------- Exiting And Saved Successfully. ---------------------------\n");
                } else {
                    printf("\n-------------------------- Error Opening File Not Saved. -----------------------------\n");
                }
                break;

            default:
                printf("\n------------------------ Invalid choice! Please enter a valid option. --------------------\n\n");
        }
    } while (choice != 'f');

    return 0;
}

// To Display The Informations.
void DisplayProcessInfo(Process e){
    printf("\nProcessID : [%d] , Time Left : [%d]", e.processID, e.burstTime);
}
