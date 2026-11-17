#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include "adt.h"

// Directed weighted graph, adjacency list
const int INFINITE_DISTANCE = 1000000000;
const int MAX_ROUTES = 100;

struct Route {                  // one DFS result (P2.3)
    ListWaypoint stops;
    int totalTime;
};

// ---------------------------------------------------- vertex primitives -----
void graphCreate(Graph &graph);
adrVertex graphAllocateVertex(string name, LocationType type);
void graphDeallocateVertex(adrVertex &vertex);
void graphAddVertex(Graph &graph, adrVertex vertex);
adrVertex graphFindVertex(Graph graph, string name);
void graphDeleteVertex(Graph &graph, adrVertex vertex); // unlink only
adrVertex graphFindSpawn(Graph graph, LocationType spawnType);
int graphCountVertices(Graph graph);

// ------------------------------------------------------ edge primitives -----
adrEdge graphAllocateEdge(adrVertex destination, int travelTime);
void graphAddEdge(adrVertex from, adrVertex to, int travelTime);
adrEdge graphFindEdge(adrVertex from, adrVertex to);
void graphDeleteEdge(adrVertex from, adrVertex to);     // no-op when missing
void graphDeleteFirstEdge(adrVertex vertex);
int graphOutDegree(adrVertex vertex);
int graphInDegree(Graph graph, adrVertex vertex);
int graphCountEdges(Graph graph);

// ------------------------------------------------------------- general ------
void graphPrint(Graph graph);                           // A1.1 / P1.1
void graphResetMarkers(Graph graph);                    // visited, parent, distance
void graphClear(Graph &graph);                          // all edges, then all vertices

// ------------------------------------------------------ map management ------
bool graphAddLocation(Graph &graph, string name, LocationType type, adrArea area);  // A1.2
void graphRemoveLocation(Graph &graph, adrVertex vertex);                          // A1.3, Kode 16
bool graphAddPath(Graph &graph, string from, string to, int travelTime, bool bidirectional);  // A1.4
bool graphRemovePath(Graph &graph, string from, string to, bool bidirectional);     // A1.5
bool graphUpdateTravelTime(Graph &graph, string from, string to, int travelTime);   // A1.6
void graphShowLocationDetail(Graph graph, string name);                             // A1.7
bool graphValidate(Graph graph, bool printIssues);                                  // A1.8, Kode 22
void graphShowStats(Graph graph);                                                   // A1.9 (S4)
void graphShowLocationsSorted(Graph graph, SortKey key, bool ascending);           // P1.4 (S3)

// ---------------------------------------------------------- algorithms ------
bool graphBfs(Graph graph, adrVertex source, adrVertex target);         // Kode 17
int graphDijkstra(Graph graph, adrVertex source, adrVertex target);     // Kode 18, target NULL = all
ListWaypoint graphBuildRoute(adrVertex target);                         // Kode 19
void graphDfsAllRoutes(adrVertex current, adrVertex target, ListWaypoint &path,
                       int totalTime, int maxSteps,
                       Route routes[], int &routeCount);                // Kode 20

// ---------------------------------------------------------- navigation ------
void graphShowFastestRoute(Graph graph, string from, string to);        // P2.1
void graphShowFewestStepsRoute(Graph graph, string from, string to);    // P2.2
void graphShowAllRoutes(Graph graph, string from, string to, int maxSteps);  // P2.3 (S5)
void graphShowReachableWithin(Graph graph, string from, int seconds);   // P2.4 (S5)
void graphShowConnectivity(Graph graph, string from, string to);        // P2.5
void graphShowSiteRotations(Graph graph);                               // P2.6
void graphShowChokepoints(Graph graph);                                 // P2.7 [BONUS]

// ------------------------------------------------------------ in match ------
void graphTickSmokes(Graph graph);                      // smokeTurnsLeft - 1 every global turn
void graphClearSmokes(Graph graph);
void graphClearTraps(Graph graph);

#endif // GRAPH_H_INCLUDED
