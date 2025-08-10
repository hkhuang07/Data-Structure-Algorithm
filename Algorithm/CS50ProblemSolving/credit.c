#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string number = get_string("Number: ");
    int length =strlen(number);
    int i,j,l,t,lo,hi;
    int count=0,tmp=0,sum=0;

    for(i=0; i < length; i++)
    {
        printf("%c",number[i]);
    }
    printf("\n");

    switch(length)
    {
        case 15:
        {
            printf("Amerrican Express \n");

            // Get numbers that starting with the number's second-to-last digit multiplied 2
            for (j = length - 2; j >= 0; j = j - 2)
            {
                if ((number[j]-48) * 2 > 9)
                {
                    lo = ((number[j]-48) * 2) / 10;
                    hi = ((number[j]-48) * 2) % 10;
                    t = hi + lo;
                }
                else
                {
                    t = ((number[j]-48) * 2);
                }
                sum = sum + t;
            }
            // Get numbers that weren’t multiplied by 2 (starting from the end):
            for (l = length - 1; l >= 0; l = l - 2)
            {
                tmp = tmp + (number[j]-48);
            }

            sum = sum + tmp;

            printf("The Last Digit In That Sum :%i \n", sum);
            // Check Legit
            if (sum % 10 == 0)
            {
                printf("- The Card is Legit!\n");
            }
            else
            {
                printf("- The Card is't Legit!\n");
            }
            break;
        }
        case 13:
        {
            printf("VISA \n");
                    // Get numbers that starting with the number's second-to-last digit multiplied 2
                    for (j = length - 2; j >= 0; j = j - 2)
                    {
                        if ((number[j]-48) * 2 > 9)
                        {
                            lo = ((number[j]-48) * 2) / 10;
                            hi = ((number[j]-48) * 2) % 10;
                            t = hi + lo;
                        }
                        else
                        {
                             t = ((number[j]-48) * 2);
                        }
                            sum = sum + t;
                    }
                    // Get numbers that weren’t multiplied by 2 (starting from the end):
                    for (l = length - 1; l >= 0; l = l - 2)
                    {
                        tmp = tmp + (number[l]-48);
                    }

                    sum = sum + tmp;

                    printf("The Last Digit In That Sum :%i \n", sum);
                    // Check Legit
                    if (sum % 10 == 0)
                    {
                        printf("- The Card is Legit!\n");
                    }
                    else
                    {
                        printf("- The Card is't Legit!\n");
                    }
            break;
        }
        case 16:
        {
                //number[0]=4
                if(number[0]==52)
                {
                    printf("VISA \n");
                    // Get numbers that starting with the number's second-to-last digit multiplied 2
                    for (j = length - 2; j >= 0; j = j - 2)
                    {
                        if ((number[j]-48) * 2 > 9)
                        {
                            lo = ((number[j]-48) * 2) / 10;
                            hi = ((number[j]-48) * 2) % 10;
                            t = hi + lo;
                        }
                        else
                        {
                            t = ((number[j]-48) * 2);
                        }
                        sum = sum + t;
                    }
                    // Get numbers that weren’t multiplied by 2 (starting from the end):
                    for (l = length - 1; l >= 0; l = l - 2)
                    {
                        tmp = tmp + (number[l]-48);
                    }

                    sum = sum + tmp;

                    printf("The Last Digit In That Sum :%i \n", sum);
                    // Check Legit
                    if (sum % 10 == 0)
                    {
                        printf("- The Card is Legit!\n");
                    }
                    else
                    {
                        printf("- The Card is't Legit!\n");
                    }
                }
                else
                {
                    //number[0]=5
                    if(number[0]==53)
                    {
                        printf("MasterCard \n");
                        // Get numbers that starting with the number's second-to-last digit multiplied 2
                        for (j = length - 2; j >= 0; j = j - 2)
                        {
                            if ((number[j]-48) * 2 > 9)
                            {
                                lo = ((number[j]-48) * 2) / 10;
                                hi = ((number[j]-48) * 2) % 10;
                                t = hi + lo;
                            }
                            else
                            {
                                t = ((number[j]-48) * 2);
                            }
                            sum = sum + t;
                        }
                        // Get numbers that weren’t multiplied by 2 (starting from the end):
                        for (l = length - 1; l >= 0; l = l - 2)
                        {
                            tmp = tmp + (number[l]-48);
                        }

                        sum = sum + tmp;

                        printf("The Last Digit In That Sum :%i \n", sum);
                        // Check Legit
                        if (sum % 10 == 0)
                        {
                            printf("- The Card is Legit!\n");
                        }
                        else
                        {
                            printf("- The Card is't Legit!\n");
                        }
                    }
                    else
                        printf("Invalid Card Code ! \n");
                }
                break;
        }

    }
}

