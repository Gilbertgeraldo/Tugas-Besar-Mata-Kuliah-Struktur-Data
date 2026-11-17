#ifndef WAYPOINT_H_INCLUDED
#define WAYPOINT_H_INCLUDED
#include "adt.h"

// SLL helper, one ADT with three uses:
//   step history : insertFirst + popFirst
//   BFS queue    : insertLast  + popFirst
//   route        : insertFirst while walking parents; DFS uses insertLast + popLast

void waypointCreateList(ListWaypoint &list);
adrWaypoint waypointAllocate(adrVertex vertex, int value);
bool waypointIsEmpty(ListWaypoint list);
void waypointInsertFirst(ListWaypoint &list, adrVertex vertex, int value = 0);
void waypointInsertLast(ListWaypoint &list, adrVertex vertex, int value = 0);
void waypointPopFirst(ListWaypoint &list, adrVertex &vertex, int &value);
void waypointPopLast(ListWaypoint &list, adrVertex &vertex, int &value);
int waypointCount(ListWaypoint list);
void waypointCopy(ListWaypoint source, ListWaypoint &destination);
void waypointPrint(ListWaypoint list);                  // "A -> B -> C"
void waypointClear(ListWaypoint &list);

#endif // WAYPOINT_H_INCLUDED
