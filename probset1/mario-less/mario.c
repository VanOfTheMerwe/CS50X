#include <cs50.h>
#include <stdio.h>

void create_pyramid(int h);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height:");
        // Get height from user
    }
    while (height < 1);

    for (int i = 0; i < height; i++)
    {
        // Inverts the pyramid
        for (int k = 0; k < height - i - 1; k++)
        {
            printf(" ");
        }

        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}

void create_pyramid(int h);
