#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "hashMap.h"
struct hashLink
{
    void* key;
    void* value;
    struct hashLink* next;
};

typedef struct hashLink hashLink;

struct hashMap
{
    hashLink **table;
    int tableSize;
    int count;
};

void _initMap(struct hashMap *ht, int tableSize)
{
    int index;
    if(ht == NULL)
        return;
    ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
    ht->tableSize = tableSize;
    ht->count = 0;
    for(index = 0; index <tableSize; index++)
        ht->table[index] = NULL;
}

hashMap *createMap(int tableSize)
{
    assert(tableSize > 0);
    hashMap *ht;
    ht = malloc(sizeof(hashMap));
    assert(ht != 0);
    _initMap(ht, tableSize);
    return ht;
}

void _freeMap(struct hashMap *ht)
{
    assert(ht != 0);
    int index = 0;
    hashLink *current;

    while(index < ht->tableSize)
    {
        current = ht->table[index];
        
        while (current != 0)
        {
            current = current->next;
            free(current->key);
            free(current->value);
            free(current);
        }
        index++;
    }
    free(ht->table);
}

void deleteMap(hashMap *ht)
{
    assert(ht != 0);
    _freeMap(ht);
    free(ht);
}

void _setTableSize(struct hashMap *ht, int newTableSize, 
compator keyCompare, hashFuncPtr hashfunc)
[   
    hashLink ** oldTable = ht->table;
    int oldSize = ht->tableSize;
    hashLink *current, *last;
    _initMap(ht, newTableSize);

    for (int i = 0; i < oldSize; i++)
    {
        current = oldTable[i];
        
    }


]
