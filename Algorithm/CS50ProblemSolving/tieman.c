#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 9

int preferences[MAX][MAX];

bool locked[MAX][MAX];
bool lock =true;

typedef struct
{
    int winner;
    int loser;
}
pair;
pair pairs[MAX * (MAX-1)/2];

string candidates[MAX];

int pair_count;
int k;

bool vote (int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
int comparator(const void *a, const void *b);

int main(int argc,string argv[])
{
    if(argc < 2)
    {
        printf("Ussage: ./tieman [candidate...]\n");
        return 1;
    }
    k = argc-1;
    if(k > MAX)
    {
        printf("Maximum of of candidate is: %i \n",MAX);
        return 2;
    }

    //Defaut Candidates[i] = name in argv[...];
    for(int i=0;i<k;i++)
    {
        candidates[i] = argv[i+1];
        //candidates[i].votes = 0;
    }
    //Defaut Locked[i][j] = false
    for(int i=0; i<k; i++)
    {
        for(int j=0; j<k; j++)
        {
            locked[i][j]=false;
            preferences[i][j] = 0;
        }
    }
    //Input
    pair_count = 0;
    int n = get_int("Number of votes: ");
    /*if(n>MAX_VOTERS)
    {
        printf("Maximum of voters is: %i",MAX_VOTERS);
    }*/
    int ranks[k];
    for(int i=0; i<n; i++)
    {

        for(int j=0; j<k; j++)
        {
            string name = get_string("Rank %i: ",j+1);
            if(!vote(j,name, ranks))
            {
                printf("Invaid vote!\n");
                return 3;
            }
        }
        printf("\n");
    }
    record_preferences(ranks);
    printf("\n");
    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}//end main

bool vote (int rank, string name, int ranks[])
{
    for(int i=0; i<k; i++)
    {
        if(strcmp(name,candidates[i])==0)
        {
            ranks[rank]=i;
            return true;
        }
    }
    return false;
}
void record_preferences(int ranks[])
{
    for(int i=0; i<k  ;i++)
    {
        for(int j=i+1; j<k; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
}
void add_pairs(void)
{
    for(int i=0 ; i<k; i++)
    {
        for(int j=i+1; j<k; j++)
        {
            if(preferences[i][j]>preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser =j;
                pair_count++;
            }
            else if(preferences[i][j]<preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser =i;
                pair_count++;
            }
        }
    }
}

int comparator(const void *a, const void *b)
{
    pair *ab= (pair*)a;
    pair *ba= (pair*)b;
    return (preferences[ba->winner][ba->loser] - preferences[ab->winner][ab->loser]);
}

void sort_pairs(void)
{
    qsort(pairs,pair_count,sizeof(pair),comparator);
}
bool has_cycle(int winner, int loser)
{
    while(winner!=-1 && winner != loser)
    {
        bool found = false;
        for(int i=0; i<k ; i++)
        {
            if(locked[i][winner])
            {
                found = true;
                winner = i;
            }
        }
        if(!found)
        {
            winner = -1;
        }
    }
    if(winner == loser)
    {
        return true;
    }
    return false;
}
void lock_pairs(void)
{
    for(int i=0; i<pair_count; i++)
    {
        if(!has_cycle(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
}

void print_winner(void)
{
    for(int col=0; col<MAX; col++)
    {
        bool found_source=true;
        for(int row=0; row<MAX; row++)
        {
            if(locked[row][col]==true)
            {
                found_source=false;
                break;
            }
        }
        if(found_source)
        {
            printf("Winner: %s \n",candidates[col]);
            return;
        }
    }
    return;
}






