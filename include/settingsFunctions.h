#ifndef SETTINGSFUNCTIONS_H
#define SETTINGSFUNCTIONS_H

#include "classes.h"
#include "time.h"
#include "io.h"
#include "adminFunctions.h"

extern bool forceLog;

extern int selector;
extern char userYN;

extern stringstream con;

extern string username;
extern string password;
extern int passLine;

extern config rules;

void passwordWizard();
void configWizard();
void contactClearWizard();
void settingsMenu();

#endif
