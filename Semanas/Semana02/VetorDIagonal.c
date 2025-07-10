#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 4

int main()
{
    int vetor[TAM][TAM];
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            scanf("%d", &vetor[i][j]);
        }
    }
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (i == j)
            {
                printf("%d ", vetor[i][j]);
            }
            
        }
    }
    printf("\n");
    return 0;
}
