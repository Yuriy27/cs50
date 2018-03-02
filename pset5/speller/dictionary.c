/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "dictionary.h"

typedef struct node
{
    bool is_word;
    struct node* children[27];
} node;

node* root;

int DICT_SIZE = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    struct node* curr_node = root;
    if (curr_node == NULL)
    {
        return false;
    }
    int word_len = strlen(word);
    int ind = 0;
    for (int i = 0; i < word_len; i++)
    {
        if (word[i] == '\'')
        {
            ind = 26;
        }
        else
        {
            ind = tolower(word[i]) - 'a';
        }
        curr_node = curr_node->children[ind];
        if (curr_node == NULL)
        {
            return false;
        }
    }

    return curr_node->is_word;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    root = (node*)malloc(sizeof(node));
    root->is_word = false;
    for (int i = 0; i < 27; i++)
    {
        root->children[i] = NULL;
    }

    FILE* fl = fopen(dictionary, "r");
    if (fl == NULL)
    {
        unload();
        return false;
    }
    char curr_word[LENGTH + 1];
    int ind = 0;
    while (fscanf(fl, "%s", curr_word) != EOF)
    {
        struct node* curr_node = root;
        int word_len = strlen(curr_word);
        for (int i = 0; i < word_len; i++)
        {
            if (curr_word[i] == '\'')
            {
                ind = 26;
            }
            else
            {
                ind = tolower(curr_word[i]) - 'a';
            }
            if (curr_node->children[ind] == NULL)
            {
                struct node* new_node = (node*)malloc(sizeof(node));
                new_node->is_word = false;
                for (int i = 0; i < 27; i++)
                {
                    new_node->children[i] = NULL;
                }
                curr_node->children[ind] = new_node;
            }
            curr_node = curr_node->children[ind];
        }
        curr_node->is_word = true;
        DICT_SIZE++;
    }

    fclose(fl);

    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return DICT_SIZE;
}

void recursive_unload(node* n)
{
    for (int i = 0; i < 27; i++)
    {
        if (n->children[i] != NULL)
        {
            recursive_unload(n->children[i]);
        }
    }
    free(n);
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    if (root != NULL)
    {
        recursive_unload(root);
    }

    return true;
}
