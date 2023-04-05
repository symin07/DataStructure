#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define TYPE char*
#define HASH(A) A-97

struct hlink{
    TYPE value;
    struct hlink *next;
};

struct hashTable{
    struct hlink** table;
    int tableSize;
    int count;
};


void initHashTable(struct hashTable *ht, int size)
{
    assert(size > 0);
    ht->table = malloc(sizeof(struct hlink*) * size);
    assert(ht->table != 0);
    
    ht->tableSize = size;
    ht->count = 0;
}
void _resizeHashTable(struct hashTable* ht)
{
    int size = ht->tableSize;
    struct hlink** tempTable = malloc(sizeof(struct hlink*) * size);
     for(int i = 0; i < size; i++)    
            tempTable[i] = ht->table[i];
    
    initHashTable(ht, size * 2);
    for(int i = 0; i < size; i++)
        addHashTable(ht, tempTable[i]->value);

}
void addHashTable(struct hashTable* ht, TYPE newValue)
{
    //compute hash value to find the correct bucket

    int hashIndex = (HASH(newValue[2])) % ht->tableSize;
    if(hashIndex < 0) hashIndex += ht->tableSize;

    struct hlink* newLink = (struct hlink*)malloc(sizeof(struct hlink));
    assert(newLink);
    newLink->value = newValue;
    newLink->next = ht->table[hashIndex];
    ht->table[hashIndex] = newLink; //add to bucket
    ht->count++;
    if((double)(ht->count/ht->tableSize) > 8.0)
        _resizeHashTable(ht);
}

int hashTableContains(struct hashTable *ht, TYPE element)
{
    int hashIndex = (HASH(element[2])) % ht->tableSize;
    if(hashIndex < 0) hashIndex += ht->tableSize;

    struct hlink* iterator =  ht->table[hashIndex];
    while(iterator != NULL && strcmp(iterator->value, element) != 0)
        iterator = iterator->next;
    if(iterator == 0 || strcmp(iterator->value, element) != 0)
        return 0;
    else if(strcmp(iterator->value, element) == 0)
        return 1;

}

void hashTableRemove(struct hashTable* ht, TYPE element)
{
    if(hashTableContains(ht, element) == 1)
    {
        int hashIndex = (HASH(element[2])) % ht->tableSize;
        if(hashIndex < 0) hashIndex += ht->tableSize;

        struct hlink* iterator =  ht->table[hashIndex];
        struct hlink* previous = iterator;
        while(iterator != NULL && strcmp(iterator->value, element) != 0)
        {
            previous = iterator;
            iterator = iterator->next;
        }
        if(previous == iterator){
            ht->table[hashIndex] = 0;
            free(iterator);
        }
        else{
            previous->next = iterator->next;
            free(iterator);
        }
    }else{
        printf("no element to remove! \n");
    }

}

void resizeTable(struct hashTable *ht)
{

}

int main()
{
    struct hashTable* ht = (struct hashTable*)malloc(sizeof(struct hashTable));
    initHashTable(ht, 4);
    addHashTable(ht, "Amina");
    addHashTable(ht, "Andy");
    addHashTable(ht, "Alessia");
    addHashTable(ht, "Alfred");
    addHashTable(ht, "Aspen");
    printf("1 == %d \n", hashTableContains(ht, "Alessia"));
    printf("1 == %d \n", hashTableContains(ht, "Amina"));
    printf("1 == %d \n", hashTableContains(ht, "Andy"));
    printf("1 == %d \n", hashTableContains(ht, "Aspen"));
    printf("1 == %d \n", hashTableContains(ht, "Alfred"));
    printf("0 == %d \n", hashTableContains(ht, "Anne"));
    addHashTable(ht, "Anne");
    addHashTable(ht, "Agnes");
    addHashTable(ht, "Alan");
    printf("1 == %d \n", hashTableContains(ht, "AlAlanfred"));
    printf("1 == %d \n", hashTableContains(ht, "Agnes"));
    hashTableRemove(ht, "Alfred");
    printf("Alfred erease 0 == %d \n", hashTableContains(ht, "Alfred"));
    hashTableRemove(ht, "Agnes");
    hashTableRemove(ht, "Aspen");
    hashTableRemove(ht, "Amina");
    printf("Agnes erease 0 == %d \n", hashTableContains(ht, "Agnes"));
    printf("Aspen erease 0 == %d \n", hashTableContains(ht, "Aspen"));
    printf("Amina erease 0 == %d \n", hashTableContains(ht, "Amina"));


}