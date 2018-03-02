#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

int counter = 0;

int is_jpeg(uint8_t block[BLOCK_SIZE])
{
    if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0)
    {
        return 1;
    }
    return 0;
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./copy image\n");
        return 1;
    }
    char *rawfile = argv[1];
    FILE *in = fopen(rawfile, "r");
    if (in == NULL)
    {
        fprintf(stderr, "Cannot open file %s\n", rawfile);
        return 2;
    }
    FILE *out;
    uint8_t buffer[BLOCK_SIZE];
    while (fread(&buffer, BLOCK_SIZE, 1, in) > 0)
    {
        if (is_jpeg(buffer))
        {
            char file[8];
            sprintf(file, "%03d.jpg", counter++);
            if (out != NULL)
            {
                fclose(out);
            }
            out = fopen(file, "w");
            fwrite(&buffer, BLOCK_SIZE, 1, out);
        }
        else
        {
            if (out != NULL)
            {
                fwrite(&buffer, BLOCK_SIZE, 1, out);
            }
        }
    }

    fclose(in);

    return 0;
}