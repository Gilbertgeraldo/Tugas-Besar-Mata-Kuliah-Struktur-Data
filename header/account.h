#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED
#include "adt.h"

// SLL account

// ---------------------------------------------------------- primitives ------
void accountCreateList(ListAccount &list);
adrAccount accountAllocate(string username, string password, AccountRole role);
void accountDeallocate(adrAccount &node);               // also frees its team & history
void accountInsertLast(ListAccount &list, adrAccount node);
void accountDeleteFirst(ListAccount &list, adrAccount &node);
void accountDeleteAfter(ListAccount &list, adrAccount prec, adrAccount &node);
adrAccount accountFind(ListAccount list, string username);
adrAccount accountFindPrev(ListAccount list, adrAccount target);
int accountCount(ListAccount list);
int accountCountAdmins(ListAccount list);
void accountPrint(ListAccount list);                    // A4.1
void accountClear(ListAccount &list);

// ------------------------------------------------------ authentication ------
adrAccount accountAuthenticate(ListAccount list, string username, string password);  // Kode 7
adrAccount accountLogin(ListAccount list);              // prompt, max 3 attempts
bool accountIsUsernameValid(ListAccount list, string username);
bool accountIsPasswordValid(string password, string confirmation);
bool accountRegister(ListAccount &list, AccountRole role);  // PLAYER: registration, ADMIN: A4.2

// ---------------------------------------------------------- management ------
bool accountRemove(ListAccount &list, adrAccount target, adrAccount current);  // A4.3, Kode 9
void accountResetPassword(adrAccount target, string newPassword);              // A4.4
bool accountChangePassword(adrAccount account, string oldPassword,
                           string newPassword, string confirmation);           // A6 / P7
double accountGetWinRate(adrAccount account);

// ------------------------------------------------------------- screens ------
void accountShowDetail(adrAccount account);             // A4.5
void accountShowSorted(ListAccount list, SortKey key, bool ascending);  // A4.6
void accountShowProfile(adrAccount account);            // A6 / P7
void accountShowLeaderboard(ListAccount list, adrAccount current);      // P6.1
void accountShowPersonalStats(adrAccount account);      // P6.2

#endif // ACCOUNT_H_INCLUDED
