#ifndef ADMINFUNCTIONS_H
#define ADMINFUNCTIONS_H

#include <sstream>
#include "time.h"
#include "io.h"

extern bool userLogin;

extern int selector;
extern char userYN;

extern stringstream con;

int getUserLine(string username);
void deleteUser(string deletedUser, int userLine);
void deletionWizard();
void adminMenu();

#endif
