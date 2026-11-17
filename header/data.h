#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED
#include "adt.h"

// Default data (section 7) & shutdown cleanup (section 9.4)

void dataLoadAgents(ListAgent &pool);                   // 12 agents, inserted in order
void dataLoadMap(Graph &graph, ListArea &areas);        // 5 areas, 13 locations, 17 paths
void dataLoadAccounts(ListAccount &accounts, ListAgent pool);  // admin, pemain1, pemain2
void dataLoadDefaults(ListAccount &accounts, ListAgent &pool, ListArea &areas, Graph &graph);
void dataFreeAll(ListAccount &accounts, ListAgent &pool, ListArea &areas, Graph &graph);
// order: accounts -> pool -> areas -> graph

// [BONUS]
void dataSaveToFile(ListAccount accounts, ListAgent pool, ListArea areas, Graph graph);
bool dataLoadFromFile(ListAccount &accounts, ListAgent &pool, ListArea &areas, Graph &graph);

#endif // DATA_H_INCLUDED
