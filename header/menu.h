#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "adt.h"

// Screens & navigation between them

void menuStart(ListAccount &accounts, ListAgent &pool, ListArea &areas, Graph &graph);

// --------------------------------------------------------------- admin ------
void menuAdmin(ListAccount &accounts, adrAccount current,
               ListAgent &pool, ListArea &areas, Graph &graph);
void menuManageMap(Graph &graph, ListArea &areas);              // A1
void menuManageAreas(ListArea &areas, Graph &graph);            // A2
void menuManageAgents(ListAgent &pool, ListAccount &accounts);  // A3
void menuManageAccounts(ListAccount &accounts, adrAccount current);  // A4
void menuShowGlobalStats(ListAccount accounts, ListAgent pool,
                         ListArea areas, Graph graph);          // A5
void menuProfile(adrAccount current);                           // A6 / P7

// -------------------------------------------------------------- player ------
void menuPlayer(ListAccount &accounts, adrAccount current,
                ListAgent &pool, ListArea &areas, Graph &graph);
void menuViewMap(Graph graph, ListArea areas);                  // P1
void menuNavigation(Graph graph);                               // P2
void menuMyTeam(adrAccount current, ListAgent pool);            // P3
void menuMatchHistory(adrAccount current);                      // P5
void menuLeaderboard(ListAccount accounts, adrAccount current);  // P6

#endif // MENU_H_INCLUDED
