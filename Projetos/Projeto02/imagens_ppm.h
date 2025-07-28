#ifndef IMAGENS_PPM_H
#define IMAGENS_PPM_H

typedef struct
{
    unsigned char r, g, b;
} Pixel;

typedef struct
{
    int largura;
    int altura;
    int maxval;
    Pixel **dados;
} ImagemPPM;

ImagemPPM *carregarImagem(const char *caminho);
void liberarImagem(ImagemPPM *img);
void salvarImagem(const char *caminho, ImagemPPM *img);

ImagemPPM *converter_dimensao(ImagemPPM *img, const char *tipo, int fator);
ImagemPPM *converter_rotacao(ImagemPPM *img, int angulo);
ImagemPPM *converter_cinza(ImagemPPM *img);
ImagemPPM *converter_negativo(ImagemPPM *img);

#endif
