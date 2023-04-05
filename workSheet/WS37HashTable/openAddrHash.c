#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define TYPE char
#define HASH(A) A-97

struct openHashTable{
    TYPE** table;
    int tableSize;
    int count;
};

void initOpenHashTable(struct openHashTable* ht, int size)
{
    int i;
    assert(size > 0);
    ht->table = (TYPE **)malloc(size * sizeof(TYPE*));
    assert(ht->table != 0);
    for(int i = 0; i < size; i++)
        ht->table[i] = 0; /*initialize empty*/
    ht->tableSize = size;
    ht->count = 0;
}

int openHashTableSize(struct openHashTable *ht)
{
    return ht->count;
}
/*
void _resizeOpenHashTable(struct openHashTable *ht)
{
    int size = ht->tableSize;
    TYPE** temp = (TYPE **)malloc(size * sizeof(TYPE*));
    for(int i = 0; i < size; i++)    
            temp[i] = ht->table[i];

    initOpenHashTable(ht, size * 2);
    for(int i = 0; i < size; i++)
        if(temp[i] != 0)
            openHashTableAdd(ht, temp[i]);

}
*/
void _resizeOpenHashTable(struct openHashTable *ht)
{
    int size = ht->tableSize * 2;
    ht->table = (TYPE **)malloc(size * sizeof(TYPE*));
    ht->tableSize = size;
}


void openHashTableAdd(struct openHashTable* ht, TYPE* newValue)
{
    int idx;
    ht->count++;
    /* Make sure we have space and under the load factor threshold*/ 
    if (((double) ht->count/ht->tableSize) > 0.75)
        _resizeOpenHashTable(ht);
    
    
    idx = (HASH(newValue[2])) % ht->tableSize;

   // if(idx < 0) 
        //idx += ht->cap;
    while(ht->table[idx] != 0)
        idx++;
    ht->table[idx] = newValue;
}





int openHashTableBagContains(struct openHashTable *ht, TYPE* newValue)
{
    int idx;
    idx = (HASH(newValue[2])) % ht->tableSize;
    //if(idx < 0)
        //idx += ht->cap;
    int iterator = idx;
    while(strcmp(ht->table[iterator], newValue) != 0)
        iterator++;
    if(idx == iterator || iterator < ht->tableSize)
        return 1;
    else return 0;

}

int main()
{
    struct openHashTable* ht;
    initOpenHashTable(ht, 8);
    openHashTableAdd(ht, "Amina");
    openHashTableAdd(ht, "Andy");
    openHashTableAdd(ht, "Alessia");
    openHashTableAdd(ht, "Alfred");
    openHashTableAdd(ht, "Aspen");
    openHashTableAdd(ht, "Anne");
    openHashTableAdd(ht, "Agnes");

}



