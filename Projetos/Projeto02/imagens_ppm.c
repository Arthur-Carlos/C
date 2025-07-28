#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imagens_ppm.h"

ImagemPPM *verificaImagem(const char *caminho)
{
    FILE *arquivo = fopen(caminho, "rb");
    if (!arquivo)
    {
        perror("Erro ao abrir os arquivos.\n");
        return NULL;
    }

    char tipo[3];
    if (fscanf(arquivo, "%2s", tipo) != 1 || strcmp(tipo, "P6") != 0)
    {
        fprintf(stderr, "Formato PPM nao suportado\n");
        fclose(arquivo);
        return NULL;
    }

    int largura, altura, maxval;
    int c;
    do
    {
        c = fgetc(arquivo);
    } while (c == '\n' || c == ' ' || c == '\r' || c == '\t');
    ungetc(c, arquivo);

    while ((c = fgetc(arquivo)) == '#')
    {
        while ((c = fgetc(arquivo)) != '\n')
            ;
    }
    ungetc(c, arquivo);

    if (fscanf(arquivo, "%d %d %d", &largura, &altura, &maxval) != 3)
    {
        fprintf(stderr, "Erro ao ler cabecalho da imagem.\n");
        fclose(arquivo);
        return NULL;
    }

    if (maxval != 255)
    {
        fprintf(stderr, "Erro no maxval.\n");
        fclose(arquivo);
        return NULL;
    }

    fgetc(arquivo);

    ImagemPPM *img = malloc(sizeof(ImagemPPM));
    img->largura = largura;
    img->altura = altura;
    img->maxval = maxval;

    img->dados = malloc(altura * sizeof(Pixel *));
    for (int i = 0; i < altura; i++)
    {
        img->dados[i] = malloc(largura * sizeof(Pixel));
        fread(img->dados[i], sizeof(Pixel), largura, arquivo);
    }

    fclose(arquivo);
    return img;
}

void liberarImagem(ImagemPPM *img)
{
    if (!img)
        return;
    for (int i = 0; i < img->altura; i++)
    {
        free(img->dados[i]);
    }
    free(img->dados);
    free(img);
}

void salvarImagem(const char *caminho, ImagemPPM *img)
{
    FILE *arquivo = fopen(caminho, "wb");
    if (!arquivo)
    {
        perror("Erro ao salvar imagem\n");
        return;
    }

    fprintf(arquivo, "P6\n%d %d\n%d\n", img->largura, img->altura, img->maxval);

    for (int i = 0; i < img->altura; i++)
    {
        fwrite(img->dados[i], sizeof(Pixel), img->largura, arquivo);
    }

    fclose(arquivo);
}

ImagemPPM *converter_dimensao(ImagemPPM *img, const char *tipo, int fator)
{
    if (fator < 1 || fator > 4)
    {
        fprintf(stderr, "Erro, entrada nao esta entre 1 e 4.\n");
        return NULL;
    }

    int nova_largura, nova_altura;

    if (strcmp(tipo, "amp") == 0)
    {
        nova_largura = img->largura * fator;
        nova_altura = img->altura * fator;
    }
    else if (strcmp(tipo, "red") == 0)
    {
        nova_largura = img->largura / fator;
        nova_altura = img->altura / fator;
    }
    else
    {
        fprintf(stderr, "Erro.\n");
        return NULL;
    }

    ImagemPPM *nova = malloc(sizeof(ImagemPPM));
    nova->largura = nova_largura;
    nova->altura = nova_altura;
    nova->maxval = 255;
    nova->dados = malloc(nova->altura * sizeof(Pixel *));

    for (int i = 0; i < nova->altura; i++)
    {
        nova->dados[i] = malloc(nova->largura * sizeof(Pixel));
    }

    if (strcmp(tipo, "amp") == 0)
    {
        for (int i = 0; i < img->altura; i++)
        {
            for (int j = 0; j < img->largura; j++)
            {
                Pixel p = img->dados[i][j];
                for (int dy = 0; dy < fator; dy++)
                {
                    for (int dx = 0; dx < fator; dx++)
                    {
                        nova->dados[i * fator + dy][j * fator + dx] = p;
                    }
                }
            }
        }
    }
    else if (strcmp(tipo, "red") == 0)
    {
        for (int i = 0; i < nova->altura; i++)
        {
            for (int j = 0; j < nova->largura; j++)
            {
                nova->dados[i][j] = img->dados[i * fator][j * fator];
            }
        }
    }

    return nova;
}

ImagemPPM *converter_rotacao(ImagemPPM *img, int angulo)
{
    if (angulo != 90 && angulo != 180 && angulo != 270)
    {
        fprintf(stderr, "Angulo errado.\n");
        return NULL;
    }

    int nova_largura = (angulo == 180) ? img->largura : img->altura;
    int nova_altura = (angulo == 180) ? img->altura : img->largura;

    ImagemPPM *nova = malloc(sizeof(ImagemPPM));
    nova->largura = nova_largura;
    nova->altura = nova_altura;
    nova->maxval = img->maxval;
    nova->dados = malloc(nova->altura * sizeof(Pixel *));
    for (int i = 0; i < nova->altura; i++)
    {
        nova->dados[i] = malloc(nova->largura * sizeof(Pixel));
    }

    for (int i = 0; i < img->altura; i++)
    {
        for (int j = 0; j < img->largura; j++)
        {
            Pixel p = img->dados[i][j];

            if (angulo == 90)
            {
                nova->dados[j][img->altura - 1 - i] = p;
            }
            else if (angulo == 180)
            {
                nova->dados[img->altura - 1 - i][img->largura - 1 - j] = p;
            }
            else if (angulo == 270)
            {
                nova->dados[img->largura - 1 - j][i] = p;
            }
        }
    }

    return nova;
}

ImagemPPM *converter_cinza(ImagemPPM *img)
{
    ImagemPPM *nova = malloc(sizeof(ImagemPPM));
    nova->largura = img->largura;
    nova->altura = img->altura;
    nova->maxval = img->maxval;

    nova->dados = malloc(nova->altura * sizeof(Pixel *));
    for (int i = 0; i < nova->altura; i++)
    {
        nova->dados[i] = malloc(nova->largura * sizeof(Pixel));
    }

    for (int i = 0; i < img->altura; i++)
    {
        for (int j = 0; j < img->largura; j++)
        {
            Pixel p = img->dados[i][j];
            int aux = (p.r * 0.21 + p.g * 0.71 + p.b * 0.02);
            Pixel cinza = {aux, aux, aux};
            nova->dados[i][j] = cinza;
        }
    }

    return nova;
}

ImagemPPM *converter_negativo(ImagemPPM *img)
{
    ImagemPPM *nova = malloc(sizeof(ImagemPPM));
    nova->largura = img->largura;
    nova->altura = img->altura;
    nova->maxval = img->maxval;

    nova->dados = malloc(nova->altura * sizeof(Pixel *));
    for (int i = 0; i < nova->altura; i++)
    {
        nova->dados[i] = malloc(nova->largura * sizeof(Pixel));
    }

    for (int i = 0; i < img->altura; i++)
    {
        for (int j = 0; j < img->largura; j++)
        {
            Pixel p = img->dados[i][j];
            Pixel aux;
            aux.r = 255 - p.r;
            aux.g = 255 - p.g;
            aux.b = 255 - p.b;
            nova->dados[i][j] = aux;
        }
    }

    return nova;
}
