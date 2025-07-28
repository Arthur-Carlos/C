#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char header[3];
int width, height, maxval;

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

int main(void)
{
    FILE *fp_in = fopen("entrada.ppm", "rb");
    FILE *fp_out = fopen("saida.ppm", "wb");

    if (fp_in == NULL || fp_out == NULL)
    {
        printf("Erro ao abrir os arquivos.\n");
        return 1;
    }

    fscanf(fp_in, "%2s", header);
    if (strcmp(header, "P6") != 0)
    {
        printf("Formato PPM não suportado.\n");
        fclose(fp_in);
        fclose(fp_out);
        return 1;
    }

    fscanf(fp_in, "%d %d %d", &width, &height, &maxval);
    fgetc(fp_in);

    int total_pixels = width * height;
    unsigned char *pixel = malloc(3 * total_pixels);
    if (!pixel)
    {
        printf("Erro no pixel");
        return 1;
    }

    fread(pixel, 3, total_pixels, fp_in);
    // leitura

    for (int i = 0; i < total_pixels; i++)
    {
        // Cinza
        // converter_cinza(&pixel[i * 3]);

        // Negativo
        //converter_negativo(&pixel[i * 3]);

    }
    unsigned char *rotacionada = converter_rotacao(pixel);
    if (!rotacionada)
    {
        printf("Erro na rotacionada");
        return 1;
    }
    //titulo
    fprintf(fp_out, "P6\n%d %d\n%d\n", width, height, maxval);

    // escrita
    fwrite(rotacionada, 3, width * height, fp_out);

    // limpeza de dados
    free(pixel);
    free(rotacionada);
    fclose(fp_in);
    fclose(fp_out);

    // confirmacao
    printf("pixel salva como saida.ppm\n");
    return 0;
}
