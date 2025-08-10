#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

//void Do_substitution(string k);
//void  aphabet_arr_value(char pos,string key);

int main(int argc, string argv[])
{
    string k = argv[1];
    int length_key = strlen(k);
    int i,j;

    /*Check p[] elements
    for(i =0; i<length; i++)
    {
        printf("p[%i]: %c=%i ",i,p[i],p[i]);
        printf("\n");
    }
    //Check k[] elements
    printf("k      : %s",k);
    printf("\n");*/

    if(argc == 2)
    {
        if(length_key  == 26)
        {
            for(i=0;i<length_key;i++)
            {
                if(!isalpha(k[i]))
                {
                    printf("Key must contain 26 characters.\n");
                    return 1;
                }
                for(j=i+1;j<length_key;j++)
                {
                    if(toupper(k[j])==toupper(k[i]))
                    {
                         printf("Key must not contain repeated alphabets.\n");
                         return 1;
                    }
                }
            }
            Do_substitution(k);
         }
         else
         {
             printf("Key must contain 26 characters.\n");
             return 1;
         }
    }
    else
    {
        printf("Usage: ./substitution key \n");
        return 1;
    }
    return 0;
}


void Do_substitution(string k)
{
    string p = get_string("Plaintext: ");
                   printf("Ciphertext: ");
    int length = strlen(p);
    for(int i=0; i<length; i++)
    {
        if((p[i]>='A' && p[i]<='Z') || (p[i]>='a' && p[i]<='z'))
        {
            char x=p[i];
            if(islower(p[i]))
            {
                aphabet_arr_value(tolower(x),k);
            }
            else
            {
                aphabet_arr_value(toupper(x),k);
            }
        }
        else
        {
            printf("%c ",p[i]);
        }
    }
    printf("\n");
}


void  aphabet_arr_value(char pos,string key)
{
    string aphal = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for(int i=0;i<strlen(aphal);i++)
    {
        if(islower(pos))
        {
            if(pos==tolower(aphal[i]))
            {
                printf("%c",tolower(key[i]));
            }
        }
        else
        {
            if(aphal[i]))(pos==touppe
            {
                 printf("%c",toupper(key[i]));
            }
        }

    }

}



