#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int roundindex(float x);

int main(void)
{
    string text = get_string("Text: ");
    int countl=0, countw=0, counts=0, count=0;
    int i,length;
    float index,L,S;

    length = strlen(text);

    //Count Letters
    for(i=0;i<length;i++)
    {
        if((text[i]>=65 && text[i]<=90) || (text[i]>=97 && text[i]<=122))
        {
            countl++;
        }
    }printf("Number of letters:: %i \n",countl);
    //Count sentence
    for(i=0;i<length;i++)
    {
        if(text[i]=='.' || text[i]=='?' || text[i]=='!')
        {
            counts++;
        }
    }printf("Number of Sentences : %i \n",counts);

    //Count Word
    for(i=0;i<length;i++)
    {
        if(text[i]<33 || text[i]>126 )
        {
            count++;
        }
    }countw=count+1;
    printf("Number of Word:%i \n",countw);

    //Process
    L=(countl/countw)*100;
    S=(counts/countw)*100;
    index = 0.0588 * L - 0.296 * S -15.8;
    int x=roundindex(index);
    //printf("%f \n",index);
    //printf("%i \n",x);
    if(x<1)
    {
        printf("Before Grade 1\n");
    }
    else if (x>=16)
        {
            printf("Grade 16+\n");
        }
        else
        {
            printf("Grade: %i \n",x);
        }
}

int roundindex(float x)
{
    int y = x;
    if((x+0.5)>=(y+1))
    {
        x=y+1;
    }
    else
    {
        x=y;
    }
    return x;
}
