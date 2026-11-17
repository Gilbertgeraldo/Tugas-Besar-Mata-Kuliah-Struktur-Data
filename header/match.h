#ifndef MATCH_H_INCLUDED
#define MATCH_H_INCLUDED
#include "adt.h"

// DLL match history

// ---------------------------------------------------------- primitives ------
void matchCreateList(ListMatch &list);
adrMatch matchAllocate(MatchRecord record);
void matchDeallocate(adrMatch &node);
bool matchIsEmpty(ListMatch list);
void matchInsertFirst(ListMatch &list, adrMatch node);
void matchInsertLast(ListMatch &list, adrMatch node);   // used after every round
void matchInsertAfter(ListMatch &list, adrMatch prec, adrMatch node);
void matchDeleteFirst(ListMatch &list, adrMatch &node);
void matchDeleteLast(ListMatch &list, adrMatch &node);
void matchDeleteAfter(ListMatch &list, adrMatch prec, adrMatch &node);
void matchDeleteNode(ListMatch &list, adrMatch node);   // all 4 cases
adrMatch matchFind(ListMatch list, int number);
int matchCount(ListMatch list);
void matchPrintOldestFirst(ListMatch list);
void matchPrintNewestFirst(ListMatch list);             // P5.1, walks from last via prev
void matchClear(ListMatch &list);

// ------------------------------------------------------------ features ------
void matchBrowse(ListMatch list);                       // P5.2: N older, P newer, Q quit
bool matchRemove(ListMatch &list, int number);          // P5.3, account stats unchanged
void matchShowSummary(ListMatch list);                  // P5.4

#endif // MATCH_H_INCLUDED
