#include <stdio.h>

int s_len(char* str)
{
    int counter = 0;
    char* beg = str;
    while (*beg != '\0')
    {
        counter++;
        beg++;
    }

    return counter - 1
    ;
}

int main(void)
{
    //char str[500];
    //fgets(str, sizeof(str), stdin);
    //printf("%i", s_len(str));
    printf("%i", (int)('a'));

    return 0;
}