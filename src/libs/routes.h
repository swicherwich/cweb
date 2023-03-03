#ifndef _ROUTES_H__
#define _ROUTES_H__

#define TABLE_SIZE 100 // size of the hash table

typedef struct Node {
    char* key;
    char* (*value)();
    struct Node* next;
} Node;

Node* table[TABLE_SIZE];

void route_bind(char* key, char* (*value)());
char* route_req(char* key);


#endif