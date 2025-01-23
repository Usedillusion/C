#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// sort out the words and stuff
void testing(char input[], int length, int values[3])
{
    for (int i = 0; i < 3; i++)
    {
        values[i] = 0;
    }

    values[1] += 1;

    // letters = [0], words = [1], sentences = [2]

    for (int i = 0; i < length; i++)
    {
        if (isalnum(input[i]))
        {
            values[0]++;
        }
        else if (isspace(input[i]))
        {
            if (i > 0 && !isspace(input[i - 1]))
            {
                values[1]++;
            }
        }
        else if (input[i] == '.' || input[i] == '!' || input[i] == '?')
        {
            values[2]++;
        }
    }
}

int main(void)
{
    int length;
    string text;
    int values[3];
    float index;

    // get the input string
    text = get_string("Text: ");
    length = strlen(text);

    // test the single function
    testing(text, length, values);
    //        printf("letters: %d\n", values[0]);
    //        printf("Words: %d\n", values[1]);
    //        printf("Sentences: %d\n", values[2]);

    // Calculate the index
    float L = (float) values[0] / values[1] * 100;
    float S = (float) values[2] / values[1] * 100;
    index = 0.0588 * L - 0.296 * S - 15.8;

    // Round up the index to the nearest whole number
    int roundedIndex = (int) round(index);

    // Print the index

    if (roundedIndex < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (roundedIndex > 16)
    {
        printf("Grade 16+\n");
    }
    else
        printf("Grade %d\n", roundedIndex);

    return 0;
}
