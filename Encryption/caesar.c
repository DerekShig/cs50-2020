#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int caesar();

int main(int argc, string argv[])
{
    int counter = 0;
    if (argc == 2)
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isdigit(argv[1][i]) == 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
            else
            {
                counter++;
            }
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (counter == strlen(argv[1]))
    {
        int key = atoi(argv[1]);
        caesar(key);
    }
    return 0;
}

int caesar(int x)
{

    string text = get_string("plaintext: ");

    for (int j = 0; j < strlen(text); j++)
    {
        if (text[j] >= 'a' && text[j] <= 'z')
        {
            int c = (((int)text[j] + x) - 97) % 26;
            text[j] = (char) c + 97;
        }
        else if (text[j] >= 'A' && text[j] <= 'Z')
        {
            int c = (((int)text[j] + x) - 65) % 26;
            text[j] = (char) c + 65;
        }
        else
        {
            text[j] = text[j];
        }

    }

    printf("ciphertext: %s\n", text);

    return 0;
}