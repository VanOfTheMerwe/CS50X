#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get user name and output to the screen
    string name = get_string("What is your name: ");
    printf("Hello, %s\n", name);
}
