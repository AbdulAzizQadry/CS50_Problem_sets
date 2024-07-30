#include <stdio.h>
#include "cs50.h"

int main (void)
{
    int change;
    do
    {
        change = get_int ("Change owed: ");
    }
    while (change < 0);
    int counter = change / 25;
    change %= 25;
    counter += change / 10;
    change %= 10;
    counter += change / 5;
    change %= 5;
    counter += change;
    printf ("%i", counter);
}