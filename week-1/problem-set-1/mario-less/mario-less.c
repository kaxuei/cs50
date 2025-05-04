#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Initializes height, row, space, and column
    int height, row, column, space;
    // Asks the user for input
    do
    {
        height = get_int("Enter height here: ");
    }
    while (height < 1 || height > 8);

    // Basically mario maker
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
        printf("\n");
    }
}
