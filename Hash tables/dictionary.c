// Implements a dictionary's functionality

#include <stdbool.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>


#include "dictionary.h"


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];
node *hashTable[N] = {NULL};
int words = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    unsigned int hashValue = hash(word);
    node *temp = hashTable[hashValue];
    while (temp != NULL)
    {
        if (strcasecmp(temp -> word, word) == 0)
        {
            return true;
        }
        temp = temp -> next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *f = fopen(dictionary, "r");
    if (f == NULL)
    {
        return false;
    }
    char word[LENGTH + 1] = {0};
    while (fscanf(f, "%s", word) != EOF)
    {
        unsigned int hashValue = hash(word);
        node *newNode = malloc(sizeof(node));
        if (newNode == NULL)
        {
            return false;
        }
        strcpy(newNode -> word, word);
        newNode -> next = hashTable[hashValue];
        hashTable[hashValue] = newNode;
        words++;

    }
    fclose(f);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return words;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    int countBuckets = 0;
    for (int i = 0; i < N; ++i)
    {
        node *temp = hashTable[i];
        while (hashTable[i] != NULL)
        {
            temp = temp -> next;
            free(hashTable[i]);
            hashTable[i] = temp;
        }
        if (hashTable[i] == NULL)
        {
            countBuckets++;
        }
    }
    if (countBuckets == N)
    {
        return true;
    }

    return false;
}