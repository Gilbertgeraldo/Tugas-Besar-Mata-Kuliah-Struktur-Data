#ifndef ROUND_H_INCLUDED
#define ROUND_H_INCLUDED
#include "adt.h"

// P4 Play: round simulation (uses every data structure)
const int ROUND_MAX_TURNS         = 40;
const int SPIKE_TIMER_TURNS       = 10;
const int SMOKE_DURATION_TURNS    = 6;
const int DEFUSE_ACTIONS_REQUIRED = 2;

// --------------------------------------------------------- entry point ------
void roundPlay(adrAccount player, ListAgent pool, Graph &graph, ListArea areas);

// --------------------------------------------------------------- setup ------
bool roundCanStart(adrAccount player, Graph graph);     // team not empty & map valid
void roundBuildOpponentTeam(ListTeam &opponents, ListAgent pool, int size);
void roundResetTeam(ListTeam &team, adrVertex spawn);   // alive, skill ready, no steps
void roundSetup(Round &round, ListTeam &playerTeam, ListTeam &opponents,
                Side playerSide, Graph graph);

// ---------------------------------------------------------------- loop ------
void roundRun(Round &round, Graph &graph, ListArea areas, Side &winner, RoundEnd &reason);  // Kode 14
bool roundIsOver(Round round, Side &winner, RoundEnd &reason);
ListTeam *roundActiveTeam(Round round);
ListTeam *roundEnemyTeam(Round round);
void roundShowTurn(Round round, adrMember member);
bool roundHandleAction(Round &round, Graph &graph, ListArea areas,
                       adrMember member, bool &surrendered);    // false = action rejected

// ------------------------------------------------ turn-consuming actions ----
bool roundMove(adrMember member, adrVertex destination);        // push step, visitCount + 1
bool roundStepBack(adrMember member);                           // pop step
bool roundUseSkill(Round &round, Graph &graph, adrMember member);
void roundCastSmoke(adrMember member, adrVertex target);        // Controller, Kode 23
void roundPlaceTrap(Round round, adrMember member);             // Sentinel
void roundRecon(Graph graph, adrMember member, ListTeam enemies);   // Initiator, Kode 21
bool roundDash(adrMember member, adrVertex first, adrVertex second);  // Duelist
bool roundPlantSpike(Round &round, adrMember member);
bool roundDefuseSpike(Round &round, adrMember member);

// ------------------------------------------------------- after action -------
void roundResolveDuel(Round &round, adrMember member);          // Kode 23
void roundTriggerTrap(Round round, adrMember member);
void roundPickUpSpike(Round &round, adrMember member);

// --------------------------------------------------------- free actions -----
void roundShowAreaStatus(ListArea areas, Round round);          // MLL
void roundShowRecommendedRoute(Graph graph, adrMember member);  // Dijkstra to nearest site
void roundShowStepHistory(adrMember member);                    // SLL

// --------------------------------------------------------- round over -------
string roundFindMvp(Round round);
void roundShowResult(Round round, Side winner, RoundEnd reason);
void roundSaveResult(adrAccount player, Round round, Side playerSide,
                     Side winner, RoundEnd reason);             // SLL + DLL + history
void roundCleanup(Round &round, ListTeam &opponents, Graph &graph);

#endif // ROUND_H_INCLUDED
