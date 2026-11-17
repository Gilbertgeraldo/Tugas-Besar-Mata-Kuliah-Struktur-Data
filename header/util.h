#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED
#include "adt.h"

// ------------------------------------------------------------- strings ------
string utilToLower(string text);
bool utilEqualsIgnoreCase(string a, string b);          // names are case-insensitive
bool utilIsAlphanumeric(string text);                   // username rule

// --------------------------------------------------------------- input ------
int utilReadInt(string prompt, int min, int max);       // repeats until valid
string utilReadLine(string prompt);                     // rejects empty input
bool utilConfirm(string prompt);                        // (y/n)
void utilWaitForEnter();

// -------------------------------------------------------------- output ------
void utilPrintDivider(char symbol, int width);
string utilAgentRoleName(AgentRole role);
string utilLocationTypeName(LocationType type);
string utilSideName(Side side);
string utilRoundEndName(RoundEnd reason);

// ---------------------------------------------------------------- misc ------
int utilRandomInt(int min, int max);

#endif // UTIL_H_INCLUDED
