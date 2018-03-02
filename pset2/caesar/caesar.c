#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define UPPERCASE 'A'
#define LOWERCASE 'a'
#define ALPHA_LENGTH 26

char get_base_char(char c)
{
    return isupper(c) ? UPPERCASE : LOWERCASE;
}

char proccess_alpha(char c, int key)
{
    char base = get_base_char(c);
    return base + (c - base + key) % ALPHA_LENGTH;
}

string encode(string plain, int key)
{
    for (int i = 0; i < strlen(plain); i++)
    {
        if (isalpha(plain[i]))
        {
            plain[i] = proccess_alpha(plain[i], key);
        }
    }

    return plain;
}

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    int key = atoi(argv[1]);
    printf("plaintext: ");
    string plaintext = get_string();
    printf("ciphertext: %s\n", encode(plaintext, key));

    return 0;
}