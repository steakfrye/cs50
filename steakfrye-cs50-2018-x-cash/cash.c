#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //declare float variables
    float change;
    int coins, change2;

    coins = 0;

    //ask user for change
    do
    {
        change = get_float("Change owed: ");
    }

    while (change < 0);
    {
        change2 = round(change * 100);

        //Calculate quarters
        while (change2 >= 25)
        {
            coins = (coins + 1);
            change2 = (change2 - 25);
        }
        //Calculate dimes
        while (change2 >= 10)
        {
            coins = (coins + 1);
            change2 = (change2 - 10);
        }
        //Calculate nickels
        while (change2 >= 5)
        {
            coins = (coins + 1);
            change2 = (change2 - 5);
        }
        //Calculate pennies
        while (change2 >= 1)
        {
            coins = (coins + 1);
            change2 = (change2 - 1);
        }

        printf("%i Coins used.\n", coins);
    }
}