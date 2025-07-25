#include <stdlib.h>
#include <string.h>
#include "imagem_ppm.h"

unsigned char *converter_rotacao(unsigned char *pixel)
{
    unsigned char *rotacionada = malloc(3 * width * height);
    if (!rotacionada)
    {
        printf("Erro de memória!\n");
        exit(1);
    }

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int old_index = (y * width + x) * 3;
            int new_x = height - 1 - y;
            int new_y = x;
            int new_index = (new_y * height + new_x) * 3;

            rotacionada[new_index] = pixel[old_index];
            rotacionada[new_index + 1] = pixel[old_index + 1];
            rotacionada[new_index + 2] = pixel[old_index + 2];
        }
    }

    int temp = width;
    width = height;
    height = temp;

    return rotacionada;
}

void converter_cinza(unsigned char *pixel)
{
    unsigned char cinza = (unsigned char)(0.21 * pixel[0] + 0.71 * pixel[1] + 0.02 * pixel[2]);
    pixel[0] = pixel[1] = pixel[2] = cinza;
}

void converter_negativo(unsigned char *pixel)
{
    pixel[0] = maxval - pixel[0];
    pixel[1] = maxval - pixel[1];
    pixel[2] = maxval - pixel[2];
}