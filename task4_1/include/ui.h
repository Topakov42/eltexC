#ifndef UI_H
#define UI_H

#include "list.h"

char *writeConsole(char* prompt);
void print_list(ContactList *list);
Node* pickPerson(ContactList *list);
void editPerson(Node *person);
void addNewContact(ContactList *list);

#endif