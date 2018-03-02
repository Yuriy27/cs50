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

int get_numeric_key(char c)
{
    return c - get_base_char(c);
}

string vigenere_encode(string plain, string key)
{
    int ind = 0;
    int key_size = strlen(key);
    for (int i = 0; i < strlen(plain); i++)
    {
        if (isalpha(plain[i]))
        {
            plain[i] = proccess_alpha(plain[i], get_numeric_key(key[ind]));
            ind = (ind + 1) % key_size;
        }
    }

    return plain;
}

bool invalid(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            return true;
        }
    }

    return false;
}

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    string key = argv[1];
    if (invalid(key))
    {
        printf("Usage: ./vigenere k (consist of alphabetical characters)\n");
        return 1;
    }
    printf("plaintext: ");
    string plaintext = get_string();
    printf("ciphertext: %s\n", vigenere_encode(plaintext, key));

    return 0;
}