#ifndef LIST_H
#define LIST_H

typedef struct Node {
    char *lastName;
    char *firstName;
    char *midName;
    char *work;
    char *number;
    char *mail;

    struct Node *prev;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
} ContactList;

ContactList* create_list();
void insert_sorted(ContactList *list, char *lastName, char *firstName, char *midName, char *work, char *number, char *mail);
void remove_node(ContactList *list, Node *person);
Node* get_node_by_index(ContactList *list, int index);
void free_list(ContactList *list);
void sort_list(ContactList *list);
#endif