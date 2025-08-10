#include <stdio.h>
#include <string.h>

int main(void)
{
    //Declare
    int n;
    int i,j,l,t,lo,hi;
    int count=0,sum=0,tmp=0;
    int choose;
    int a[16];
    long number;
    char cardtypes[17];

    //Input
    printf("Card Type: 1. American Express  2. MasterCard   3.VISA  :");
    scanf("%i",&choose);
	switch(choose)
    {
        case 0:
        {
            return 0;
        }

        case 1:
        {
            //Input
            strcpy(cardtypes,"American_Express");
            printf("%s\n",cardtypes);
            //Amerian Express Card has 15 digits
			n=15;
			//The 1st serial number of the Amerian Express card must be 3
			printf("The 1st Serial Number of the Amerian Express Card Must Be 3: ");
            a[0]=3;
            //The 2nd serial number of the Amerian Express card must be 4 or 7
           	do
			{
				printf("The 2nd Serial Number Of The Amerian Express Card Must Be 4 or 7: ");
				scanf("%i",&a[1]);
			}while(a[1]!=4&&a[1]!=7);
			//The number from 3 - 15 of the American Express card 
			for(i=2;i<n;i++)
            {	
		       	do
				{
					printf("The %ith Serial Number Of The Amerian Express Card Only 1 Digit: : ",i);
					scanf("%i",&a[i]);
				}while(a[i]>9);
            }
            //Process
            for(i=0;i<n;i++)
            {
                printf("%i",a[i]);
            }
            printf("\n");
            // Get numbers that starting with the number's second-to-last digit multiplied 2
            for(j=n-2;j>=0;j=j-2)
            {
                if(a[j]*2>9)
                {
                    lo=(a[j]*2)/10;
                    hi=(a[j]*2)%10;
                    t=hi+lo;
                }
                else
                {
                    t=a[j]*2;
                }
                sum=sum+t;
            }
            //Get numbers that were not multiplied by 2 (starting from the end):
            for(l=n-1;l>=0;l=l-2)
            {
                tmp=tmp+a[l];
            }
            printf("\n");

            sum=sum+tmp;

            printf("The Last Digit In That Sum :%i \n",sum);
            //Check Legit
            if(sum%10==0)
            {
                printf("- The Card is Legit!\n");
            }
            else
            {
                printf("- The Card is't Legit!\n");
            }

            break;
        }

        case 2:
        {
            //Input Number Digits String
            strcpy(cardtypes,"MasterCard");
            printf("%s\n",cardtypes);
            //Master Card has 16 digits
            n=16;
            //The 1st serial number of the Master Card card must be 5
            a[0]=5;
            //The 2st serial number of the Master Card card must be 1,2,3,4 or 5
			do
			{
				printf("Must Be 1,2,3,4 Or 5: ");
            	scanf("%i",&a[1]);
			}while(a[1]<1||a[1]>5);
			//The number from 3 - 16 of the Master Card 
           	for(i=2;i<n;i++)
            {	
		       	do
				{
					printf("Enter only 1 digit: ");
					scanf("%i",&a[i]);
				}while(a[i]>9);
            }
			//Process
            for(i=0;i<n;i++)
            {
                printf("%i",a[i]);
            }
            printf("\n");
            // Get numbers that starting with the number's second-to-last digit multiplied 2
            for(j=n-2;j>=0;j=j-2)
            {
                if(a[j]*2>9)
                {
                    lo=(a[j]*2)/10;
                    hi=(a[j]*2)%10;
                    t=hi+lo;
                }
                else
                {
                    t=a[j]*2;
                }
                sum=sum+t;
            }
            //Get numbers that were not multiplied by 2 (starting from the end):
            for(l=n-1;l>=0;l=l-2)
            {
                tmp=tmp+a[l];
            }
            printf("\n");

            sum=sum+tmp;

            printf("The Last Digit In That Sum :%i \n",sum);
            //Check Legit
            if(sum%10==0)
            {
                printf("- The Card is Legit!\n");
            }
            else
            {
                printf("- The Card is't Legit!\n");
            }
            break;
        }

        case 3:
        {
            strcpy(cardtypes,"VISA");
            printf("%s\n",cardtypes);
            //VISA card has 13-16 digits
            do
            {
                printf("Number of Digits Must Be 13 Or 16: ");
                scanf("%i",&n);
            }while(n!=16&&n!=13);
			//The 1st serial number of the VISA card must be 4
			a[0]=4;
			//The number from 2 - (13 or 16) of the VISA card 
            for(i=1;i<n;i++)
            {
                do
				{
					printf("Enter only 1 digit: ");
					scanf("%i",&a[i]);
				}while(a[i]>9);
            }
			//Process
            for(i=0;i<n;i++)
            {
                printf("%i",a[i]);
            }
            printf("\n");
            // Get numbers that starting with the number's second-to-last digit multiplied 2
            for(j=n-2;j>=0;j=j-2)
            {
                if(a[j]*2>9)
                {
                    lo=(a[j]*2)/10;
                    hi=(a[j]*2)%10;
                    t=hi+lo;
                }
                else
                {
                    t=a[j]*2;
                }
                sum=sum+t;
            }
            //Get numbers that were not multiplied by 2 (starting from the end):
            for(l=n-1;l>=0;l=l-2)
            {
                tmp=tmp+a[l];
            }
            printf("\n");

            sum=sum+tmp;

            printf("The Last Digit In That Sum :%i \n",sum);
            //Check Legit
            if(sum%10==0)
            {
                printf("- The Card is Legit!\n");
            }
            else
            {
                printf("- The Card is't Legit!\n");
            }
            break;
        }
    }
}

