#include <stdio.h>
#include "imagem_ppm.h"


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
        //Cinza
        //converter_cinza(&pixel[i * 3]);

        //Negativo
        //converter_negativo(&pixel[i * 3]);
    }
    unsigned char *rotacionada = converter_rotacao(pixel);
    if (!rotacionada)
    {
        printf("Erro na rotacionada");
        return 1;
    }

    fprintf(fp_out, "P6\n%d %d\n%d\n", width, height, maxval);

    // escrita
    fwrite(pixel, 3, width * height, fp_out);

    // limpeza de dados
    free(pixel);
    free(rotacionada);
    fclose(fp_in);
    fclose(fp_out);

    // confirmacao
    printf("pixel salva como saida.ppm\n");
    return 0;
}
