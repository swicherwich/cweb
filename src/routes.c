#include "libs/routes.h"
#include "libs/logs.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// hash function
unsigned int hash(char* key);

// function to add a key-function pair to the map
void route_bind(char* key, char* (*value)())
{
    unsigned int index = hash(key);
    Node* new_node = malloc(sizeof(Node*));
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;

    if (table[index] == NULL)
    {
        table[index] = new_node;
    } 
    else
    {
        Node* curr = table[index];
        while (curr->next != NULL) 
        {
            curr = curr->next;
        }
        curr->next = new_node;
    }

    log_info("Route [%s] added", key);
}

// function to get the function for a given key
char* route_req(char* key)
{
    unsigned int index = hash(key);
    Node* curr = table[index];
    while (curr != NULL) 
    {
        if (strcmp(curr->key, key) == 0) 
        {
            return curr->value();
        }
        curr = curr->next;
    }
    
    return NULL;
}

unsigned int hash(char* key)
{
    unsigned int hash = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        hash = hash * 31 + key[i];
    }
    return hash % TABLE_SIZE;
}
