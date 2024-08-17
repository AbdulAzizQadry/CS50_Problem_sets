#include <stdio.h>
#include "cs50.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits (string key);
string rotate (string plain, int key);

int main (int argc, string argv [])
{
    if (argc != 2 || only_digits(argv [1]))
    {
        printf ("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi (argv [1]);
    key %= 26;

    string plain = get_string ("plaintext:  ");
    string cipher = rotate (plain, key);
    printf ("ciphertext: %s\n", cipher);
    return 0;
}

bool only_digits (string key)
{
    for (int i = 0, n = strlen (key); i < n; i++)
    {
        if (isdigit (key[i]) == 0)
        {
            return true;
        }
    }
    return false;
}

string rotate (string plain, int key)
{
    string cipher = plain;
    for (int i = 0, n = strlen (plain); i < n; i++)
    {
        if (isalpha (plain [i]))
        {
            char offset = isupper (plain [i]) ? 'A' : 'a';
            cipher [i] = ((plain [i] - offset + key) % 26) + offset;
        }
    }
    return cipher;
}
