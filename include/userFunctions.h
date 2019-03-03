#ifndef USERFUNCTIONS_H
#define USERFUNCTIONS_H

#include "time.h"
#include "io.h"
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
