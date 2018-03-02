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
    bool is_space = s[0] == ' ';
    if (!is_space)
    {
        printf("%c", to_upper(s[0]));
    }
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
        {
            is_space = true;
        }
        else
        {
            if (is_space)
            {
                printf("%c", to_upper(s[i]));
                is_space = false;
            }
        }
    }
    printf("\n");
}