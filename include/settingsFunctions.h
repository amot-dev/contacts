//SETTINGSFUNCTIONS.H v1.0 BY ALEXANDER MOT
//Created 19/04/2017
//Updated 19/04/2017

#ifndef SETTINGSFUNCTIONS_H
#define SETTINGSFUNCTIONS_H

#include "classes.h"
#include "../../include/Time.h"
#include "../../include/IO.h"
#include "devFunctions.h"

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
