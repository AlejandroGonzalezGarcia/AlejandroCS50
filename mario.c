#include <cs50.h>
#include <stdio.h>

// This code will build pyramid-style blocks that resemble those seen in Nintendo's Super Mario Bros. Note that one of the
// restrictions provided for this assignment was that the height of the blocks must not exceed 8.

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    int i = 0;

    while (i < n)
    {
        int a = n - (i+1);

        while(a >= 0)
        {
            printf(" ");
            a--;
        }

        int k = 0;

        while (k <= i)
        {

            printf("#");
            k++;
        }

        printf("  ");

        int j = 0;

        while (j <= i)
        {
            printf("#");
            j++;
        }
    i++;
    printf("\n");
    }
}
