//
//  hashmap.h
//  Lab9
//
//  Created by Todd Kulesza on 3/1/14.
//

#ifndef __hashmap_h__
#define __hashmap_h__

struct hashMap;

struct hashMap* createHashMap(int size);
void insertMap(struct hashMap *map, char *key, int value);
int containsKey(struct hashMap *map, char *key);
double tableLoad(struct hashMap *map);

#endif
