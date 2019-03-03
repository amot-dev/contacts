//USERFUNCTIONS.H v1.0 BY ALEXANDER MOT
//Created 19/04/2017
//Updated 19/04/2017

#ifndef USERFUNCTIONS_H
#define USERFUNCTIONS_H

#include "../../include/Time.h"
#include "../../include/IO.h"
#include "classes.h"

extern int selector;
extern char userYN;

extern string username;
extern string password;
extern int passLine;

extern config rules;

void listContacts();
void listContactsFancy(person contact);
person getContact(string contactName);
void contactViewer();
void contactEditWizard();
void contactRemoveWizard();
void contactAddWizard();

#endif
