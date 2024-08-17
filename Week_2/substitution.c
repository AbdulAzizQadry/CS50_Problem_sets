#include <stdio.h>
#include "cs50.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_letters (string key);
string substitute (string plain, string key);

int main (int argc, string argv [])
{
    if (argc != 2 || only_letters (argv [1]))
    {
        printf ("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen (argv [1]) != 26)
    {
        printf ("Key must be 26 letters\n");
        return 1;
    }

    string plain = get_string ("plaintext:  ");
    string cipher = substitute (plain, argv[1]);
    printf ("ciphertext: %s\n", cipher);
    return 0;
}

bool only_letters (string key)
{
    for (int i = 0, n = strlen (key); i < n; i++)
    {
        if (isalpha (key [i]) == false)
        {
            return true;
        }
        for (int j = 0; j < i; j++)
        {
            if (key [i] == key [j])
            {
                return true;
            }
        }
    }
    return false;
}

string substitute (string plain, string key)
{
    string cipher = plain;
    for (int i = 0, n = strlen (plain); i < n; i++)
    {
        if (isalpha (plain [i]))
        {
            bool up_low = isupper (plain [i]);
            char offset = up_low ? 'A' : 'a';
            cipher [i] = key [plain [i] - offset];
            cipher [i] = up_low ? toupper (cipher [i]) : tolower (cipher [i]);
        }
    }
    return cipher;
}
