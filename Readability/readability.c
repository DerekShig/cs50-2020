#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int main(void)
{

    float words = 1;
    float letters = 0;
    float sentences = 0;
    float L = 0.00;
    float S = 0.00;
    float index = 0.00;

    string text = get_string("Text: ");

    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }
        if (text[i] == '.' ||  text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
        if (text[i] == ' ')
        {
            words++;
        }
    }

    L = ((letters * 100) / (words * 100)) * 100;
    S = ((sentences * 100) / (words * 100)) * 100;
    index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Grade Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", index);
    }

}