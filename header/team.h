#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED
#include "adt.h"

// DLL team (My Team and the temporary opponent team)
const int TEAM_MAX_SIZE = 5;

// ---------------------------------------------------------- primitives ------
void teamCreateList(ListTeam &team);
adrMember teamAllocateMember(adrAgent agent);           // zeroed stats, points to pool node
void teamDeallocateMember(adrMember &member);           // also clears its step history
bool teamIsEmpty(ListTeam team);
void teamInsertFirst(ListTeam &team, adrMember member);
void teamInsertLast(ListTeam &team, adrMember member);
void teamInsertAfter(ListTeam &team, adrMember prec, adrMember member);
void teamDeleteFirst(ListTeam &team, adrMember &member);
void teamDeleteLast(ListTeam &team, adrMember &member);
void teamDeleteAfter(ListTeam &team, adrMember prec, adrMember &member);
void teamDeleteNode(ListTeam &team, adrMember member);  // Kode 10, all 4 cases
adrMember teamFind(ListTeam team, string agentName);
adrMember teamFindByAgent(ListTeam team, adrAgent agent);
void teamPrintForward(ListTeam team);                   // P3.1
void teamPrintBackward(ListTeam team);                  // P3.1
void teamClear(ListTeam &team);

// ------------------------------------------------------------ features ------
bool teamAddMember(ListTeam &team, adrAgent agent,
                   InsertPosition position, string afterName);  // P3.2
bool teamRemoveMember(ListTeam &team, string agentName);        // P3.3
void teamBrowse(ListTeam team);                                 // P3.4
void teamSwapMembers(ListTeam &team, adrMember a, adrMember b); // P3.5, Kode 11
void teamSort(ListTeam &team, SortKey key, bool ascending);     // P3.6, insertion sort (S1)
void teamShowAgentStats(ListTeam team);                         // P3.7
adrMember teamFindMostKills(ListTeam team);                     // P6.2

// ------------------------------------------------------------ in match ------
adrMember teamNextAlive(ListTeam team, adrMember lastMoved);    // Kode 14, circular
int teamCountAlive(ListTeam team);

#endif // TEAM_H_INCLUDED
