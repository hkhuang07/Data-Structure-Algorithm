#include <stdio.h>

int main(void)
{
    // Declace
    int height;
    int i, j, k, l;
    // Input
    do
    {
        printf("Height In (1-8): ");
        scanf("%i", &height);
    }
    while (height < 1 || height > 8);

    // Process and Output
    for (i = height; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            printf(".");
        }
        for (k = height; k > 0; k--)
        {
            printf("#");
            if (k == j)
                break;
        }
        printf("..");
        for (l = height; l > 0; l--)
        {
            printf("#");
            if (l == j)
                break;
        }
        printf("\n");
    }
}
