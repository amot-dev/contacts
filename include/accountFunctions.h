//ACCOUNTFUNCTIONS.H v1.0 BY ALEXANDER MOT
//Created 19/04/2017
//Updated 19/04/2017

#ifndef ACCOUNTFUNCTIONS_H
#define ACCOUNTFUNCTIONS_H

#include <sstream>
#include "../../include/Time.h"
#include "../../include/IO.h"

extern bool userLogin;

extern stringstream con;

extern string username;
extern string password;
extern int passLine;

void accountWizard();
void loginWizard();

#endif
