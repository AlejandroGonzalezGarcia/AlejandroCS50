#include <cs50.h>
#include <stdio.h>

// This code will build pyramid-style blocks that resemble those seen in Nintendo's Super Mario Bros. Note that one of the
// restrictions provided for this assignment was that the height of the blocks must not exceed 8.

int main(void)
{
    // Declear the height of the blocks
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // Declare first variable which will construct the rows
    int i = 0;

    while (i < n)
    {
        // Create spaces behind hashtags
        int a = n - (i+1);

        while(a >= 0)
        {
            printf(" ");
            a--;
        }

        // Create hashtags on left-hand side
        int k = 0;

        while (k <= i)
        {

            printf("#");
            k++;
        }

        // Make space to separate left side from right side of the blocks
        printf("  ");

        // Create right side of the blocks
        int j = 0;

        while (j <= i)
        {
            printf("#");
            j++;
        }

    i++;

    // Create new row
    printf("\n");
    }
}