/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if (n <= 0)
    {
        return false;
    }
    int left = 0;
    while (left <= n)
    {
        int mid = left + (n - left) / 2;
        if (values[mid] == value)
        {
            return true;
        }
        else if (value < values[mid])
        {
            n = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return false;
}


/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int swaps = -1;
    while (swaps != 0)
    {
        swaps = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (values[i] > values[i + 1])
            {
                int tmp = values[i];
                values[i] = values[i + 1];
                values[i + 1] = tmp;
                swaps++;
            }
        }
        n--;
    }

    return;
}
