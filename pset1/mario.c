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
        int w = i + 1;
        for (int j = 0; j < n - w; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < w; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = 0; j < w; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}