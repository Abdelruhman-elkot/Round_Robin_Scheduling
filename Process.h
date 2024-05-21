#ifndef PROCESS_H_INCLUDED
#define PROCESS_H_INCLUDED

#include "Global.h"
#include "LinkedList.h"

void addProcess(Process *pc, int burstTime, List *pl);
void ServeProcess(int pos ,List *pl, Process *e);
int NumberOfWatingProcess (List *pl);
void DisplayProcessesInfo(List *pl);
int displayTotalBurstTime(List *pl);

#endif // PROCESS_H_INCLUDED
