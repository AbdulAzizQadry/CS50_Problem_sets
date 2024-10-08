#include <stdio.h>
#include "cs50.h"
#include <string.h>
#include <ctype.h>
#include <math.h>

int coleman_liao (string text);

int main (void)
{
    string text = get_string ("Text: ");
    
    int grade = coleman_liao (text);

    if (grade <= 1)
    {
        printf ("Before Grade 1\n");
    }
    else if (grade < 16)
    {
        printf ("Grade %i\n", grade);
    }
    else
    {
        printf ("Grade 16+\n");
    }
}

int coleman_liao (string text)
{
    int letters = 0;
    int words = 1;
    int sentences = 0;

    for (int i = 0, n = strlen (text); i < n; i++)
    {
        if (isalpha (text [i]))
        {
            letters++;
        }
        else if (isblank (text [i]))
        {
            words++;
        }
        else if (text [i] == '.' || text [i] == '?' || text [i] == '!')
        {
            sentences++;
        }
    }

    int index = round ((0.0588 * letters / words * 100) - (0.296 * sentences / words * 100) - 15.8);
    return index;
}
