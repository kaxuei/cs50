#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Prototypes
// Followed ddb and made multiple functions

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int calculate_index(int letters, int words, int sentences);
void print_grade(int index);

int main(void)
{
    // Prompt the user for text
    string text = get_string("Text: ");

    // Counts the letter, words, and sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Coleman-Liau Index
    int index = calculate_index(letters, words, sentences);

    // Prints if the person is a kid or not
    print_grade(index);

    return 0;
}

// Counts the number of letters in the given text

int count_letters(string text)
{
    int count = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }

    return count;
}
// Counts the number of words in the given text
// Words are defined as sequences of letters separated by spaces

int count_words(string text)
{
    int count = 1; // Start with 1 because last word doesn't end with space

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }

    return count;
}

// Counts the number of sentences in the text
// A sentence ends with a period, exclamation point, or question mark

int count_sentences(string text)
{
    int count = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }

    return count;
}

// Calculates the Coleman-Liau readability index

int calculate_index(int letters, int words, int sentences)
{
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;

    return (int) round(0.0588 * L - 0.296 * S - 15.8);
}

// Prints the grade level based on the above index
void print_grade(int index)
{
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}
