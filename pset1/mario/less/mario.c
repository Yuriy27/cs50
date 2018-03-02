#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        printf("Height: ");
        n = get_int();
    }
    while (n < 0 || n > 23);
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        for (; j < n + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}