#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float n;
    printf("O hai! How much change is owed?\n");
    n = get_float();
    while (n < 0)
    {
        printf("How much change is owed?\n");
        n = get_float();
    }
    int cents = round(n * 100);
    int coins = 0;
    if (cents / 25 != 0)
    {
        coins += cents / 25;
        cents -= (cents / 25) * 25;
    }
    if (cents / 10 != 0)
    {
        coins += cents / 10;
        cents -= (cents / 10) * 10;
    }
    if (cents / 5 != 0)
    {
        coins += cents / 5;
        cents -= (cents / 5) * 5;
    }
    coins += cents;
    printf("%i\n", coins);
}