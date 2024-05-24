#include <stdio.h>
#include <cs50.h>

int calc_r5(int coins);

int main(void)
{
    int change = get_int("What is da change?");
    printf("Your amount is %i\n",change);

    int r5 = calc_r5(change);
    change = change - (r5 *5);

}
int calc_r5(int coins)
{
    return change / 5;
}
