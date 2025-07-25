#include <stdio.h>
#include "string.h"

void teste(int r, int g, int b)
{
    printf("\x1b[38;2;%d;%d;%dm█", r, g, b);//obs só funfa no linux
}

int main(void)
{
    int i, j, x, y, z;

    FILE *fp = fopen("entrada.ppm", "rb");
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char header[3];
    int width, height, maxval;

    fscanf(fp, "%2s", header);
    if (strcmp(header, "P6") != 0)
    {
        printf("Formato PPM não suportado.\n");
        fclose(fp);
        return 1;
    }
    fscanf(fp, "%d %d %d", &width, &height, &maxval);
    fgetc(fp);

    unsigned char pixel[3];
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            fread(pixel, 1, 3, fp);
            /*
            x = 255-pixel[0]; negativa
            y = 255-pixel[1];
            z = 255-pixel[2];
             */
            x = pixel[0];
            y = pixel[1];
            z = pixel[2];
            teste(x, y, z);
            teste(x, y, z);
        }
        printf("\n");
    }
    fclose(fp);
    return 0;
}