#include <stdio.h>
#include "cs50.h"
#include <string.h>
#include <ctype.h>

int calculate (string player);

int main (void)
{
    string player_1 = get_string ("player 1: ");
    string player_2 = get_string ("player 2: ");

    int score_1 = calculate (player_1);
    int score_2 = calculate (player_2);

    if (score_1 > score_2)
    {
        printf ("Player 1 wins!\n");
    }
    else if (score_1 < score_2)
    {
        printf ("Player 2 wins!\n");
    }
    else
    {
        printf ("Tie!\n");
    }
}

int calculate (string player)
{
    int count = 0;
    int score [26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    for (int i = 0, n = strlen (player); i < n; i++)
    {
        player [i] = tolower (player [i]);
        if (player [i] >= 'a' && player [i] <= 'z')
        {
            int index = player [i] - 'a';
            count += score [index];
        }
    }
    return count;
}