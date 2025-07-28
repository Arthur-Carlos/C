#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "imagens_ppm.h"

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        fprintf(stderr, "Uso: %s <entrada.ppm> <comando> [param] <saida.ppm>\n", argv[0]);
        return 1;
    }

    ImagemPPM *fp_in = carregarImagem(argv[1]);
    if (!fp_in)
    {
        fprintf(stderr, "Erro ao abrir os aquivos.\n");
        return 1;
    }

    ImagemPPM *entrada = NULL;

    if (strcmp(argv[2], "rot") == 0 && argc == 5)
    {
        int angulo = atoi(argv[3]);
        entrada = converter_rotacao(fp_in, angulo);
    }
    else if ((strcmp(argv[2], "amp") == 0 || strcmp(argv[2], "red") == 0) && argc == 5)
    {
        int fator = atoi(argv[3]);
        entrada = converter_dimensao(fp_in, argv[2], fator);
    }
    else if (strcmp(argv[2], "cinza") == 0 && argc == 4)
    {
        entrada = converter_cinza(fp_in);
    }
    else if (strcmp(argv[2], "inverte") == 0 && argc == 4)
    {
        entrada = converter_negativo(fp_in);
    }
    else
    {
        fprintf(stderr, "Entrada errada.\n");
        liberarImagem(fp_in);
        return 1;
    } 

    if (entrada)
    {
        salvarImagem(argv[argc - 1], entrada);
        liberarImagem(entrada);
    }

    liberarImagem(fp_in);
    return 0;
}
