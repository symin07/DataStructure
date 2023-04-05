//
//  main.c
//  Lab9
//
//  Created by Todd Kulesza on 3/1/14.
//

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "hashmap.h"

int main() {
    FILE *dictionaryFile;
    char line[100];
    char *nlptr;
    struct hashMap *dictionaryMap;
    clock_t begin, end;
    int count = 0;
    int size = 1000; // The number of buckets in our hashmap. You can change
    // this to time how long it takes to build hashmaps with very small or
    // very large numbers of buckets. (Try dropping it to 100, or increasing it
    // to 10,000.)
    
    // Create a hashMap to hold our dictionary
    dictionaryMap = createHashMap(size);
    
    // Open the textfile containing our dictionary words, read each word,
    // and add it to our hashmap.
    // You'll need to copy the "dictionary.txt" file to the same directory
    // as your executable for this to work!
    dictionaryFile = fopen("dictionary.txt", "r");
    // (Fun fact not at all related to this lab: we're using the 1934 edition
    // of Webster's dictionary. Why 1934? Because the copyright lapsed. Most
    // UNIX systems and Mac OS X use this same dictonary for their built-in
    // spell checking support)
    assert(dictionaryFile != NULL);
    begin = clock();
    while(fgets(line, sizeof(line), dictionaryFile)) {
        // Get rid of the newline character
        nlptr = strchr(line, '\n');
        if (nlptr) {
            *nlptr = '\0';
        }
        
        // If the word isn't already in the hash table, add it
        if (!containsKey(dictionaryMap, line)) {
            insertMap(dictionaryMap, line, 1);
        }
        count++;
    }
    end = clock();
    printf("It took %0.3f second(s) to build our hashmap.\n",
           (end - begin) / (double)CLOCKS_PER_SEC);
    printf("With %d words in %d buckets, the hashmap's load is %0.3f\n",
           count, size, tableLoad(dictionaryMap));
    
    // Close our file pointer
    fclose(dictionaryFile);
    
    // Now let the user check if a word is spelled correctly.
    printf("Enter a word (or press 'Return' to exit): ");
    while(fgets(line, sizeof(line), stdin)) {
        // Get rid of the newline character
        nlptr = strchr(line, '\n');
        if (nlptr) {
            *nlptr = '\0';
        }

        // If the line is empty, exit the program.
        if (strlen(line) == 0) {
            printf("Goodbye!\n");
            break;
        }
        
        // Check to see if the user's word exists in our hashmap. If it does,
        // tell them that it's spelled correctly. Otherwise, tell them it's
        // misspelled.
        // FIXME: you get to implement this
        
        // Prompt the user to enter another word
        printf("Enter a word (or press 'Return' to exit): ");
    }
    
    return 0;
}
