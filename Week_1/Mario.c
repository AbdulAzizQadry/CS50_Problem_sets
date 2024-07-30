#include <stdio.h>
#include "cs50.h"

void row (int a, int b);

int main (void)
{
    int H;
    do
    {
        H = get_int ("Height: ");
    }
    while (H < 1 || H > 8);
    for (int i = 0; i < H; i++)
    {
        row (H - i - 1, i + 1);
    }
}

void row (int a, int b)
{
    for (int j = 0; j < a; j++)
    {
        printf (" ");
    }
    for (int k = 0; k < b; k++)
    {
        printf ("#");
    }
    printf ("  ");
    for (int k = 0; k < b; k++)
    {
        printf ("#");
    }
    printf ("\n");
}