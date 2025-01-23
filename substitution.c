#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

char key[26];
char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                     'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
int position[50];

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

void returnWord(string input)
{
    int length = strlen(input);

    for (int i = 0; i < length; i++)
    {
        char currentChar = toupper(input[i]);
        int pos = findCharacterPosition(alphabet, currentChar);

        position[i] = pos; // Store the index, not the character
    }
}

int main(int arg, string cipher[])
{
    // Ensure exactly one command line argument is provided (the key)
    if (arg != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Ensure the key length is exactly 26 characters
    if (strlen(cipher[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Initialize array to track seen characters
    bool seen[26] = {false};

    // Copy the key from the command line argument
    for (int i = 0; i < 26; i++)
    {
        char currentChar = toupper(cipher[1][i]);

        // Check if the character is a letter
        if (!isalpha(currentChar))
        {
            printf("Key must contain only letters.\n");
            return 1;
        }

        // Check for duplicate characters
        if (seen[currentChar - 'A'])  //-65 to get the index for A to 0 to translate to the seen index.
        {
            printf("Key must not contain duplicate characters.\n");
            return 1;
        }
        seen[currentChar - 'A'] = true; //This marks the current index for the letter as seen - so index 0 is A based on Ascii, so if seen[0] = true then A (based on A being 0 in it's ascii number -65) is marked true, and if that letter comes up again it checks the index corresponding to it for true/false
        key[i] = currentChar; //puts the character into the key array
    }

    string message;

    message = get_string("plaintext: ");
    int loop = strlen(message);

    returnWord(message);

    printf("ciphertext: ");

    for (int i = 0; i < loop; i++)
    {
        if (position[i] != -1) // Ensure it's a valid index
        {
            if (isupper(message[i]))
            {
                printf("%c", key[position[i]]); // Print the character from the key array
            }
            else
            {
                printf("%c", tolower(key[position[i]])); // changes back to lowercase if it was lower case
            }
        }
        else
        {
            printf("%c", message[i]); // to print other characters
        }
    }

    printf("\n");

    return 0;
}
