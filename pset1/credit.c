#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    printf("Number: ");
    long long n = get_long_long();
    char card[17];
    sprintf(card, "%llu", n);
    int evens = 0;
    int odds = 0;
    int size = strlen(card);
    bool flag = false;
    for (int i = size - 1; i >= 0; i--)
    {
        if (flag)
        {
            int curr = (card[i] - '0') * 2;
            odds += (curr >= 10 ? curr / 10 + curr % 10 : curr);
        }
        else
        {
            int curr = card[i] - '0';
            evens += curr;
        }
        flag = !flag;
    }
    int sum = odds + evens;
    if (sum % 10 == 0)
    {
        if (size == 15 && card[0] == '3' && (card[1] == '4' || card[1] == '7'))
        {
            printf("AMEX\n");
        }
        else if (size == 16 && card[0] == '5' && (card[1] > '0' && card[1] < '6'))
        {
            printf("MASTERCARD\n");
        }
        else if ((size == 16 || size == 13) && card[0] == '4')
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}