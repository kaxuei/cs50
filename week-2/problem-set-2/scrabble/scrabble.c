#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// followed ddbs advice and defined a constant
#define ASCII_OFFSET 65

// Sticky Notessss

// Letter Values
// 1 point - A, E, I, L, N, O, R, S, T, U
// 2 points - D, G
// 3 points - B, C, M, P
// 4 points - F, H, V, W, Y
// 5 points - K
// 8 points - J, X
// 10 points - Q, Z

// What is Scrabble?
// Scrabble is a word game where players score points by forming words on a board by placing
// lettered tiles, similar to a crossword puzzle. The goal is to achieve the highest score by
// strategically using letter tiles and taking advantage of premium squares on the board.

// What is the goal of this program?
// In a file called scrabble.c in a folder called scrabble, implement a program in C that
// determines the winner of a short Scrabble-like game.
// Your program should prompt for input twice: once for “Player 1” to input their word
// and once for “Player 2” to input their word.
// Then, depending on which player scores the most points, your program should either print
// “Player 1 wins!”, “Player 2 wins!”, or “Tie!” (in the event the two players score equal points).

// ddb also suggested to create a function to calculate scores.
int calculate_score(string word);

int main(void)
{
    // Prompt the user for their respective words
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    // Check if inputs are valid
    if (strlen(player1) == 0 || strlen(player2) == 0)
    {
        printf("Error: Both players must enter a word\n");
        return 1;
    }

    // Calculate scores
    int score1 = calculate_score(player1);
    int score2 = calculate_score(player2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 Wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 Wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}

int calculate_score(string word)
{
    int score = 0;
    // Points for letters A-Z
    int letter_points[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                             1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    // Loop through each character in the word
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (isalpha(word[i]))
        {
            // Convert each letter to uppercase for consistency
            char c = toupper(word[i]);
            // Calculate score using the letters position in the alphabet
            score += letter_points[c - ASCII_OFFSET];
        }
    }
    return score;
}
