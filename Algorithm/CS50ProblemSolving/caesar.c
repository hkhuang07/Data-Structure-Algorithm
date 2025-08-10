#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc , string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
        string p = get_string("Plaintext: ");
        string c = p;
        int length = strlen(p);
        int i,j;

        int k = atoi(argv[1]);
        //printf("k = %i ",k);

        for(i=0;i<length;i++)
        {
            //printf("p[%i] = %i ",i,p[i]);
            if(p[i]>='A'&& p[i]<='Z')
            {
                if((p[i]+k)<='Z')
                {
                    c[i]=p[i]+k;
                }
                else
                {
                    c[i]=((p[i]+k)%26);
                }

            }
            else if(p[i]>='a'&& p[i]<='z')
                {

                    {
                        if((p[i]+k)<='z')
                        {
                            c[i]=p[i]+k;
                        }
                        else
                        {
                            c[i]=((p[i]+k)%26);
                        }

                    }
                }
            else
            {
                c[i]=p[i];
            }
            //printf("argc = %i ",argc%k);
            //printf("c[%i] = %i ",i,c[i]);
            //printf("\n");
        }
        printf("Ciphertext: %s \n",c);
    return 0;
}


