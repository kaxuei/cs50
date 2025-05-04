#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Asks the user for their name
    string name = get_string("What is your name? ");
    // Greets the user!
    printf("Hello, %s\n", name);
}
