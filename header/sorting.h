#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED
#include "adt.h"
#include "graph.h"

// Sorting & searching on temporary POINTER ARRAYS: the original lists are untouched.
// (S1, S2, S8 reorder the list itself: see team.h, agent.h, area.h)
// (S6, S7 account merge sort lives in account.cc, used only by that module)
// Recursive helpers (merge, partition) and comparators stay static in sorting.cpp.

struct PathRef {                // one edge together with its origin (S4)
    adrVertex from;
    adrEdge edge;
};

// -------------------------------------------------------- collectors --------
int sortCollectLocations(Graph graph, adrVertex out[]);
int sortCollectPaths(Graph graph, PathRef out[]);

// ----------------------------------------------------------- sorting --------
void sortLocations(adrVertex items[], int count, SortKey key, bool ascending);   // S3 selection
void sortPaths(PathRef items[], int count, bool ascending);                      // S4 merge
void sortRoutes(Route items[], int count, bool ascending);                       // S5 quick
void sortVerticesByDistance(adrVertex items[], int count, bool ascending);       // S5 quick

// --------------------------------------------------- searching [BONUS] ------
int searchLocationSequential(adrVertex items[], int count, string name, int &comparisons);
int searchLocationBinary(adrVertex items[], int count, string name, int &comparisons);

#endif // SORTING_H_INCLUDED
