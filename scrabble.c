#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// declarations
char letters[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
int points[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int p1score;
int p2score;

// functions

// Check for Alphanumeric characters
bool isAlphanumeric(char str[], int length)
{
    for (int i = 0; i < length; i++)
    {

        if (!isalnum(str[i]))
        {
            return false; // Found a non-alphanumeric character
        }
    }
    return true; // All characters are alphanumeric
}

// find the position of the character
int findCharacterPosition(string array, char target)
{
    int size = strlen(array);
    for (int i = 0; i < size; i++)
    {
        if (array[i] == target)
        {
            return i; // Return the position (index) of the target character
        }
    }
    return -1; // Return -1 if the character is not found
}

// Calculate the score for a string
int calculateScore(string input)
{
    int score = 0;
    int length = strlen(input);

    for (int i = 0; i < length; i++)
    {
        // Convert to uppercase to match the letters array
        char currentChar = toupper(input[i]);
        int pos = findCharacterPosition(letters, currentChar);

        if (pos != -1)
        {
            score += points[pos]; // looks up the points array
        }
    }

    return score;
}

// main

int main()
{
    string Player1;
    string Player2;
    int length;

    //    do {
    Player1 = get_string("Player 1: ");
    length = strlen(Player1);
    //    } while (!isAlphanumeric(Player1, length));

    //    printf("Player1: %s\n", Player1);

    //   do {
    Player2 = get_string("Player 2: ");
    length = strlen(Player2);
    //   } while (!isAlphanumeric(Player2, length));

    //    printf("Player2: %s\n", Player2);

    p1score = calculateScore(Player1);
    //   printf("\nPlayer 1 Score: %d\n", p1score);
    p2score = calculateScore(Player2);
    //   printf("Player 2 Score: %d\n", p2score);

    if (p1score > p2score)
    {
        printf("Player 1 Wins! \n");
    }
    else if (p1score < p2score)
    {
        printf("Player 2 Wins! \n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}
