#include <stdio.h>
#include <math.h>
#define TAM 20

int main()
{
    char string[TAM], charmaior;
    int contagem[256] = {0}, maior = 0;
    for (int i = 0; i < TAM; i++)
    {
        scanf(" %c", &string[i]);
        contagem[string[i]]++;
    }
    for (int i = 0; i < 256; i++)
    {
        if (contagem[i] > maior)
        {
            maior = contagem[i];
            charmaior = (char)i;
        }
        
    }
    printf("%c %d", charmaior, maior);
    return 0;
}
