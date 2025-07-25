#ifndef IMAGEM_PPM_H
#define IMAGEM_PPM_H

char header[3];
int width, height, maxval;

unsigned char *converter_rotacao(unsigned char *pixel);

void converter_cinza(unsigned char *pixel);
void converter_negativo(unsigned char *pixel);

#endif