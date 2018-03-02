#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize nfactor infile outfile\n");
        return 1;
    }
    int n = atoi(argv[1]);
    if (n < 1 || n > 100)
    {
        fprintf(stderr, "n should be in range [1..100]\n");
        return 1;
    }
    FILE* in = fopen(argv[2], "r");
    if (in == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[2]);
        return 1;
    }
    FILE* out = fopen(argv[3], "w");
    if (out == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[3]);
        return 1;
    }
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, in);
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, in);
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(out);
        fclose(in);
        fprintf(stderr, "Unsupported file format.\n");
        return 1;
    }
    BITMAPFILEHEADER out_bf = bf;
    BITMAPINFOHEADER out_bi = bi;
    int in_padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    out_bi.biWidth = bi.biWidth * n;
    out_bi.biHeight = bi.biHeight * n;
    int padding = (4 - (out_bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    out_bi.biSizeImage = (sizeof(RGBTRIPLE) * out_bi.biWidth + padding) * abs(out_bi.biHeight);
    out_bf.bfSize = out_bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    fwrite(&out_bf, sizeof(BITMAPFILEHEADER), 1, out);
    fwrite(&out_bi, sizeof(BITMAPINFOHEADER), 1, out);

    for (int i = 0; i < abs(bi.biHeight); i++)
    {
        for (int vert = 0; vert < n; vert++)
        {
            for (int j = 0; j < bi.biWidth; j++)
            {
                RGBTRIPLE triple;
                fread(&triple, sizeof(RGBTRIPLE), 1, in);
                for (int hor = 0; hor < n; hor++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, out);
                }
            }
            fseek(in, in_padding, SEEK_CUR);
            for (int k = 0; k < padding; k++)
            {
                fputc(0x00, out);
            }
            if (vert != n - 1) {
                fseek(in, -(bi.biWidth * 3 + in_padding), SEEK_CUR);
            }
        }
    }
    fclose(out);
    fclose(in);

    return 0;
}