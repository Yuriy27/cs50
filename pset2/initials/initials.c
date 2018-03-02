#include <stdio.h>
#include <cs50.h>
#include <string.h>

int UPPERCASE_OFFSET = 'a' - 'A';

char to_upper(char c)
{
    return c >= 'a' ? c - UPPERCASE_OFFSET : c;
}

int main()
{
    string s = get_string();
    printf("%c", to_upper(s[0]));
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
        {
            printf("%c", to_upper(s[i + 1]));
        }
    }
    printf("\n");
}