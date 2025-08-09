#include <stdio.h>

int main(void)
{
    //Decrale
    int height,i,j,k;
    printf("Height: "); scanf("%i",&height);

    //Input
    while( height<1 || height>8)
    {
       printf("Height: "); scanf("%i",&height);
    }

    //Process and Output
    for(i=height;i>0;i--)
    {
        for(j=0;j<i;j++)
        {
            printf(" ");
        }
        for(k=height;k>j-1;k--)
        {
            printf("#");
            if(k==j) break;
        }
        printf("\n");
    }
    printf("\n");

}




