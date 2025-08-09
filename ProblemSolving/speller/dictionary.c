// Implements a dictionary's functionality
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int TABLE_SIZE = 50000;
const unsigned int N = 26;

// Hash table
node *table[TABLE_SIZE];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    //return true if found else return false
    int index = hash(word);
    //Make a cursor node which points to the head of the hash table
    node *cursor = table[index];
    //for loop to go through the list intil the final node is reached
    for (node *temp = cursor; temp != NULL; temp = temp->next)
    {
        if(strcasecmp(temp->word,word)==0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int hashvalue = 0;
    for(int i =0 ;i < strlen(word); i++)
    {
        hashvalue += tolower(word[i]);
        hashvalue = (hashvalue * tolower(word[i]))%TABLE_SIZE;
    }
    //return toupper(word[0]) - 'A';
    return hashvalue;
}

int counter = 0 ;
// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //Open the dictionary file
    FILE *source = fopen(dictionary, "r");
    if(source == NULL)
    {
        fprintf(stderr, "There has been an error");
        return false;
    }
    //Read each word in the file
    //worldlist is character array of words
    char  wordlist[LENGTH + 1];
    //while fscanf != EOF print the words into the characters array word
    while(fscanf(source, "%s",wordlist) != EOF)
    {
        //Keep track of how many nodes are being made
        counter ++;
        //for each new node allocate memorry
        node *newNode = malloc(sizeof(node));
        //check for null
        if(newNode == NULL)
        {
            return 1;
        }
        //Add each word to the hash table
        //Initialize the new node bt copying the word to the node
        strcpy(newNode->word,wordlist);
        newNode->next = NULL;
        //Adđ to hash table each element of the hashtable is a linked list!
        //If index != NULL newNode->word points to the old head of the list
        int index = hash(wordlist);
        if(table[index] == NULL)
        {
            table[index] = newNode;
        }
        else
        {
            //makes the next the new head
            newNode->next = table[index];
            //head points to the new node.
            table[index] = newNode;
        }
    }
    //Close the dictionary file
    fclose(source);
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    //For each of hash table 'buckets' the memory must be free'd
    //Make a cursor which points to the head node. this cursor will word through the linked list making each = NULL, freeing the memory
    node *tmp = NULL;
    node *cursor = NULL;
    for(int i =0; i< TABLE_SIZE; i++)
    {
        cursor = table[i];
        while(cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
        }
    }
    return false;
}
