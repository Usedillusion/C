#include <cs50.h>
#include <stdio.h>

void pyramid(int height);
int get_valid_height(void);

int main(void)
{
    int height = get_valid_height();
    pyramid(height);
}

int get_valid_height(void)
{
    int height;
    do
    {
        height = get_int("Height? ");
    }
    while (height < 1 || height > 8);
    return height;
}

void pyramid(int height)
{
    for (int row = 0; row < height; row++)
    {
        // works out the amount of blocks and spaces to use +1 is to print something on the first
        // line otherwise blocks = 0
        int blocks = row + 1;
        int spaces = height - blocks;

        // loop for printing the amount of spaces
        for (int i = 0; i < spaces; i++)
        {
            printf(" ");
        }
        // loop for blocks
        for (int i = 0; i < blocks; i++)
        {
            printf("#");
        }
        //blank space for middle of pyramid
        printf("  ");
        // repeat print blocks
        for (int i = 0; i < blocks; i++)
        {
            printf("#");
        }
        // end loops with a new line
        printf("\n");
    }
}
