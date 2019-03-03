#ifndef ACCOUNTFUNCTIONS_H
#define ACCOUNTFUNCTIONS_H

#include <sstream>
#include "time.h"
#include "io.h"

extern bool userLogin;

extern stringstream con;

extern string username;
extern string password;
extern int passLine;

void accountWizard();
void loginWizard();

#endif
