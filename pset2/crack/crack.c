#define _XOPEN_SOURCE
#include <unistd.h>

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char salt[2];
string hash = "";
string source = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
bool found = false;

bool verify_password(string pass)
{
    return strcmp(crypt(pass, salt), hash) == 0;
}

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    hash = argv[1];
    strncpy(salt, hash, 2);
    int source_size = strlen(source);
    char curr[5];
    curr[4] = '\0';
    for (int i = 0; i < source_size; i++)
    {
        curr[0] = source[i];
        curr[1] = '\0';
        if (verify_password(curr))
        {
            printf("%s\n", curr);
            return 0;
        }
    }
    for (int i = 0; i < source_size; i++)
    {
        for (int j = 0; j < source_size; j++)
        {
            curr[0] = source[i];
            curr[1] = source[j];
            curr[2] = '\0';
            if (verify_password(curr))
            {
                printf("%s\n", curr);
                return 0;
            }
        }
    }
    for (int i = 0; i < source_size; i++)
    {
        for (int j = 0; j < source_size; j++)
        {
            for (int k = 0; k < source_size; k++)
            {
                curr[0] = source[i];
                curr[1] = source[j];
                curr[2] = source[k];
                curr[3] = '\0';
                if (verify_password(curr))
                {
                    printf("%s\n", curr);
                    return 0;
                }
            }
        }
    }
    for (int i = 0; i < source_size; i++)
    {
        for (int j = 0; j < source_size; j++)
        {
            for (int k = 0; k < source_size; k++)
            {
                for (int z = 0; z < source_size; z++)
                {
                    curr[0] = source[i];
                    curr[1] = source[j];
                    curr[2] = source[k];
                    curr[3] = source[z];
                    if (verify_password(curr))
                    {
                        printf("%s\n", curr);
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}