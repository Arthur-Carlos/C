#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char pixel[3];
char header[3];
int width, height, maxval;

void converter_cinza(unsigned char *pixel)
{
    unsigned char cinza = (unsigned char)(0.3 * pixel[0] + 0.59 * pixel[1] + 0.11 * pixel[2]);
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

    fprintf(fp_out, "P6\n%d %d\n%d\n", width, height, maxval);

    int total_pixels = width * height;
    for (int i = 0; i < total_pixels; i++)
    {
        fread(pixel, 1, 3, fp_in);

        // Negativa
        //converter_negativo(pixel);
        // Cinza
        //converter_cinza(pixel);
        
        fwrite(pixel, 1, 3, fp_out);
    }

    fclose(fp_in);
    fclose(fp_out);
    printf("Imagem negativa salva como saida.ppm\n");

    return 0;
}
