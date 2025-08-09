#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#define MAX 9

typedef struct
{
    string name;
    int votes;
}
candidate;
candidate candidates[MAX];

bool vote(string name);
void print_winner(void);

int k;

int main(int argc, string argv[])
{
    int i,j;

    if(argc<1)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    k = argc-1;
    if(k>MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    for(i=0; i<k ; i++)
    {
        candidates[i].name = argv[i+1];
        //printf("c[%i].name %s \n",i, candidates[i].name);
        candidates[i].votes = 0;
        //printf("c[%i].votes %i \n",i, candidates[i].votes);
    }
    //
    int n = get_int("Number of voters: ");
    for(i=0 ; i<n ; i++)
    {
        string namevote = get_string("vote: ");
        //printf("namevote: %s \n", namevote);
        if(!vote(namevote))
        {
            printf("Invaid vote \n");
        }
    }
    print_winner();
}
 bool vote(string name)
 {
    for(int i=0;i<k;i++)
    {
        if(strcmp(candidates[i].name,name)==0)
        {
            candidates[i].votes++;
            //printf("c[%i].votes %i \n",i,candidates[i].votes);
            return true;
        }
    }
    return false;
 }

 void print_winner(void)
 {
    int i;
    int max=0;
    for( i=0; i<k ;i++)
    {
        if(candidates[i].votes >  max)
        {
            max = candidates[i].votes;
        }
    }
    for( i=0; i<k ;i++)
    {
        if(candidates[i].votes == max)
        {
            printf("%s \n", candidates[i].name);
        }
    }
    printf("\n");
    return;
 }




