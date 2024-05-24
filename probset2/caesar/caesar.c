#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    for (int key = 0; key < strlen(argv[1]); key++)
    {
        // Takes key from user.
        if (isalpha(argv[1][key]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]) % 26;
    // Gets input from user.
    string plaintxt = get_string("Plaintext: ");

    printf("ciphertext: ");

    for (int i = 0, len = strlen(plaintxt); i < len; i++)
    {
        if (!isalpha(plaintxt[i]))
        {
            printf("%c", plaintxt[i]);
        }
        // Takes the condition of the balance and determines what happens next, differs between
        // upper and lowercase characters.
        int balance = isupper(plaintxt[i]) ? 65 : 97;

        int ptb = (plaintxt[i] - balance);

        int cyin = (ptb + key) % 26;

        printf("%c", cyin + balance);
    }
    printf("\n");
    return 0;
}
