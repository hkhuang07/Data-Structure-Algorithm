
#include <stdio.h>
#include <string.h>
void Point(char x);

int main()
{
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");
    int i,sum1=0,sum2=0;
    int length1=strlen(player1);
    int length2=strlen(player2);

   for(i=0;i<length1;i++)
    {
        switch(player1[i])
        {
            case 'a':
            {
                player1[i]=1;
                break;
            }
            case 'A':
            {
                player1[i]=1;
                break;
            }
            case 'e':
            {
                player1[i]=1;
                break;
            }
            case 'E':
            {
                player1[i]=1;
                break;
            }
            case 'i':
            {
                player1[i]=1;
                break;
            }
            case 'I':
            {
                player1[i]=1;
                break;
            }
            case 'l':
            {
                player1[i]=1;
                break;
            }
            case 'L':
            {
                player1[i]=1;
                break;
            }
            case 'n':
            {
                player1[i]=1;
                break;
            }
            case 'N':
            {
                player1[i]=1;
                break;
            }
            case 'o':
            {
                player1[i]=1;
                break;
            }
            case 'O':
            {
                player1[i]=1;
                break;
            }
            case 'r':
            {
                player1[i]=1;
                break;
            }
            case 'R':
            {
                player1[i]=1;
                break;
            }
            case 's':
            {
                player1[i]=1;
                break;
            }
            case 'S':
            {
                player1[i]=1;
                break;
            }
            case 't':
            {
                player1[i]=1;
                break;
            }
            case 'T':
            {
                player1[i]=1;
                break;
            }
            case 'u':
            {
                player1[i]=1;
                break;
            }
            case 'U':
            {
                player1[i]=1;
                break;
            }
            case 'd':
            {
                player1[i]=2;
                break;
            }
            case 'D':
            {
                player1[i]=2;
                break;
            }
            case 'g':
            {
                player1[i]=2;
                break;
            }
            case 'G':
            {
                player1[i]=2;
                break;
            }
            case 'b':
            {
                player1[i]=3;
                break;
            }
            case 'B':
            {
                player1[i]=3;
                break;
            }
              case 'c':
            {
                player1[i]=3;
                break;
            }
            case 'C':
            {
                player1[i]=3;
                break;
            }
            case 'm':
            {
                player1[i]=3;
                break;
            }
            case 'M':
            {
                player1[i]=3;
                break;
            }
            case 'p':
            {
                player1[i]=3;
                break;
            }
            case 'P':
            {
                player1[i]=3;
                break;
            }
            case 'f':
            {
                player1[i]=4;
                break;
            }
            case 'F':
            {
                player1[i]=4;
                break;
            }
            case 'h':
            {
                player1[i]=4;
                break;
            }
            case 'H':
            {
                player1[i]=4;
                break;
            }
            case 'v':
            {
                player1[i]=4;
                break;
            }
            case 'V':
            {
                player1[i]=4;
                break;
            }
            case 'w':
            {
                player1[i]=4;
                break;
            }
            case 'W':
            {
                player1[i]=4;
                break;
            }
            case 'y':
            {
                player1[i]=4;
                break;
            }
            case 'Y':
            {
                player1[i]=4;
                break;
            }
            case 'k':
            {
                player1[i]=5;
                break;
            }
            case 'K':
            {
                player1[i]=5;
                break;
            }
            case 'j':
            {
                player1[i]=8;
                break;
            }
            case 'J':
            {
                player1[i]=8;
                break;
            }
            case 'x':
            {
                player1[i]=8;
                break;
            }
            case 'X':
            {
                player1[i]=8;
                break;
            }
            case 'q':
            {
                player1[i]=10;
                break;
            }
            case 'Q':
            {
                player1[i]=10;
                break;
            }
            case 'z':
            {
                player1[i]=10;
                break;
            }
            case 'Z':
            {
                player1[i]=10;
                break;
            }
            case '!':
            {
                player1[i]=1;
                break;
            }
            case '?':
            {
                player1[i]=1;
                break;
            }
        }
        switch(player2[i])
        {
            case 'a':
            {
                player2[i]=1;
                break;
            }
            case 'A':
            {
                player2[i]=1;
                break;
            }
            case 'e':
            {
                player2[i]=1;
                break;
            }
            case 'E':
            {
                player2[i]=1;
                break;
            }
            case 'i':
            {
                player2[i]=1;
                break;
            }
            case 'I':
            {
                player2[i]=1;
                break;
            }
            case 'l':
            {
                player2[i]=1;
                break;
            }case 'L':
            {
                player2[i]=1;
                break;
            }
            case 'n':
            {
                player2[i]=1;
                break;
            }
            case 'N':
            {
                player2[i]=1;
                break;
            }
            case 'o':
            {
                player2[i]=1;
                break;
            }
            case 'O':
            {
                player2[i]=1;
                break;
            }
            case 'r':
            {
                player2[i]=1;
                break;
            }
            case 'R':
            {
                player2[i]=1;
                break;
            }
            case 's':
            {
                player2[i]=1;
                break;
            }
            case 'S':
            {
                player2[i]=1;
                break;
            }
            case 't':
            {
                player2[i]=1;
                break;
            }
            case 'T':
            {
                player2[i]=1;
                break;
            }
            case 'u':
            {
                player2[i]=1;
                break;
            }
            case 'U':
            {
                player2[i]=1;
                break;
            }
            case 'd':
            {
                player2[i]=2;
                break;
            }
            case 'D':
            {
                player2[i]=2;
                break;
            }
            case 'g':
            {
                player2[i]=2;
                break;
            }
            case 'G':
            {
                player2[i]=2;
                break;
            }
            case 'b':
            {
                player2[i]=3;
                break;
            }
            case 'B':
            {
                player2[i]=3;
                break;
            }
              case 'c':
            {
                player2[i]=3;
                break;
            }
            case 'C':
            {
                player2[i]=3;
                break;
            }
            case 'm':
            {
                player2[i]=3;
                break;
            }
            case 'M':
            {
                player2[i]=3;
                break;
            }
            case 'p':
            {
                player2[i]=3;
                break;
            }
            case 'P':
            {
                player2[i]=3;
                break;
            }
            case 'f':
            {
                player2[i]=4;
                break;
            }
            case 'F':
            {
                player2[i]=4;
                break;
            }
            case 'h':
            {
                player2[i]=4;
                break;
            }
            case 'H':
            {
                player2[i]=4;
                break;
            }
            case 'v':
            {
                player2[i]=4;
                break;
            }
            case 'V':
            {
                player2[i]=4;
                break;
            }
            case 'w':
            {
                player2[i]=4;
                break;
            }
            case 'W':
            {
                player2[i]=4;
                break;
            }
            case 'y':
            {
                player2[i]=4;
                break;
            }
            case 'Y':
            {
                player2[i]=4;
                break;
            }
            case 'k':
            {
                player2[i]=5;
                break;
            }
            case 'K':
            {
                player2[i]=5;
                break;
            }
            case 'j':
            {
                player2[i]=8;
                break;
            }
            case 'J':
            {
                player2[i]=8;
                break;
            }
            case 'x':
            {
                player2[i]=8;
                break;
            }
            case 'X':
            {
                player2[i]=8;
                break;
            }
            case 'q':
            {
                player2[i]=10;
                break;
            }
            case 'Q':
            {
                player2[i]=10;
                break;
            }
            case 'z':
            {
                player2[i]=10;
                break;
            }
            case 'Z':
            {
                player2[i]=10;
                break;
            }
            case '!':
            {
                player2[i]=1;
                break;
            }
            case '?':
            {
                player2[i]=1;
                break;
            }
        }
        //printf("pl1: %i \n",player1[i]);
        //printf("pl2: %i \n",player2[i]);

        sum1+=(player1[i]);
        sum2+=(player2[i]);

    }
    //printf("Sum1: %i \n",sum1);
    //printf("Sum2: %i \n",sum2);
    if(sum1 > sum2)
    {
        printf("Player 1 Win! \n");
    }
    else if(sum1 < sum2)
        {
            printf("Player 2 Win! \n");
        }
        else
        {
            printf("Tie!\n");
        }


}

void Point(char x)
{
     switch(x)
        {
            case 'a':
            {
                x=1;
                break;
            }
            case 'A':
            {
                x=1;
                break;
            }
            case 'e':
            {
                x=1;
                break;
            }
            case 'E':
            {
                x=1;
                break;
            }
            case 'i':
            {
                x=1;
                break;
            }
            case 'I':
            {
                x=1;
                break;
            }
            case 'l':
            {
                x=1;
                break;
            }case 'L':
            {
                x=1;
                break;
            }
            case 'n':
            {
                x=1;
                break;
            }
            case 'N':
            {
                x=1;
                break;
            }
            case 'o':
            {
                x=1;
                break;
            }
            case 'O':
            {
                x=1;
                break;
            }
            case 'r':
            {
                x=1;
                break;
            }
            case 'R':
            {
                x=1;
                break;
            }
            case 's':
            {
                x=1;
                break;
            }
            case 'S':
            {
                x=1;
                break;
            }
            case 't':
            {
                x=1;
                break;
            }
            case 'T':
            {
                x=1;
                break;
            }
            case 'u':
            {
                x=1;
                break;
            }
            case 'U':
            {
                x=1;
                break;
            }
            case 'd':
            {
                x=2;
                break;
            }
            case 'D':
            {
                x=2;
                break;
            }
            case 'g':
            {
                x=2;
                break;
            }
            case 'G':
            {
                x=2;
                break;
            }
            case 'b':
            {
                x=3;
                break;
            }
            case 'B':
            {
                x=3;
                break;
            }
              case 'c':
            {
                x=3;
                break;
            }
            case 'C':
            {
                x=3;
                break;
            }
            case 'm':
            {
                x=3;
                break;
            }
            case 'M':
            {
                x=3;
                break;
            }
            case 'p':
            {
                x=3;
                break;
            }
            case 'P':
            {
                x=3;
                break;
            }
            case 'f':
            {
                x=4;
                break;
            }
            case 'F':
            {
                x=4;
                break;
            }
            case 'h':
            {
                x=4;
                break;
            }
            case 'H':
            {
                x=4;
                break;
            }
            case 'v':
            {
                x=4;
                break;
            }
            case 'V':
            {
                x=4;
                break;
            }
            case 'w':
            {
                x=4;
                break;
            }
            case 'W':
            {
                x=4;
                break;
            }
            case 'y':
            {
                x=4;
                break;
            }
            case 'Y':
            {
                x=4;
                break;
            }
            case 'k':
            {
                x=5;
                break;
            }
            case 'K':
            {
                x=5;
                break;
            }
            case 'j':
            {
                x=8;
                break;
            }
            case 'J':
            {
                x=8;
                break;
            }
            case 'x':
            {
                x=8;
                break;
            }
            case 'X':
            {
                x=8;
                break;
            }
            case 'q':
            {
                x=10;
                break;
            }
            case 'Q':
            {
                x=10;
                break;
            }
            case 'z':
            {
                x=10;
                break;
            }
            case 'Z':
            {
                x=10;
                break;
            }
            case '!':
            {
                x=0;
                break;
            }
            case '?':
            {
                x=0;
                break;
            }
        }
}
