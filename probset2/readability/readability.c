#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
// Prototypes
int count_letters(string text);
int count_sents(string text);
int count_words(string text);

int main(void)
{
    // Algorithm:
    // index = 0.0588 * L - 0.296 * S - 15.8
    // L - average number of letters per 100 words.
    // S - average number of sentences in 100 words.

    // Get input sentence.
    string text = get_string("Enter Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sents(text);

    int index =
        round(0.0588 * (100.0 * letters / words) - 0.296 * (100.0 * sentences / words) - 15.8);

    //  What reading level is the text.
    if (index > 1 && index < 18)
    {
        printf("Grade %i\n", index);
    }
    if (index < 2)
    {
        printf("Before Grade 1\n");
    }
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    return 0;
}
// Counting the letters.
int count_letters(string text)
{
    int count = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // Count all alphabetic characters
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
    // do research on the code library
    //  see you later
}
// counting sentences.
int count_sents(string text)
{
    int count = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // count the end of a sentence:
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}
// count the words
int count_words(string text)
{
    // count words
    int count = 0;
    bool new_word = true;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == ' ')
        {
            new_word = true;
            continue;
        }
        if (new_word)
        {
            count++;
            new_word = false;
        }
    }
    return count;
}
