#ifndef ADT_H_INCLUDED
#define ADT_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

/* =============================================================================
 * NAMING CONVENTIONS
 * -----------------------------------------------------------------------------
 * Types      : elmX (node), adrX (pointer to node), ListX (list head), PascalCase
 *              for plain data structs and enums.
 * Constants  : UPPER_SNAKE_CASE, enum values prefixed by their group
 *              (ROLE_, LOC_, SIDE_, ...).
 * Functions  : <module><Verb><Object>, camelCase. The module prefix equals the
 *              header name (account.h -> accountXxx, graph.h -> graphXxx).
 *
 * Verbs (same meaning in every module):
 *   create / clear           empty list init / free every node
 *   allocate / deallocate    one node
 *   insertFirst/Last/After   link an existing node (primitive, no validation)
 *   deleteFirst/Last/After/  unlink a node and hand it back (no free)
 *   deleteNode
 *   popFirst / popLast       unlink, return its values, and free the node
 *   find                     return pointer or NULL
 *   count                    return int
 *   print                    raw dump of a list
 *   add / remove             feature-level insert/delete WITH validation,
 *                            returns bool (false = rejected)
 *   show                     formatted screen for a feature
 *   browse                   interactive N / P / Q traversal
 *   sort                     reorder
 *   is / has / can           returns bool
 * ===========================================================================*/

// ----------------------------------------------------------------- enums ----
enum LocationType  { LOC_COMMON, LOC_SPAWN_ATTACKER, LOC_SPAWN_DEFENDER, LOC_SITE };
enum AgentRole     { ROLE_DUELIST, ROLE_CONTROLLER, ROLE_INITIATOR, ROLE_SENTINEL };
enum AccountRole   { ACCOUNT_ADMIN, ACCOUNT_PLAYER };
enum Side          { SIDE_ATTACKER, SIDE_DEFENDER };
enum TrapOwner     { TRAP_NONE, TRAP_ATTACKER, TRAP_DEFENDER };
enum RoundEnd      { END_DETONATED, END_DEFUSED, END_ELIMINATED, END_TIMEOUT, END_SURRENDER };
enum InsertPosition{ INSERT_FIRST, INSERT_LAST, INSERT_AFTER };
enum SortKey       { SORT_BY_NAME, SORT_BY_ROLE, SORT_BY_KILLS, SORT_BY_MATCHES,
                     SORT_BY_CONNECTIONS, SORT_BY_VISITS };

// ----------------------------------------z`----------- forward declarations ---
typedef struct elmVertex   *adrVertex;     // Graph : location
typedef struct elmEdge     *adrEdge;       // Graph : path between two locations
typedef struct elmArea     *adrArea;       // MLL   : parent (area)
typedef struct elmAreaLoc  *adrAreaLoc;    // MLL   : child  (location inside an area)
typedef struct elmAgent    *adrAgent;      // DLL   : agent pool
typedef struct elmMember   *adrMember;     // DLL   : team member
typedef struct elmMatch    *adrMatch;      // DLL   : match history
typedef struct elmAccount  *adrAccount;    // SLL   : account
typedef struct elmWaypoint *adrWaypoint;   // SLL   : helper (steps, BFS queue, route)

// ------------------------------------------------------ SLL waypoint --------
struct elmWaypoint {
    adrVertex vertex;
    int value;                  // turn number / BFS depth
    adrWaypoint next;
};
struct ListWaypoint { adrWaypoint first, last; };

// ------------------------------------------------------------- Graph --------
struct Location {
    string name;
    LocationType type;
    int visitCount;             // +1 every time an agent enters during a match
};
struct elmEdge {
    adrVertex destination;
    int travelTime;             // seconds, > 0
    int smokeTurnsLeft;         // 0 = open, > 0 = blocked for n global turns
    adrEdge next;
};
struct elmVertex {
    Location info;
    adrEdge firstEdge;
    adrArea area;               // back-pointer to MLL parent
    TrapOwner trap;
    bool visited;               // BFS / DFS / Dijkstra marker
    int distance;
    adrVertex parent;
    adrVertex next;
};
struct Graph { adrVertex first; };

// --------------------------------------------------------- MLL area ---------
struct elmAreaLoc {             // CHILD
    adrVertex vertex;           // points to a graph vertex (not a copy)
    adrAreaLoc next, prev;
};
struct ListAreaLoc { adrAreaLoc first, last; };

struct elmArea {                // PARENT
    string name;                // e.g. "Site A"
    ListAreaLoc locations;
    adrArea next, prev;
};
struct ListArea { adrArea first, last; };

// ---------------------------------------------------- DLL agent pool --------
struct Agent {
    string name;
    AgentRole role;
};
struct elmAgent {
    Agent info;
    adrAgent next, prev;
};
struct ListAgent { adrAgent first, last; };

// --------------------------------------------------------- DLL team ---------
struct AgentStats {
    int matchesPlayed, kills, deaths, plants, defuses;
};
struct MatchState {             // reset every round
    adrVertex position;
    bool isAlive, hasSpike, skillUsed, isTrapped;
    int roundKills;
    ListWaypoint steps;         // SLL step history (Step Back action)
};
struct elmMember {
    adrAgent agent;             // points to the pool node (not a copy)
    AgentStats stats;
    MatchState state;
    adrMember next, prev;
};
struct ListTeam {
    adrMember first, last;
    int size;
};

// ------------------------------------------------ DLL match history ---------
struct MatchRecord {
    int number;
    Side side;
    RoundEnd endReason;
    int turns, kills, deaths;
    bool won;
    string mvp;
};
struct elmMatch {
    MatchRecord info;
    adrMatch next, prev;
};
struct ListMatch { adrMatch first, last; };

// ------------------------------------------------------ SLL account ---------
struct Account {
    string username, password;
    AccountRole role;
    int matchesPlayed, wins, losses, kills, deaths;
};
struct elmAccount {
    Account info;
    ListTeam team;              // DLL "My Team" owned by this account
    ListMatch history;          // DLL match history owned by this account
    int nextMatchNumber;
    adrAccount next;
};
struct ListAccount { adrAccount first; };

// -------------------------------------------------- running round -----------
struct Round {
    ListTeam *attackers;
    ListTeam *defenders;
    adrMember lastAttacker;     // member who moved last on each side
    adrMember lastDefender;
    bool isAttackerTurn;
    int globalTurn;
    bool isSpikePlanted;
    adrVertex spikeLocation;    // also used when the spike is dropped
    int spikeTimer;
    int defuseProgress;
};

#endif // ADT_H_INCLUDED
