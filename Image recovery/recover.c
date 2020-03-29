#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>


int main(int argc, char *argv[])
{
    if (argc == 2 && strcmp(argv[1], "card.raw") == 0)
    {

        FILE *f = fopen(argv[1], "r");

        int file_count = 0;
        char file_name[8];
        FILE *img;
        unsigned char temp[512];

        while (fread(temp, sizeof(temp), 1, f) == 1)
        {
            if (temp[0] == 0xff && temp[1] == 0xd8 && temp[2] == 0xff && (temp[3] & 0xf0) == 0xe0)
            {
                if (file_count > 0)
                {
                    fclose(img);
                    sprintf(file_name, "%03i.jpg", file_count);
                    file_count++;
                    img = fopen(file_name, "w");
                    fwrite(temp, 512, 1, img);
                }
                if (file_count == 0)
                {
                    sprintf(file_name, "%03i.jpg", file_count);
                    file_count++;
                    img = fopen(file_name, "w");
                    fwrite(temp, 512, 1, img);
                }
            }
            else if (file_count > 0)
            {
                fwrite(temp, 512, 1, img);
            }
        }

        fclose(img);
        fclose(f);
        return 0;

    }
    else
    {
        printf("Usage: ./recover image");
        return 1;
    }
}