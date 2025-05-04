#include <cs50.h>
#include <math.h>
#include <stdio.h>
// Sticky Notes (technically right?)

// Luhn's Algorithm
//  1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then
//  add those products’ digits together.
//  2. Add the sum to the sum of the digits that weren’t multiplied by 2.
//  3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to
//  0), the number is valid!

// Card Lengths
// AMEX: 15-Digit #'s, Starts with: 34 or 37
// MASTERCARD: 16-Digit #'s, Starts with: 51, 52, 53, 54, or 55
// VISA: 13-16-Digit #'s, Starts with: 4
int calculateLuhnSum(long credit_card);
int multiplyAndSum(int last_digits);
int number_of_digits(long credit_card);
bool isValidAmex(long credit_card, int numDigits);
bool isValidMasterCard(long credit_card, int numDigits);
bool isValidVisa(long credit_card, int numDigits);

int main(void)
{
    long credit_card = get_long("Credit Card: ");
    int sum_of_calculateLuhnSum = calculateLuhnSum(credit_card);
    int numDigits = number_of_digits(credit_card);
    bool amex = isValidAmex(credit_card, numDigits);
    bool master = isValidMasterCard(credit_card, numDigits);
    bool visa = isValidVisa(credit_card, numDigits);
    if (sum_of_calculateLuhnSum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    else if (amex == true)
    {
        printf("AMEX\n");
    }
    else if (master == true)
    {
        printf("MASTERCARD\n");
    }
    else if (visa == true)
    {
        printf("VISA\n");
    }
    // Prints if the user enters a single digit
    else
    {
        printf("INVALID\n");
    }
}

// Check if the length of the credit card number is 15
// and if the first two digits are 34 or 37 then identifies is as
// an AMEX card.
bool isValidAmex(long credit_card, int numDigits)
{
    int first_two_digits = credit_card / pow(10, 13);
    if ((numDigits == 15) && (first_two_digits == 34 || first_two_digits == 37))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Does the same thing as the previous lines of code
// but checks if it is 16 digits long and
// its first two digits are 51 - 55.
bool isValidMasterCard(long credit_card, int numDigits)
{
    int first_two_digits = credit_card / pow(10, 14);
    if ((numDigits == 16) && (first_two_digits > 50 && first_two_digits < 56))
    {
        return true;
    }
    return false;
}

// Checks if the card is 13 or 16 digits long
// it doesnt need to check for two digits as
// Visa cards always start with 4.
bool isValidVisa(long credit_card, int numDigits)
{
    if (numDigits == 13)
    {
        int first_digit = credit_card / pow(10, 12);
        if (first_digit == 4)
        {
            return true;
        }
    }
    else if (numDigits == 16)
    {
        int first_digit = credit_card / pow(10, 15);
        if (first_digit == 4)
        {
            return true;
        }
    }
    return false;
}

int number_of_digits(long credit_card)
{
    int count = 0;
    while (credit_card > 0)
    {
        count += 1;
        credit_card /= 10;
    }
    return count;
}

int calculateLuhnSum(long credit_card)
{
    int sum = 0;
    bool isAlternateDigit = false;
    while (credit_card > 0)
    {
        if (isAlternateDigit == true)
        {
            int last_digit = credit_card % 10;
            int product = multiplyAndSum(last_digit);
            sum += product;
        }
        else
        {
            int last_digit = credit_card % 10;
            sum += last_digit;
        }
        isAlternateDigit = !isAlternateDigit;
        credit_card /= 10;
    }
    return sum;
}

int multiplyAndSum(int last_digit)
{
    int multiply = last_digit * 2;
    int sum = 0;
    while (multiply > 0)
    {
        int last_digit_multiply = multiply % 10;
        sum += last_digit_multiply;
        multiply /= 10;
    }
    return sum;
}
