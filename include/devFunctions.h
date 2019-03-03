//DEVFUNCTIONS.H v1.0 BY ALEXANDER MOT
//Created 19/04/2017
//Updated 19/04/2017

#ifndef DEVFUNCTIONS_H
#define DEVFUNCTIONS_H

#include <sstream>
#include "../../include/Time.h"
#include "../../include/IO.h"

extern bool userLogin;

extern int selector;
extern char userYN;

extern stringstream con;

int getUserLine(string username);
void deleteUser(string deletedUser, int userLine);
void deletionWizard();
void devMenu();

#endif
