#ifndef AGENT_H_INCLUDED
#define AGENT_H_INCLUDED
#include "adt.h"

// DLL agent pool

// ---------------------------------------------------------- primitives ------
void agentCreateList(ListAgent &list);
adrAgent agentAllocate(string name, AgentRole role);
void agentDeallocate(adrAgent &node);
bool agentIsEmpty(ListAgent list);
void agentInsertFirst(ListAgent &list, adrAgent node);
void agentInsertLast(ListAgent &list, adrAgent node);
void agentInsertAfter(ListAgent &list, adrAgent prec, adrAgent node);
void agentDeleteFirst(ListAgent &list, adrAgent &node);
void agentDeleteLast(ListAgent &list, adrAgent &node);
void agentDeleteAfter(ListAgent &list, adrAgent prec, adrAgent &node);
void agentDeleteNode(ListAgent &list, adrAgent node);   // handles all 4 cases
adrAgent agentFind(ListAgent list, string name);        // A3.6
adrAgent agentFindAt(ListAgent list, int index);        // 1-based, for numbered menus
int agentCount(ListAgent list);
void agentPrintForward(ListAgent list);                 // A3.1
void agentPrintBackward(ListAgent list);                // A3.1
void agentClear(ListAgent &list);

// ------------------------------------------------------------- sorting ------
void agentSwapWithNext(ListAgent &list, adrAgent node); // Kode 13, relinks pointers
void agentSort(ListAgent &list, SortKey key, bool ascending);  // A3.7, bubble sort (S2)

// ------------------------------------------------------------ features ------
bool agentAdd(ListAgent &list, string name, AgentRole role,
              InsertPosition position, string afterName);           // A3.2
int agentCountUsage(ListAccount accounts, adrAgent agent);          // teams using this agent
void agentRemove(ListAgent &list, ListAccount &accounts, adrAgent agent);  // A3.3
void agentChangeRole(adrAgent agent, AgentRole newRole);            // A3.4
void agentBrowse(ListAgent list);                                   // A3.5

#endif // AGENT_H_INCLUDED
