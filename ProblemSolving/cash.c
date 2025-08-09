//#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Declare
    int change;
    int w=0,x=0,y=0,z=0;
    //Input
    change=get_int("Change: ");
    if(change<=0)
    {
        do
        {
            change=get_int("Change Owed Must Be >=0 : ");
        }while(change<=0);
    }
    //Process
    w = change/25;
    change = change - (w*25);

    x = change/10;
    change = change - (x*10);

    y = change/5;
    change = change - (y*5);

    z = change/1;
    change = change - (z*1);
    //Output
    printf("%i \n",(w+x+y+z));

}


