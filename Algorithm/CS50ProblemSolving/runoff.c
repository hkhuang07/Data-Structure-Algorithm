#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#define MAX_CANDIDATES 9
#define MAX_VOTERS 100

typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;
candidate candidates[MAX_CANDIDATES];

int preferences[MAX_VOTERS][MAX_CANDIDATES];
int k;
int n;

bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int minvotes);
void eliminated(int minvote);

int main(int argc, string argv[])
{
    //Check Argc
    if(argc < 2)
    {
        printf("Usage: ./runoff [...]");
        return 1;
    }
    k = argc - 1;
    if(k > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for(int i=0; i<k ; i++)
    {
        candidates[i].name = argv[i+1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }
    //Input
    n = get_int("Number of voters: ");
    if(n > MAX_VOTERS)
    {
            printf("Maximum number of voters is %i\n", MAX_VOTERS);
            return 3;
    }

    for(int i=0;i<n;i++) // Browse each vote
    {
        for(int j=0;j<k;j++)    //Brow each rank
        {
            string name = get_string("Rank %i : ",(j+1));

            if(!vote(i,j,name))
            {
                printf("Invalid Vote !");
                return 4;
            }
        }

        printf("\n");
    }
    while(true)
    {
        tabulate();

        bool won = print_winner();
        if(won)
        {
            break;
        }
        int min = find_min();
        bool tie = is_tie(min);

        if(tie)
        {
            for(int i=0; i<k; i++)
            {
                if(candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        eliminated(min);

        for(int i=0; i<k; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;

}


bool vote(int voter, int rank, string name)
{
    for(int i=0; i<k ;i++) //browse each voter i
    {

        if(strcmp(name,candidates[i].name)==0) //found then update votes
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

void tabulate(void)
{
    for(int i=0; i<n ; i++ )
    {
        for(int j=0; j<k ; j++)
        {
            if(candidates[i].eliminated == false)
            {
                candidates[preferences[i][j]].votes++;
            }
        }
    }
    return;
}
bool print_winner(void)
{
    for(int i=0; i<k; i++)
    {
        string most = candidates[i].name;
        if(candidates[i].votes > n/2)
        {
            printf("Winner %s\n", most);
            return true;
        }
    }
    return false;
}

int find_min(void)
{
    int minvotes = n;
    for(int i=0; i<k;i++)
    {
        if(candidates[i].eliminated == false && candidates[i].votes>minvotes)
        {
            minvotes = candidates[i].votes;
        }
    }
    return 0;
}

bool is_tie(int minvotes)
{
    for(int i=0; i<k;i++)
    {
        if(candidates[i].eliminated == false && candidates[i].votes!=minvotes)
        {
            return false;
        }
    }
    return true;
}
void eliminated(int minvotes)
{
    for(int i=0; i<k; i++)
    {
        if(candidates[i].eliminated == false && candidates[i].votes==minvotes)
        {
            candidates[i].eliminated = true;
        }
    }
    return ;
}
