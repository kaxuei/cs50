#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Declare variables
    int height, row, column, space;
    // Asks the user for for the height and informs them that they can only choose a number from 1 -
    // 8
    do
    {
        height = get_int("Enter height here (1-8): ");
    }
    while (height < 1 || height > 8);

    // Left side of the pyramid
    for (row = 0; row < height; row++)
    {
        for (space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }
        for (column = 0; column <= row; column++)
        {
            printf("#");
        }
        // The two spaces in the middle of the pyramid
        printf("  ");
        // Right side of the Pyramid, its shorter as the rest of the logic was already done on the
        // left side.
        for (column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("\n");
    }
}
