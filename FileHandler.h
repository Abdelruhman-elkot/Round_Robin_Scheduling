#ifndef FILEHANDLER_H_INCLUDED
#define FILEHANDLER_H_INCLUDED

#include "LinkedList.h"

int ReadFromFile(List *pl);
int saveToFile(List *pl);

int SavePosToFile(int pos);
int ReadPosFromFile(int *pos);

#endif // FILEHANDLER_H_INCLUDED
