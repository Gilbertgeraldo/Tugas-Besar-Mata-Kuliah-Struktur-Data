#ifndef AREA_H_INCLUDED
#define AREA_H_INCLUDED
#include "adt.h"

// MLL 1-to-N: area (parent) -> location (child pointing to a graph vertex)

// --------------------------------------------------- parent primitives ------
void areaCreateList(ListArea &list);
adrArea areaAllocate(string name);
void areaDeallocate(adrArea &node);
void areaInsertLast(ListArea &list, adrArea node);
void areaDeleteNode(ListArea &list, adrArea node);      // unlink only, all 4 cases
adrArea areaFind(ListArea list, string name);
adrArea areaFindAt(ListArea list, int index);           // 1-based, for numbered menus
int areaCount(ListArea list);
void areaPrintForward(ListArea list);                   // A2.1 / P1.2
void areaPrintBackward(ListArea list);                  // A2.1
void areaClear(ListArea &list);                         // frees children & parents, not vertices

// ---------------------------------------------------- child primitives ------
void areaLocCreateList(ListAreaLoc &list);
adrAreaLoc areaLocAllocate(adrVertex vertex);
void areaLocDeallocate(adrAreaLoc &node);
void areaLocInsertLast(ListAreaLoc &list, adrAreaLoc node);
void areaLocDeleteNode(ListAreaLoc &list, adrAreaLoc node);   // unlink only
adrAreaLoc areaLocFind(ListAreaLoc list, adrVertex vertex);
int areaLocCount(ListAreaLoc list);
void areaLocMove(adrArea from, adrArea to, adrAreaLoc node);

// ------------------------------------------------------------ features ------
bool areaAdd(ListArea &list, string name);                      // A2.2
bool areaRemove(ListArea &list, adrArea area);                  // A2.3, only when empty
bool areaRename(ListArea list, adrArea area, string newName);   // A2.4
void areaAttachLocation(adrArea area, adrVertex vertex);        // Kode 15, sets back-pointer
bool areaMoveLocation(adrVertex vertex, adrArea destination);   // A2.5, Kode 15
adrArea areaFindByLocation(Graph graph, string locationName);   // A2.6 / P1.3
void areaShowStats(ListArea list);                              // A2.7
void areaSortLocations(adrArea area, bool ascending);           // A2.8, insertion sort (S8)

#endif // AREA_H_INCLUDED
