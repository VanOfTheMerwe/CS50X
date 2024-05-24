// Implements a dictionary's functionality

#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
//*Number of "buckets" in the hash table
const unsigned int N = 100000;

// Hash table
node *table[N];

int dictSize = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    //*Hash word to obtain value
    int hashValue = hash(word);

    //*Access the link list
    node *n = table[hashValue];

    //?Look for the word in the link list
    while (n != NULL)
    {
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
        }
        n = n->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    //*Sum value
    long sum = 0;

    //*Checks that all are lower case to make it easier
    for (int dog = 0; dog < strlen(word); dog++)
    {
        sum += tolower(word[dog]);
    }
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //*Open file directory
    FILE *dictPointer = fopen(dictionary, "r");

    //*If dictionary is empty
    if (dictionary == NULL)
    {
        printf("Error opening %s\n", dictionary);
        return false;
    }
    //*Make word array
    char nextWord[LENGTH + 1];

    //*Read only one word at a time from file
    while (fscanf(dictPointer, "%s", nextWord) != EOF)
    {
        //*Create new node for each string
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        //*Use strcopy to copy word or string into node
        strcpy(n->word, nextWord);

        //*Get the hash value
        int hashValue = hash(nextWord);

        //*Insert node at the correct location in the hash table
        n->next = table[hashValue];
        table[hashValue] = n;
        dictSize++;
    }
    //*Close the file
    fclose(dictPointer);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    //*Track the number of words entered into the variable
    return dictSize;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    //*Rewrite data in hash table and free nodes
    for (int dog = 0; dog < N; dog++)
    {
        node *n = table[dog];

        //*Loop through link list
        while (n != NULL)
        {
            node *tmp = n;

            n = n->next;

            // Free tmp
            free(tmp);
        }
        if (n == NULL && dog == N - 1)
        {
            return true;
        }
    }
    return false;
}
