// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

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
unsigned int size_of_table = 0;
// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int hash_number = hash(word);
    for (node *temp = table[hash_number]; ; temp = temp->next)
    {
        if (temp == NULL)
        {
            break;
        }
        else if (strcasecmp(word, temp->word) == 0)
        {
            //printf("string compared fine\n");
            return true;
        }
    }
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int n = 0;
    static const char *const alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *p = strchr(alphabet, toupper((unsigned char)word[0]));

    if (p)
    {
        n = p - alphabet;
    }

    return n;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //opening files and making sure they exist
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char *s = malloc(sizeof(char) * LENGTH);
    int hash_number = 0;
    
    //null pointers on tables
    char str[2];
    str[1] = '\0';
    for (int i = 0; i < N; ++i)
    {
        table[i] = malloc(sizeof(node));
        str[0] = ((char) 65 + i);
        strcpy(table[i]->word, str);
        table[i]->next = NULL;
    }

    while (!feof(file))
    {
        fscanf(file, "%s\n", s);
        
        hash_number = hash(s);
        for (node *temp = table[hash_number]->next; ; temp = temp->next)
        {
            if (temp == NULL)
            {
                temp = malloc(sizeof(node));
                strcpy(temp->word, s);
                
                ++size_of_table;
                temp->next = table[hash_number];
                table[hash_number] = temp;
                break;
            }
        }
    }
    
    //free memory for string
    fflush(file);
    fclose(file);
    free(s);

    // TODO
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return size_of_table;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; ++i)
    {
        for (node *temp = table[i]; temp != NULL;)
        {
            temp = table[i]->next;
            //printf("%p", table[i]);
            free(table[i]);
            //printf("%p", table[i]);
            table[i] = temp;
        }
        
    }
    // TODO
    return true;
}
