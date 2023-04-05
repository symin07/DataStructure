//
//  hashmap
//  Lab9
//
//  Created by Todd Kulesza on 3/1/14.
//

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"

struct hashLink {
    char key[100];
    int value;
    struct hashLink *next; // Pointer to the next hashLink in this bucket
};

struct hashMap {
    struct hashLink **table; // array of pointers to hashLinks
    int tableSize; // number of buckets in the table
    int count; // number of hashLinks in the table
};

// Return a hash for 'str'.
unsigned long _hashString(char *str) {
    // Use the DJB2 hashing algorithm
    unsigned long hash = 5381;
    int c;
    
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    
    return hash;
}

struct hashMap* createHashMap(int size) {
    int i;
    
    // Allocate memory for the hashMap struct
    struct hashMap *map = malloc(sizeof(struct hashMap));
    
    // Allocate memory for 'size' hashLink pointers
    map->table = malloc(sizeof(struct hashLink *) * size);
    map->tableSize = size; // This is the number of buckets in the hashMap
    map->count = 0; // We start out with 0 items in the hashMap
    
    // Initialize each bucket to a NULL pointer
    for (i = 0; i < size; i++) {
        map->table[i] = NULL;
    }
    
    return map;
}

// 'map' should be an existing hashMap. 'key' is the word to add to 'map'.
// 'value' is the value associated with the key (but in this lab we really
// don't use 'value', so it doesn't matter what it is).
void insertMap(struct hashMap *map, char *key, int value) {
    
    // FIXME: You get to implement this!
    
    // Figure out which bucket 'key' belongs in, then create a hashLink, copy
    // 'key' and 'value' into it, and insert it at the appropriate place in the
    // hashmap. Don't worry about what to do if 'key' is already in the hashmap
    // (this is different behavior than Assignment #6!)
    // Hint: you'll need to use strcpy to copy 'key' into the new hashLink.
}

// Return 1 if 'key' exists in 'map', otherwise return 0.
int containsKey(struct hashMap *map, char *key) {
    int retval = 0;

    // FIXME: You get to implement this.
    
    // To find the key, figure out which bucket it should be in, then loop
    // through the items in that bucket. If one of them matches 'key', return 1.

    
    return retval;
}

// Return the ratio of: (number of hashlinks) / (number of buckets)
double tableLoad(struct hashMap *map) {
    // FIXME: You get to implement this.
    
    return 0;
}
