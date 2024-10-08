#include <stdio.h>
#include "cs50.h"

int other_digit (long long a);
int digit (long long a);
int count (long long a);

int main (void)
{
    long long credit = get_long_long ("Number: ");
    int sum = other_digit (credit);
    sum += digit (credit);
    if (sum % 10 != 0)
    {
        printf ("INVALID\n");
    }
    else
    {
        int counter = count (credit);
        if (counter == 15)
        {
            if (credit / 10000000000000 == 34 || credit / 10000000000000 == 37)
            {
                printf ("AMEX\n");
            }
            else
            {
                printf ("INVALID\n");
            }
        }
        else if (counter == 13)
        {
            if (credit / 1000000000000 == 4)
            {
                printf ("VISA\n");
            }
            else
            {
                printf ("INVALID\n");
            }
        }
        else if (counter == 16)
        {
            if (credit / 1000000000000000 == 4)
            {
                printf ("VISA\n");
            }
            else if (credit / 100000000000000 == 51 || credit / 100000000000000 == 52 || credit / 100000000000000 == 53 || credit / 100000000000000 == 54 || credit / 100000000000000 == 55)
            {
                printf ("MASTERCARD\n");
            }
            else
            {
                printf ("INVALID\n");
            }
        }
        else
        {
            printf ("INVALID\n");
        }
    }
}

int other_digit (long long a)
{
    int sum = 0;
    while (a)
    {
        a /= 10;
        int n = (a % 10) * 2;
        for (int i = 0; i < 2; i++)
        {
            sum += n % 10;
            n /= 10;
        }
        a /= 10;
    }
    return sum;
}

int digit (long long a)
{
    int sum = 0;
    while (a)
    {
        sum += a % 10;
        for (int i = 0; i < 2; i++)
        {
            a /= 10;
        }
    }
    return sum;
}

int count (long long a)
{
    int counter = 0;
    while (a)
    {
        counter++;
        a /= 10;
    }
    return counter;
}