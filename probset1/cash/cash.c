#include <cs50.h>
#include <stdio.h>
// Prototypes
int get_change(void);
int calc_quarters(int cents);
int calc_dimes(int cents);
int calc_nickels(int cents);
int calc_pennies(int cents);

int main(void)
{
    // get change from user
    int change = get_change();

    // calculate quaters
    int quarters = calc_quarters(change);
    change = change - (quarters * 25);

    // calculate dimes
    int dimes = calc_dimes(change);
    change = change - (dimes * 10);

    // calculate nickels
    int nickels = calc_nickels(change);
    change = change - (nickels * 5);

    // calculate pennies
    int pennies = calc_pennies(change);
    change = change - (pennies * 1);

    int total = quarters + dimes + nickels + pennies;

    printf("%i coins\n", total);
}

int get_change(void)
{
    int change;

    do
    {
        change = get_int("Change Owed:");
    }
    while (change < 1);

    return change;
}
// repeat and mod
int calc_quarters(int cents)
{
    return cents / 25;
}

int calc_dimes(int cents)
{
    return cents / 10;
}

int calc_nickels(int cents)
{
    return cents / 5;
}

int calc_pennies(int cents)
{
    return cents / 1;
}
